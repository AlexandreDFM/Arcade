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
        this->gameDll = new DLLoader("./lib/arcade_menu.so");
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
            else if (strncmp(string, "game", 4) == 0) _games.push_back(entry.path());
            else std::cout << "Error: " << entry.path() << " is not a valid library" << std::endl;
        }
    }

    Core::Core(std::string lib, std::string game)
    {
        this->graphicDll = new DLLoader(lib);
        this->setGraphic(this->graphicDll->getFunction<IDisplay>("entryPoint"));
        this->gameDll = new DLLoader(game);
        this->setGame(this->gameDll->getFunction<IGame>("entryPoint"));
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
            this->setChangeGame(eventKey);
            this->MenuGetChange();
            if (!this->game->isRunning()) break;
            this->graphic->update();
            this->graphic->clear();
        }
        this->graphic->close();
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
        if (tmp.game_path == "" || tmp.lib_path == "") {
            return;
        } else {
            if (!std::filesystem::exists(tmp.game_path)) {
                std::cout << "Error: " << tmp.game_path << " is not a valid path" << std::endl; return;
            } else if (!std::filesystem::exists(tmp.lib_path)) {
                std::cout << "Error: " << tmp.lib_path << " is not a valid path" << std::endl; return;
            }
            this->_menuInfo = tmp;
            this->game->setMenuInfo((MenuInfo) {"", "", ""});
            this->changeLib(this->_menuInfo.lib_path);
            std::cout << "After game: " << this->_menuInfo.game_path << std::endl;
            std::cout << "After lib: " << this->_menuInfo.lib_path << std::endl;
//            this->changeGame(this->_menuInfo.game_path);
        }
    }
    void Core::changeLib(std::string lib)
    {
        std::cout << "Change lib: " << lib << std::endl;
        std::cout << "Index: " << this->_indexLib << std::endl;
        this->graphic->close();
        this->graphicDll->~DLLoader();
        this->graphicDll = new DLLoader(lib);
        this->setGraphic(this->graphicDll->getFunction<IDisplay>("entryPoint"));
        this->graphic->init(this->game->getAssets());
    }

    void Core::changeGame(std::string game)
    {
        std::cout << "Change game: " << game << std::endl;
        this->game->close();
        this->gameDll->~DLLoader();
        this->gameDll = new DLLoader(game);
        this->setGame(this->gameDll->getFunction<IGame>("entryPoint"));
        this->game->init();
        this->graphic->close();
        this->graphic->init(this->game->getAssets());
    }
}
