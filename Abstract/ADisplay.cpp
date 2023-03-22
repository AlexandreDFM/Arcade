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

    void ADisplay::stop()
    {
        std::cout << "DisplayModuleA stopped" << std::endl;
    }

    void ADisplay::createText()
    {
        std::cout << "DisplayModuleA createText" << std::endl;
    }

    void ADisplay::createSprite()
    {
        std::cout << "DisplayModuleA createSprite" << std::endl;
    }

    int ADisplay::getEvent()
    {
        std::cout << "DisplayModuleA getEvent" << std::endl;
        return 0;
    }

    bool ADisplay::getIsRunning() const
    {
        return this->_isRunning;
    }

    void ADisplay::setIsRunning(bool isRunning)
    {
        this->_isRunning = isRunning;
    }

    void ADisplay::drawSprite(void *spt)
    {
        std::cout << "DisplayModuleA drawSprite" << std::endl;
    }

    void ADisplay::drawBackground(void *bkg)
    {
        std::cout << "DisplayModuleA drawBackground" << std::endl;
    }

    void ADisplay::drawText(std::string text, int x, int y)
    {
        std::cout << "DisplayModuleA drawText" << std::endl;
    }
}
