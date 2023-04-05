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

    void NCurses::init(const std::map<char, std::string> &gameAssets)
    {
        (void) gameAssets;
        this->window = initscr();
        nodelay(this->window, TRUE);
    // if (!newterm(NULL, stderr, stdin)) {
    //     printw("Error opening new terminal.");
    //     refresh();
    //     endwin();
    // }
    }

    void NCurses::update()
    {
        static auto start = std::chrono::steady_clock::now();
        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsed_seconds = end - start;
        if (elapsed_seconds.count() > 0.1) start = std::chrono::steady_clock::now();
        else return;
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
        for (auto &drawable : drawables) {
                mvwprintw(this->window, drawable.y, drawable.x, "%c", drawable.draw);
            }
    }
    void NCurses::display(std::vector<DrawableText> drawables)
    {
        (void) drawables;
        // TODO
    }

    Arcade::EventType NCurses::getEvent()
    {

        int ch = wgetch(this->window);
        if (ch == 'z')
            return Arcade::EventType::UP;
        if (ch == 's')
            return Arcade::EventType::DOWN;
        if (ch == 'q')
            return Arcade::EventType::LEFT;
        if (ch == 'd')
            return Arcade::EventType::RIGHT;
        if (ch == 'm')
            return Arcade::EventType::LIBNEXT;
        if (ch == 'o')
            return Arcade::EventType::LIBPREV;
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
