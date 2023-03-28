/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-arcade-roman.lopes
** File description:
** ADisplay.cpp
*/

#include "ADisplay.hpp"

namespace Arcade {
    ADisplay::ADisplay()
    {
        this->_isRunning = true;
        std::cout << "DisplayModuleA created" << std::endl;
    }

    ADisplay::~ADisplay()
    {
        std::cout << "DisplayModuleA destroyed" << std::endl;
    }

    void ADisplay::init()
    {
        this->_isRunning = true;
        std::cout << "DisplayModuleA initialized" << std::endl;
    }

    void ADisplay::update()
    {
        std::cout << "DisplayModuleA updated" << std::endl;
    }

    void ADisplay::close()
    {
        this->_isRunning = false;
        std::cout << "DisplayModuleA initialized" << std::endl;
    }

    void ADisplay::display(std::vector<Drawable> drawables)
    {
        std::cout << "DisplayModuleA display" << std::endl;
    }

    void ADisplay::display(std::vector<DrawableText> drawables)
    {
        std::cout << "DisplayModuleA display" << std::endl;
    }

    int ADisplay::getEvent()
    {
        std::cout << "DisplayModuleA getEvent" << std::endl;
        return 0;
    }
}
