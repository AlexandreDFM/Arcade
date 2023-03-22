/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-arcade-roman.lopes
** File description:
** Menu
*/

#include "Menu.hpp"

void Menu::init()
{
    std::string path = "./lib";
    for (const auto & entry : std::filesystem::directory_iterator(path)) {
        if (entry.path() == "./lib/lib_arcade_sfmlo.so" || entry.path() == "./lib/lib_arcade_ncurse.so" || entry.path() == "./lib/lib_arcade_opengl.so") {
             _liblist.push_back(entry.path());
        }
        else {
            _gamelist.push_back(entry.path());
        }
    }
}

int Menu::handleEvent(int event)
{
    if (event == 1)

    return 0;
}

void Menu::update()
{
}

bool Menu::getIsRunning()
{
    return false;
}

bool Menu::setIsRunning()
{
    return false;
}

void Menu::close()
{
}


std::vector <std::string> Menu::getLib()
{
    return _liblist;
}

std::vector <std::string> Menu::getGame()
{
    return _gamelist;
}