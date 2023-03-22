/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-arcade-roman.lopes
** File description:
** Main.cpp
*/

#include "Core/Core.hpp"
#include "Menu/Menu.hpp"
#include "Usage/Usage.hpp"
#include "ncurse/ncurse.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    Usage usage;
    usage.CheckUsage(argc, argv);
    Menu menu;
    ncurse ncurse;
    menu.init();
    std::vector <std::string> gamelist = menu.getGame();
    std::vector <std::string> liblist = menu.getLib();
    ncurse.init();
    while (1)
    {
        ncurse.drawText(liblist[0], 0, 0);
        ncurse.drawText(liblist[1], 0, 1);
        ncurse.drawText(liblist[2], 0, 2);
        ncurse.drawText(gamelist[0], 0, 5);
        ncurse.update();
    }

    return 0;
}