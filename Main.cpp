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
//#include "Libraries/SDL2/SDL2.hpp"
#include "DLLoader/DLLoader.hpp"
#include "Games/Snake/Snake.hpp"

int main(int argc, char **argv)
{
    Usage::CheckUsage(argc, argv);
    if (argc == 2 && std::string(argv[1]) == "-h") {
        Usage::DisplayUsage(); return 0;
    }
    std::unique_ptr<Arcade::IDisplay> display = std::make_unique<Arcade::SFML>();
    std::unique_ptr<Arcade::IGame> game = std::make_unique<Arcade::SnakeGame>();
    game->init();
    display->init(game->getAssets());
    int _time = 1;
    clock_t _clock = clock();
    while (game->isRunning()) {
        clock_t _clock2 = clock();
        int sec = (_clock2 - _clock) / CLOCKS_PER_SEC;
        if (sec >= _time) {
            game->update(display->getEvent());
            display->display(game->getDrawable());
        }
    }
    Arcade::Core("./lib/arcade_ncurses.so");
}
