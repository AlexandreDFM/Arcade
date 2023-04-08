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

    Core::~Core()
    {
    }

    Core::Core(std::string lib)
    {
        this->_indexLib = 0;
        this->_indexGame = 0;
        this->graphicDll = new DLLoader(lib);
        char *str = this->graphicDll->getFunction<char>("getType");
        if (str == nullptr) {
            std::cout << "Error: " << lib << " is not a valid library" << std::endl; exit(84);
        } else if (strncmp(str, "lib", 3) != 0) {
            std::cout << "Error: " << lib << " is not a valid library" << std::endl; exit(84);
        }
        this->setGraphic(this->graphicDll->getFunction<IDisplay>("entryPoint"));
        if (!std::filesystem::exists("./lib/arcade_menu.so")) {
            std::cout << "Error: ./lib/arcade_menu.so does not exist" << std::endl; exit(84);
        }
        this->gameDll = new DLLoader("./lib/arcade_menu.so");
        this->setGame(this->gameDll->getFunction<IGame>("entryPoint"));
        std::string path = "./lib";
        for (const auto & entry : std::filesystem::directory_iterator(path)) {
            if (entry.path().extension() != ".so") {
                std::cout << "Error: " << entry.path() << " is not a library" << std::endl; continue;
            }
            DLLoader *loader = new DLLoader(entry.path());
            char *string = loader->getFunction<char>("getType");
            if (string == nullptr) {
                std::cout << "Error: " << entry.path() << " is not a valid library" << std::endl;
                delete loader; continue;
            }
            if (strncmp(string, "lib", 3) == 0) _libs.push_back(entry.path());
            else if (strncmp(string, "game", 4) == 0) _games.push_back(entry.path());
            else std::cout << "Error: " << entry.path() << " is not a valid library" << std::endl;
//            delete loader;
        }
    }

    Core::Core(std::string lib, std::string game)
    {
        this->graphicDll = new DLLoader(lib);
        this->setGraphic(this->graphicDll->getFunction<IDisplay>("entryPoint"));
        this->gameDll = new DLLoader(game);
        this->setGame(this->gameDll->getFunction<IGame>("entryPoint"));
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
//            static auto start = std::chrono::high_resolution_clock::now();
//            auto end = std::chrono::high_resolution_clock::now();
//            if (std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() <= 100) continue;
//            else start = std::chrono::high_resolution_clock::now();
            Arcade::EventType eventKey = this->graphic->getEvent();
            if (eventKey == EventType::MENU) this->setMenu();
            this->game->update(eventKey);
            this->setChangeLib(eventKey);
            this->setChangeGame(eventKey);
            this->MenuGetChange();
            if (!this->game->isRunning()) break;
            this->graphic->update();
            this->graphic->clear();
        }
        this->graphic->close();
    }

    void Core::setMenu()
    {
        if (!std::filesystem::exists("./lib/arcade_menu.so")) {
            std::cout << "Error: ./lib/arcade_menu.so does not exist" << std::endl; return;
        }
        this->game->close();
        this->graphic->close();
        this->gameDll = new DLLoader("./lib/arcade_menu.so");
        this->setGame(this->gameDll->getFunction<IGame>("entryPoint"));
        this->game->init();
        this->graphic->init(this->game->getAssets());
        this->graphic->display(this->game->getDrawable());
        this->graphic->display(this->game->getDrawableText());
        this->graphic->update();
        this->graphic->clear();
    }

    void Core::setChangeLib(EventType event)
    {
        if (event == EventType::LIBNEXT) {
            if (this->_indexLib == this->_libs.size() - 1) this->_indexLib = 0;
            else this->_indexLib++;
            this->changeLib(this->_libs[this->_indexLib]);
        } else if (event == EventType::LIBPREV) {
            if (this->_indexLib == 0) this->_indexLib = this->_libs.size() - 1;
            else this->_indexLib--;
            this->changeLib(this->_libs[this->_indexLib]);
        }
    }

    void Core::setChangeGame(EventType event)
    {
        if (event == EventType::GAMENEXT) {
            if (this->_indexGame == this->_games.size() - 1) this->_indexGame = 0;
            else this->_indexGame++;
            this->changeGame(this->_games[this->_indexGame]);
        } else if (event == EventType::GAMEPREV) {
            if (this->_indexGame == 0) this->_indexGame = this->_games.size() - 1;
            else this->_indexGame--;
            this->changeGame(this->_games[this->_indexGame]);
        }
    }

    void Core::MenuGetChange()
    {
        MenuInfo tmp = this->game->getMenuInfo();
        if (tmp.gamePath == "" || tmp.libPath == "") {
            return;
        } else {
            if (!std::filesystem::exists(tmp.gamePath)) {
                std::cout << "Error: " << tmp.gamePath << " is not a valid path" << std::endl; return;
            } else if (!std::filesystem::exists(tmp.libPath)) {
                std::cout << "Error: " << tmp.libPath << " is not a valid path" << std::endl; return;
            }
            this->_menuInfo = tmp;
            this->changeLib(this->_menuInfo.libPath);
            this->changeGame(this->_menuInfo.gamePath);
        }
    }

    void Core::changeLib(std::string lib)
    {
        this->graphic->close();
        this->graphicDll->~DLLoader();
        this->graphicDll = new DLLoader(lib);
        this->setGraphic(this->graphicDll->getFunction<IDisplay>("entryPoint"));
        this->graphic->init(this->game->getAssets());
    }

    void Core::changeGame(std::string game)
    {
        this->game->close();
        this->gameDll->~DLLoader();
        this->gameDll = new DLLoader(game);
        this->setGame(this->gameDll->getFunction<IGame>("entryPoint"));
        this->game->setMenuInfo({this->_menuInfo.username, "", "" });
        this->game->init();
        this->graphic->close();
        this->graphic->init(this->game->getAssets());
    }
}
