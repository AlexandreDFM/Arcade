/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-arcade-roman.lopes
** File description:
** Menu
*/

#include "Menu.hpp"

namespace Arcade {
    void Menu::init()
    {
        std::string path = "./lib";
        for (const auto & entry : std::filesystem::directory_iterator(path)) {
            if (entry.path() == "./lib/arcade_sfml.so" || entry.path() == "./lib/arcade_ncurses.so" || entry.path() == "./lib/arcade_opengl.so") {
                 _liblist.push_back(entry.path());
            } else {
                _gamelist.push_back(entry.path());
            }
        }
    }

    void Menu::update(Arcade::EventType event)
    {
        (void) event;
    }

    void Menu::close()
    {
    }

    bool Menu::isRunning()
    {
        return false;
    }

    const std::vector<Drawable> &Menu::getDrawable()
    {
        return _drawable;
    }

    const std::map<char, std::string> &Menu::getAssets()
    {
        return _assets;
    }

    const std::vector<DrawableText> &Menu::getDrawableText()
    {
        return _drawableText;
    }

    Arcade::EventType Menu::getDirection()
    {
        return _event;
    }

    void Menu::setIsRunning(bool isRunning)
    {
        _isRunning = isRunning;
    }

    std::vector <std::string> Menu::getLib()
    {
        return _liblist;
    }

    std::vector <std::string> Menu::getGame()
    {
        return _gamelist;
    }

    extern "C" IGame *entryPoint()
    {
        return new Menu();
    }
}
