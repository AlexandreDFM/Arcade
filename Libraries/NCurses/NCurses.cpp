/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-arcade-roman.lopes
** File description:
** NCurses
*/

#include "NCurses.hpp"

void NCurses::init()
{
    window = initscr();
    cbreak();
    noecho();
    keypad(window, TRUE);
    curs_set(0);
    nodelay(window, TRUE);
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
    wrefresh(window);
    wclear(window);
}

void NCurses::drawText(std::string text, int x, int y)
{
    mvprintw(y, x, text.c_str());
}

void NCurses::drawSprite(void *spt)
{
}

void NCurses::drawBackground(void *bkg)
{
}

void NCurses::close()
{
    endwin();
}
