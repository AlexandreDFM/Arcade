/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-arcade-roman.lopes
** File description:
** NCurses
*/

#ifndef NCURSE_HPP_
    #define NCURSE_HPP_

    #include "../../Interface/IGraphic.hpp"
    #include <curses.h>

class NCurses : public IGraphic {
    public:
        void init();
        int getEvent();
        virtual void update();
        virtual void drawText(std::string text, int x, int y);
        virtual void drawSprite(void *spt);
        virtual void drawBackground(void *bkg);
        virtual void close();
    private:
        WINDOW *window;
};
#endif /* !NCURSE_HPP_ */
