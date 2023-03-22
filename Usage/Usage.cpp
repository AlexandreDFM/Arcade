/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-arcade-roman.lopes
** File description:
** Usage
*/

#include "Usage.hpp"

Usage::Error::Error(ErrorType type)
{
    switch (type) {
        case LIB:
            _message = "Error: Library not found";
            break;
        case GAME:
            _message = "Error: Game not found";
            break;
    }
}

const std::string &Usage::Error::what() const { return _message; }

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
        Usage::DisplayUsage();
        exit(0);
//        throw Usage::Error(Usage::Error::LIB);
    }
}

void Usage::CheckLib(char **av)
{
    std::string lib = av[1];
    if (lib.find(".so") == std::string::npos) {
        DisplayUsage(); throw Usage::Error(Usage::Error::LIB);
    }
}
