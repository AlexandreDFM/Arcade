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
        this->gameDll = new DLLoader("./lib/arcade_snake.so");
        this->setGame(this->gameDll->getFunction<IGame>("entryPoint"));
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
        this->game->init();
        this->graphic->init(this->game->getAssets());
        while (this->game->isRunning()) {
           this->graphic->display(this->game->getDrawable());
           this->graphic->display(this->game->getDrawableText());
           this->game->update(this->graphic->getEvent());
           if (!this->game->isRunning()) break;
           this->graphic->update();
           this->graphic->clear();
        }
        this->graphic->close();
    }
}
