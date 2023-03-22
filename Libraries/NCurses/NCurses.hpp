/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-arcade-roman.lopes
** File description:
** NCurses
*/

#ifndef NCURSE_HPP_
    #define NCURSE_HPP_

    #include <curses.h>
    #include "../../Abstract/ADisplay.hpp"

namespace Arcade {
    class NCurses : public ADisplay {
        public:
            /////////////////////// Constructors //////////////////////
            NCurses();
            ~NCurses() override = default;
            //////////////////////// Functions ////////////////////////
            void init() override;
            void update() override;
            void close() override;

            //////////////////////// Getters //////////////////////////
            int getEvent();

            //////////////////////// Setters //////////////////////////

            //////////////////////// Drawers //////////////////////////
            void drawText(std::string text, int x, int y);
            void drawSprite(void *spt);
            void drawBackground(void *bkg);
            //////////////////////// Creators /////////////////////////
            void createText() override;
            void createSprite() override;
        private:
            WINDOW *window;
    };
}

#endif /* !NCURSE_HPP_ */
