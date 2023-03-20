/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-arcade-roman.lopes
** File description:
** ncurse
*/

#include "ncurse.hpp"

void ncurse::init()
{
    window = initscr();
    cbreak();
    noecho();
    keypad(window, TRUE);
    curs_set(0);
    nodelay(window, TRUE);
}

void ncurse::update()
{
    wrefresh(window);
}

void ncurse::drawText(std::string text, int x, int y)
{
    mvprintw(y, x, text.c_str());
}

void ncurse::drawSprite(void *spt)
{
}

void ncurse::drawBackground(void *bkg)
{
}

void ncurse::close()
{
    endwin();
}