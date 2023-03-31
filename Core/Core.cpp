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
        DLLoader Dll(lib);
        this->setGraphic(Dll.getFunction<IDisplay>("entryPoint"));
        DLLoader Game("./lib/arcade_menu.so");
        this->setGame(Game.getFunction<IGame>("entryPoint"));
    }

    Core::Core(std::string lib, std::string game)
    {
        DLLoader dll("./lib/arcade_ncurses.so");
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
//        this->init();
        while (this->game->isRunning()) {
//            this->graphic->clear();
//            this->graphic->draw(this->game->getMap());
//            this->graphic->display();
//            this->game->update(this->graphic->getEvent());
        }
    }
}
