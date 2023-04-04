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
        std::cout << "DisplayModuleA created" << std::endl;
    }

    ADisplay::~ADisplay()
    {
        std::cout << "DisplayModuleA destroyed" << std::endl;
    }

    void ADisplay::init(const std::map<char, std::string>& gameAssets)
    {
        (void) gameAssets;
        std::cout << "DisplayModuleA initialized" << std::endl;
    }

    void ADisplay::update()
    {
        std::cout << "DisplayModuleA updated" << std::endl;
    }

    void ADisplay::clear()
    {
        std::cout << "DisplayModuleA cleared" << std::endl;
    }

    void ADisplay::close()
    {
        std::cout << "DisplayModuleA initialized" << std::endl;
    }

    void ADisplay::display(std::vector<Drawable> drawables)
    {
        (void) drawables;
        std::cout << "DisplayModuleA display" << std::endl;
    }

    void ADisplay::display(std::vector<DrawableText> drawables)
    {
        (void) drawables;
        std::cout << "DisplayModuleA display" << std::endl;
    }

    Arcade::EventType ADisplay::getEvent()
    {
        std::cout << "DisplayModuleA getEvent" << std::endl;
        return Arcade::EventType::NOTHING;
    }
}
