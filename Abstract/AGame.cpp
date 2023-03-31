/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-arcade-roman.lopes
** File description:
** AGame.cpp
*/

#include "AGame.hpp"

namespace Arcade {
    AGame::AGame()
    {
        _isRunning = true;
        _event = Arcade::EventType::NOTHING;
    }

    void AGame::init()
    {
    }

    void AGame::update(Arcade::EventType event)
    {
    }

    void AGame::close()
    {
    }

    bool AGame::isRunning()
    {
        return _isRunning;
    }

    const std::vector<Drawable> &AGame::getDrawable()
    {
        return _drawable;
    }

    const std::map<char, std::string> &AGame::getAssets()
    {
        return _assets;
    }

    const std::vector<DrawableText> &AGame::getDrawableText()
    {
        return _drawableText;
    }

    Arcade::EventType AGame::getDirection()
    {
        return _event;
    }

    void AGame::setIsRunning(bool isRunning)
    {
        _isRunning = isRunning;
    }
}
