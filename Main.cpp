/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-arcade-roman.lopes
** File description:
** Main.cpp
*/

#include "Interface/IDisplayModule.hpp"
#include "Interface/IGameModule.hpp"
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
    // Menu menu;
    // menu.start();
    return 0;
}
