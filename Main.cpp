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
#include "Libraries/NCurses/NCurses.hpp"
#include "Libraries/SDL2/SDL2.hpp"
#include "DLLoader/DLLoader.hpp"
#

int main(int argc, char **argv)
{
    Usage::CheckUsage(argc, argv);
    if (argc == 2 && std::string(argv[1]) == "-h") {
        Usage::DisplayUsage(); return 0;
    }

//    std::shared_ptr<Arcade::Menu> menu = std::make_shared<Arcade::Menu>(); // Error on this line because not Arcade::Menu but Arcade::IGame
//    std::shared_ptr<Arcade::IDisplay> game = std::make_shared<Arcade::SFML>();

    DLLoader<Arcade::IDisplay> loader("./lib/lib_arcade_ncurses.so");
    auto instance = loader.getInstance("create_display_module");
    instance->init();
    while(instance->getIsRunning()) {
        instance->drawText("Hello", 0, 0);
        instance->update();
    }
    instance->stop();
//    instance->~IDisplayModule();
//    return 0;

//    menu->init();
//    std::vector <std::string> gameList = menu->getGame();
//    std::vector <std::string> libList = menu->getLib();
//    std::cout << "Games List:" << std::endl;
//    for (auto &i : gameList) std::cout << i << std::endl;
//    std::cout << std::endl <<"Library List:" << std::endl;
//    for (auto &i : libList) std::cout << i << std::endl;
//
//    game->init();
//    while(game->getIsRunning()) {
//        game->drawText("Hello", 0, 0);
//        game->update();
//    }
    // Menu menu;
    // menu.start();

    // Usage usage;
    // usage.CheckUsage(argc, argv);
    // Menu menu;
    // ncurse ncurse;
    // menu.init();
    // std::vector <std::string> gamelist = menu.getGame();
    // std::vector <std::string> liblist = menu.getLib();
    // ncurse.init();
    // while (1)
    // {
    //     ncurse.drawText(liblist[0], 0, 0);
    //     ncurse.drawText(liblist[1], 0, 1);
    //     ncurse.drawText(liblist[2], 0, 2);
    //     ncurse.drawText(gamelist[0], 0, 5);
    //     ncurse.update();
    // }

    return 0;
}
