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
        keypad(this->window, TRUE);
        start_color(); noecho(); curs_set(0);
        init_pair(1, COLOR_BLACK, COLOR_BLACK);
        init_pair(2, COLOR_BLACK, COLOR_RED);
        init_pair(3, COLOR_BLACK, COLOR_GREEN);
        init_pair(4, COLOR_BLACK, COLOR_BLUE);
        init_pair(5, COLOR_BLACK, COLOR_WHITE);
        init_pair(6, COLOR_BLACK, COLOR_MAGENTA);
        init_pair(7, COLOR_BLACK, COLOR_CYAN);
        init_pair(8, COLOR_BLACK, COLOR_YELLOW);
    }

    void NCurses::update()
    {
        static auto start = std::chrono::steady_clock::now();
        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsed_seconds = end - start;
        if (elapsed_seconds.count() > 0.1) start = std::chrono::steady_clock::now();
        else return;
        wrefresh(this->window);
    }

    void NCurses::clear()
    {
        static auto start = std::chrono::steady_clock::now();
        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsed_seconds = end - start;
        if (elapsed_seconds.count() > 0.1) start = std::chrono::steady_clock::now();
        else return;
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
            switch (drawable.color) {
                case Arcade::Color::BLACK:   attron(COLOR_PAIR(1)); break;
                case Arcade::Color::RED:     attron(COLOR_PAIR(2)); break;
                case Arcade::Color::GREEN:   attron(COLOR_PAIR(3)); break;
                case Arcade::Color::BLUE:    attron(COLOR_PAIR(4)); break;
                case Arcade::Color::WHITE:   attron(COLOR_PAIR(5)); break;
                case Arcade::Color::MAGENTA: attron(COLOR_PAIR(6)); break;
                case Arcade::Color::CYAN:    attron(COLOR_PAIR(7)); break;
                case Arcade::Color::YELLOW:  attron(COLOR_PAIR(8)); break;
                default :                    attron(COLOR_PAIR(1)); break;
            }
                mvwprintw(this->window, drawable.y, drawable.x * 2, "  ");
            switch (drawable.color) {
                case Arcade::Color::BLACK:   attroff(COLOR_PAIR(1)); break;
                case Arcade::Color::RED:     attroff(COLOR_PAIR(2)); break;
                case Arcade::Color::GREEN:   attroff(COLOR_PAIR(3)); break;
                case Arcade::Color::BLUE:    attroff(COLOR_PAIR(4)); break;
                case Arcade::Color::WHITE:   attroff(COLOR_PAIR(5)); break;
                case Arcade::Color::MAGENTA: attroff(COLOR_PAIR(6)); break;
                case Arcade::Color::CYAN:    attroff(COLOR_PAIR(7)); break;
                case Arcade::Color::YELLOW:  attroff(COLOR_PAIR(8)); break;
                default :                    attroff(COLOR_PAIR(1)); break;
            }
        }
    }

    void NCurses::display(std::vector<DrawableText> drawables)
    {
        for (auto &drawable : drawables) {
            switch (drawable.color) {
                case Arcade::Color::BLACK:   attron(COLOR_PAIR(1)); break;
                case Arcade::Color::RED:     attron(COLOR_PAIR(2)); break;
                case Arcade::Color::GREEN:   attron(COLOR_PAIR(3)); break;
                case Arcade::Color::BLUE:    attron(COLOR_PAIR(4)); break;
                case Arcade::Color::WHITE:   attron(COLOR_PAIR(5)); break;
                case Arcade::Color::MAGENTA: attron(COLOR_PAIR(6)); break;
                case Arcade::Color::CYAN:    attron(COLOR_PAIR(7)); break;
                case Arcade::Color::YELLOW:  attron(COLOR_PAIR(8)); break;
                default :                    attron(COLOR_PAIR(1)); break;
            }
            mvwprintw(this->window, drawable.y, drawable.x * 2, "%s", drawable.text.c_str());
            switch (drawable.color) {
                case Arcade::Color::BLACK:   attroff(COLOR_PAIR(1)); break;
                case Arcade::Color::RED:     attroff(COLOR_PAIR(2)); break;
                case Arcade::Color::GREEN:   attroff(COLOR_PAIR(3)); break;
                case Arcade::Color::BLUE:    attroff(COLOR_PAIR(4)); break;
                case Arcade::Color::WHITE:   attroff(COLOR_PAIR(5)); break;
                case Arcade::Color::MAGENTA: attroff(COLOR_PAIR(6)); break;
                case Arcade::Color::CYAN:    attroff(COLOR_PAIR(7)); break;
                case Arcade::Color::YELLOW:  attroff(COLOR_PAIR(8)); break;
                default :                    attroff(COLOR_PAIR(1)); break;
            }
        }
    }

    Arcade::EventType NCurses::getEvent()
    {

        int key = wgetch(this->window);
        switch (key) {
            case 27:        return Arcade::EventType::CLOSE;
            case ' ':       return Arcade::EventType::RESTART;
            case KEY_RIGHT: return Arcade::EventType::RIGHT;
            case KEY_LEFT:  return Arcade::EventType::LEFT;
            case KEY_DOWN:  return Arcade::EventType::DOWN;
            case KEY_UP:    return Arcade::EventType::UP;
            case 'd':       return Arcade::EventType::RIGHT;
            case 'q':       return Arcade::EventType::LEFT;
            case 's':       return Arcade::EventType::DOWN;
            case 'z':       return Arcade::EventType::UP;
            case 'l':       return Arcade::EventType::LIBPREV;
            case 'm':       return Arcade::EventType::LIBNEXT;
            case 'o':       return Arcade::EventType::GAMEPREV;
            case 'p':       return Arcade::EventType::GAMENEXT;
            case 'e':       return Arcade::EventType::ACTION1;
            case 'r':       return Arcade::EventType::ACTION2;
            case 't':       return Arcade::EventType::MENU;
            case 'y':       return Arcade::EventType::SAVE;
            default:        return Arcade::EventType::NOTHING;
        }
    }

    extern "C" {
    IDisplay *entryPoint()
        {
            return new NCurses();
        }
    char *getType()
        {
            return (char *) "libNcurses";
        }
    }
}
