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
        return false;
    }

    const std::vector<Drawable> &getDrawable()
    {
        return std::vector<Drawable>();
    }

    const std::map<char, std::string> &getAssets()
    {
        return std::map<char, std::string>();
    }

    const std::vector<DrawableText> &getDrawableText()
    {
        return std::vector<DrawableText>();
    }

    void AGame::setIsRunning()
    {
    }
}
