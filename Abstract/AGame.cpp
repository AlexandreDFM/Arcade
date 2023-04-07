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
        (void) event;
    }

    void AGame::close()
    {
    }

    bool AGame::isRunning() const
    {
        return _isRunning;
    }

    const std::vector<Drawable> &AGame::getDrawable() const
    {
        return _drawable;
    }

    const std::map<char, std::string> &AGame::getAssets() const
    {
        return _assets;
    }

    const std::vector<DrawableText> &AGame::getDrawableText() const
    {
        return _drawableText;
    }

    void AGame::setIsRunning(bool isRunning)
    {
        _isRunning = isRunning;
    }

    const MenuInfo AGame::getMenuInfo(Arcade::EventType event)
    {
        (void) event;
        return MenuInfo {0, 0};
    }
}
