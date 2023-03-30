/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-arcade-roman.lopes
** File description:
** Core
*/

#include "Core.hpp"

namespace Arcade {
    Core::Core() {
    }

    Core::Core(std::string lib) {
        DLLoader Dll(lib);
        this->setGraphic(Dll.getFunction<IDisplay>("create"));
        DLLoader Game("./lib/menu.so");
        this->setGame(Game.getFunction<IGame>("create"));
    }

    Core::Core(std::string lib, std::string game) {
        DLLoader dll(lib);
        this->setGraphic(dll.getFunction<IDisplay>("create"));
        DLLoader dll2(game);
        this->setGame(dll2.getFunction<IGame>("create"));
    }

    Core::~Core() {
    }

    void Core::setGraphic(IDisplay *graphic) {
        this->graphic = graphic;
    }

    void Core::setGame(IGame *game) {
        this->game = game;
    }
}
