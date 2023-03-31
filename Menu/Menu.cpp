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
            if (entry.path() == "./lib/lib_arcade_sfmlo.so" || entry.path() == "./lib/lib_arcade_ncurse.so" || entry.path() == "./lib/lib_arcade_opengl.so") {
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

    std::vector <std::string> Menu::getLib()
    {
        return _liblist;
    }

    std::vector <std::string> Menu::getGame()
    {
        return _gamelist;
    }
}
