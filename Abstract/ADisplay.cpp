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
    }

    ADisplay::~ADisplay()
    {
    }

    void ADisplay::init(const std::map<char, std::string>& gameAssets)
    {
        (void) gameAssets;
    }

    void ADisplay::update()
    {
    }

    void ADisplay::clear()
    {
    }

    void ADisplay::close()
    {
    }

    void ADisplay::display(std::vector<Drawable> drawables)
    {
        (void) drawables;
    }

    void ADisplay::display(std::vector<DrawableText> drawables)
    {
        (void) drawables;
    }

    Arcade::EventType ADisplay::getEvent()
    {
        return Arcade::EventType::NOTHING;
    }
}
