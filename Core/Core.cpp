/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-arcade-roman.lopes
** File description:
** Core
*/

#include "Core.hpp"

namespace Arcade {
    Core::Core()
    {
    }

    Core::Core(std::string lib)
    {
        this->_index = 1;
        this->graphicDll = new DLLoader(lib);
        this->setGraphic(this->graphicDll->getFunction<IDisplay>("entryPoint"));
        this->gameDll = new DLLoader("./lib/arcade_snake.so");
        this->setGame(this->gameDll->getFunction<IGame>("entryPoint"));
        std::string path = "./lib";
        for (const auto & entry : std::filesystem::directory_iterator(path)) {
            if (entry.path().extension() != ".so") {
                std::cout << "Error: " << entry.path() << " is not a library" << std::endl;
                continue;
            }
            DLLoader *loader = new DLLoader(entry.path());
            char *string = loader->getFunction<char>("getType");
            if (string == nullptr) {
                std::cout << "Error: " << entry.path() << " is not a valid library" << std::endl;
                delete loader; continue;
            }
            if (strncmp(string, "lib", 3) == 0) _libs.push_back(entry.path());
        }
    }

    Core::Core(std::string lib, std::string game)
    {
        DLLoader dll(lib);
        this->setGraphic(dll.getFunction<IDisplay>("entryPoint"));
        DLLoader dll2(game);
        this->setGame(dll2.getFunction<IGame>("entryPoint"));
    }

    Core::~Core()
    {
    }

    void Core::setGraphic(IDisplay *graphic)
    {
        this->graphic = graphic;
    }

    void Core::setGame(IGame *game)
    {
        this->game = game;
    }

    void Core::loop()
    {
        this->game->init();
        this->graphic->init(this->game->getAssets());
        while (this->game->isRunning()) {
           this->graphic->display(this->game->getDrawable());
           this->graphic->display(this->game->getDrawableText());
           Arcade::EventType eventKey = this->graphic->getEvent();
           this->game->update(eventKey);
           this->setChangeLib(eventKey);
           if (!this->game->isRunning()) break;
           this->graphic->update();
           this->graphic->clear();
        }
        this->graphic->close();
    }

    void Core::setChangeLib(EventType event)
    {
        if (event == EventType::LIBNEXT) {
            if (this->_index == this->_libs.size() - 1) this->_index = 0;
            else this->_index++;
            this->changeLib(this->_libs[this->_index]);
        } else if (event == EventType::LIBPREV) {
            if (this->_index == 0) this->_index = this->_libs.size() - 1;
            else this->_index--;
            this->changeLib(this->_libs[this->_index]);
        }
    }

    void Core::changeLib(std::string lib)
    {
        std::cout << "Change lib: " << lib << std::endl;
        std::cout << "Index: " << this->_index << std::endl;
        this->graphic->close();
        this->graphicDll->~DLLoader();
        this->graphicDll = new DLLoader(lib);
        this->setGraphic(this->graphicDll->getFunction<IDisplay>("entryPoint"));
        this->graphic->init(this->game->getAssets());
    }
}
