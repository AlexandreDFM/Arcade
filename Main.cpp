/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-arcade-roman.lopes
** File description:
** Main.cpp
*/

#include "Core/Core.hpp"
#include "Usage/Usage.hpp"

int main(int argc, char **argv)
{
    Usage::CheckUsage(argc, argv);
    if (argc == 2 && std::string(argv[1]) == "-h") {
        Usage::DisplayUsage(); return 0;
    }
    if (!std::filesystem::exists(argv[1])) {
        std::cout << "Error: " << argv[1] << " is not a valid path" << std::endl;
        exit(84);
    }
    Arcade::Core core = Arcade::Core(argv[1]);
    core.loop();
}
