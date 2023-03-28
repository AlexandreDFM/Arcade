/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-arcade-roman.lopes
** File description:
** NCurses
*/

#include "NCurses.hpp"

namespace Arcade {
    NCurses::NCurses()
    {
        this->window = nullptr;
    }

    void NCurses::init()
    {
        this->window = initscr();
        cbreak();
        noecho();
        keypad(this->window, TRUE);
        curs_set(0);
        nodelay(this->window, TRUE);
    }

    int NCurses::getEvent()
    {
        int ch = getch();
        if (ch == KEY_UP)
            return 1;
        if (ch == KEY_DOWN)
            return 2;
        if (ch == KEY_LEFT)
            return 3;
        if (ch == KEY_RIGHT)
            return 4;
        if (ch == 10)
            return 5;
        if (ch == 27)
            return 6;
        return 0;
    }

    void NCurses::update()
    {
        wrefresh(this->window);
        wclear(this->window);
    }

    void NCurses::close()
    {
        endwin();
    }
}
