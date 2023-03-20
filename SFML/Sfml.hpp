/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-arcade-roman.lopes
** File description:
** Sfml
*/

#ifndef SFML_HPP_
#define SFML_HPP_
#include "../Interface/IGraphic.hpp"
#include <SFML/Graphics.hpp>

class Sfml {
    public:
        Sfml();
        void init();
        int getEvent();
        void update();
        void drawText(std::string text, int x, int y);
        void drawSprite(void *spt);
        void drawBackground(void *bkg);
        void close();
        ~Sfml();

    protected:
    private:
        sf::RenderWindow *window;
        sf::Event event;
        sf::Text text;
        sf::Font font;
};

#endif /* !SFML_HPP_ */
