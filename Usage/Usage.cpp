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
    std::cout << "\tLibraries\t\tlibrary in which the game will be played" << std::endl << std::endl;
    std ::cout << "\tEscape Key\t\tClose the program" << std::endl;
    std::cout << "\tArrow Keys\t\tFor movements in game" << std::endl;
    std::cout << "\tSpace Key\t\tFor reset games" << std::endl;
    std::cout << "\tM Key\t\t\tFor graphical next library" << std::endl;
    std::cout << "\tL Key\t\t\tFor graphical previous library" << std::endl;
    std::cout << "\tO Key\t\t\tFor game previous library" << std::endl;
    std::cout << "\tP Key\t\t\tFor game next library" << std::endl;
    std::cout << "\tR Key\t\t\tFor validate choices in menu and action1" << std::endl;
    std::cout << "\tE Key\t\t\tFor action2" << std::endl;
    std::cout << "\tY Key\t\t\tFor going back to menu" << std::endl;
}

void Usage::CheckUsage(int ac, char **av)
{
    if (ac != 2) {
        Usage::DisplayUsage();
        exit(84);
//        throw Usage::Error(Usage::Error::LIB);
    }
    if (std::string(av[1]) == "-h") {
        DisplayUsage();
        exit (0);
    }
}

void Usage::CheckLib(char **av)
{
    std::string lib = av[1];
    if (lib.find(".so") == std::string::npos) {
        DisplayUsage(); throw Usage::Error(Usage::Error::LIB);
    }
}
