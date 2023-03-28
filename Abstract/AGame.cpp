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
    }

    void AGame::init()
    {
    }

    void AGame::update()
    {
    }

    void AGame::close()
    {
    }

    int AGame::handleEvent(int event)
    {
        return 0;
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

    void AGame::setIsRunning()
    {
    }
}
