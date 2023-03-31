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

    void NCurses::init(const std::map<char, std::string>& gameAssets)
    {
        (void) gameAssets;
        this->window = initscr();
        cbreak();
        noecho();
        keypad(this->window, TRUE);
        curs_set(0);
        nodelay(this->window, TRUE);
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

    void NCurses::display(std::vector<Drawable> drawables)
    {
        (void) drawables;
        // TODO
    }

    void NCurses::display(std::vector<DrawableText> drawables)
    {
        (void) drawables;
        // TODO
    }

    Arcade::EventType NCurses::getEvent()
    {
        int ch = getch();
        if (ch == KEY_UP)
            return Arcade::EventType::UP;
        if (ch == KEY_DOWN)
            return Arcade::EventType::DOWN;
        if (ch == KEY_LEFT)
            return Arcade::EventType::LEFT;
        if (ch == KEY_RIGHT)
            return Arcade::EventType::RIGHT;
//        if (ch == 10)
//            return Arcade::EventType::ENTER;
//        if (ch == 27)
//            return Arcade::EventType::ESCAPE;
        return Arcade::EventType::NOTHING;
    }

    extern "C" IDisplay *entryPoint()
    {
        return new NCurses();
    }
}
