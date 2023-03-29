/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-arcade-roman.lopes
** File description:
** Main.cpp
*/

#include <memory>
#include "Menu/Menu.hpp"
#include "Usage/Usage.hpp"
#include "Libraries/SFML/SFML.hpp"
#include "Core/Core.hpp"
#include "Libraries/NCurses/NCurses.hpp"
#include "Libraries/SDL2/SDL2.hpp"
#include "DLLoader/DLLoader.hpp"

int main(int argc, char **argv)
{
    Usage::CheckUsage(argc, argv);
    if (argc == 2 && std::string(argv[1]) == "-h") {
        Usage::DisplayUsage(); return 0;
    }
    Arcade::Core("./lib/arcade_ncurses.so");
}
