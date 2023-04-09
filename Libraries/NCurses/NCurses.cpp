/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-arcade-roman.lopes
** File description:
** NCurses
*/

#include "NCurses.hpp"

namespace Arcade {
    /**
     * This is a constructor for the NCurses class that initializes the window
     * pointer to nullptr.
     */
    NCurses::NCurses()
    {
        this->window = nullptr;
    }

    /**
     * The function initializes the NCurses library and sets up color pairs for
     * the game.
     *
     * @param gameAssets gameAssets is a map that contains character keys and
     * their corresponding string values. It is passed as a parameter to the
     * init() function of the NCurses class. However, in the given code, the
     * gameAssets parameter is not used and is cast to void to avoid a compiler
     * warning.
     */
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

    /**
     * This function updates the NCurses window every 0.1 seconds.
     *
     * @return If the elapsed time since the last update is less than 0.1 seconds,
     * then nothing is returned and the function exits early. If the elapsed time
     * is greater than or equal to 0.1 seconds, then the function refreshes the
     * window and returns nothing.
     */
    void NCurses::update()
    {
        static auto start = std::chrono::steady_clock::now();
        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsed_seconds = end - start;
        if (elapsed_seconds.count() > 0.1) start = std::chrono::steady_clock::now();
        else return;
        wrefresh(this->window);
    }

    /**
     * The function clears the NCurses window if at least 0.1 seconds have passed
     * since the last clear.
     *
     * @return If the elapsed time since the last call to `clear()` is less than
     * 0.1 seconds, then nothing is done and the function returns. Otherwise, the
     * `window` is cleared using the `wclear()` function.
     */
    void NCurses::clear()
    {
        static auto start = std::chrono::steady_clock::now();
        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsed_seconds = end - start;
        if (elapsed_seconds.count() > 0.1) start = std::chrono::steady_clock::now();
        else return;
        wclear(this->window);
    }

    /**
     * The function closes the NCurses window.
     */
    void NCurses::close()
    {
        endwin();
    }

    /**
     * The function displays a vector of Drawable objects with different colors
     * using the NCurses library.
     *
     * @param drawables A vector of Drawable objects that contain information
     * about the position and color of objects to be displayed on the screen. The
     * function iterates through this vector and displays each object on the
     * screen with the specified color.
     */
    void NCurses::display(std::vector<Drawable> drawables)
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

    /**
     * This function displays a vector of DrawableText objects with different
     * colors using the NCurses library.
     *
     * @param drawables The parameter `drawables` is a vector of `DrawableText`
     * objects. Each `DrawableText` object contains information about a text
     * string to be displayed on the screen, including its position (x and y
     * coordinates) and color. The `display` function uses this information to
     * print the text strings
     */
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

    /**
     * The function returns an Arcade event type based on the key pressed in the
     * NCurses window.
     *
     * @return The function `getEvent()` returns an `Arcade::EventType` enum value
     * based on the user input received through the `ncurses` library. The
     * returned value corresponds to the type of event that occurred, such as a
     * key press or a menu selection. If no event occurred, the function returns
     * `Arcade::EventType::NOTHING`.
     */
    Arcade::EventType NCurses::getEvent()
    {
        switch (wgetch(this->window)) {
            case 27:        return Arcade::EventType::CLOSE;
            case ' ':       return Arcade::EventType::RESTART;
            case KEY_RIGHT: return Arcade::EventType::RIGHT;
            case KEY_LEFT:  return Arcade::EventType::LEFT;
            case KEY_DOWN:  return Arcade::EventType::DOWN;
            case KEY_UP:    return Arcade::EventType::UP;
            case 'l':       return Arcade::EventType::LIBPREV;
            case 'm':       return Arcade::EventType::LIBNEXT;
            case 'o':       return Arcade::EventType::GAMEPREV;
            case 'p':       return Arcade::EventType::GAMENEXT;
            case 'e':       return Arcade::EventType::ACTION1;
            case 'r':       return Arcade::EventType::ACTION2;
            case 't':       return Arcade::EventType::SAVE;
            case 'y':       return Arcade::EventType::MENU;
            default:        return Arcade::EventType::NOTHING;
        }
    }

    /* The `extern "C"` block is used to specify that the functions inside it
    should be compiled using C linkage instead of C++ linkage. This is
    necessary when creating a shared library that will be used by programs
    written in other languages, such as C. */
    extern "C" {
        /**
         * The function returns a new instance of the NCurses class that
         * implements the IDisplay interface.
         *
         * @return A pointer to a new instance of the `NCurses` class, which
         * implements the `IDisplay` interface.
         */
        IDisplay *entryPoint()
        {
            return new NCurses();
        }

        /**
         * The function returns a string indicating the type of library as
         * "libNcurses".
         *
         * @return A string literal "libNcurses" is being returned as a pointer to
         * a character array.
         */
        char *getType()
        {
            return (char *) "libNcurses";
        }
    }
}
