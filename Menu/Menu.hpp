/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-arcade-roman.lopes
** File description:
** Menu
*/

#ifndef MENU_HPP_
#define MENU_HPP_

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <filesystem>
#include "../Interface/IGame.hpp"
class Menu : public IGame{
    public:
        void init();
        int handleEvent(int event);
        void update();
        bool getIsRunning();
        bool setIsRunning();
        void close();
        std::vector <std::string> getLib();
        std::vector <std::string> getGame();
    protected:
    private:
        std::vector <std::string> _liblist;
        std::vector <std::string> _gamelist;
};

#endif /* !MENU_HPP_ */
