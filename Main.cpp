/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-arcade-roman.lopes
** File description:
** Main.cpp
*/

#include "Core/Core.hpp"
#include "Menu/Menu.hpp"
#include "Usage/Usage.hpp"

#include <iostream>
int main(int argc, char **argv)
{
    Usage usage;
    usage.CheckUsage(argc, argv);
    if (argc == 2 && std::string(argv[1]) == "-h") {
        usage.DisplayUsage();
        return 0;
    }
    Menu menu;
    menu.init();
    std::vector <std::string> gamelist = menu.getGame();
    std::vector <std::string> liblist = menu.getLib();
    std::cout << "Games List:" << std::endl;
    for (auto &i : gamelist)
        std::cout << i << std::endl;
    std::cout << std::endl <<"Library List:" << std::endl;
    for (auto &i : liblist)
        std::cout << i << std::endl;
    // Menu menu;
    // menu.start();

    return 0;
}