/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-arcade-roman.lopes
** File description:
** Usage
*/

#include "Usage.hpp"

Usage::Usage()
{
}

void Usage::DisplayUsage()
{
    std::cout << "USAGE" << std::endl;
    std::cout << "\t./arcade Libraries" << std::endl;
    std::cout << "DESCRIPTION" << std::endl;
    std::cout << "\tLibraries\t\tlibrary in which the game will be played" << std::endl;
}

void Usage::CheckUsage(int ac, char **av)
{
    if (ac != 2) {
        DisplayUsage();
        exit(84);
    }
}

void Usage::CheckLib(char **av)
{
    std::string lib = av[1];
    if (lib.find(".so") == std::string::npos) {
        DisplayUsage();
        exit(84);
    }
}
