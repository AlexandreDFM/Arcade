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
        this->graphicDll = new DLLoader(lib);
        this->setGraphic(this->graphicDll->getFunction<IDisplay>("entryPoint"));
        this->gameDll = new DLLoader("./lib/arcade_nibbler.so");
        this->setGame(this->gameDll->getFunction<IGame>("entryPoint"));
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
           Arcade::EventType eventkey = this->graphic->getEvent();
           this->game->update(eventkey);
           this->setChangeLib(eventkey);
           if (!this->game->isRunning()) break;
           this->graphic->update();
           this->graphic->clear();
        }
        this->graphic->close();
    }

    void Core::setChangeLib(EventType event)
    {
        if (event == EventType::LIBNEXT)
            this->changeLib("./lib/arcade_sfml.so");
        else if (event == EventType::LIBPREV)
            this->changeLib("./lib/arcade_ncurses.so");
    }

    void Core::changeLib(std::string lib)
    {
        std::cout << "NEXT" << std::endl;
        this->graphic->close();
        this->graphicDll->~DLLoader();
        this->graphicDll = new DLLoader(lib);
        this->setGraphic(this->graphicDll->getFunction<IDisplay>("entryPoint"));
        this->graphic->init(this->game->getAssets());
    }
}
