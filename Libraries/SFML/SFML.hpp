/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-arcade-roman.lopes
** File description:
** SFML
*/

#ifndef SFML_HPP_
    #define SFML_HPP_

    #include <SFML/Graphics.hpp>
    #include "../../Abstract/ADisplay.hpp"

namespace Arcade {
    class SFML : public ADisplay {
        public:
            SFML();
            void init() override;
            int getEvent() override;
            void createText() override;
            void createSprite() override;
            void update() override;
            void drawText(std::string text, int x, int y) override;
            void drawSprite(void *spt) override;
            void drawBackground(void *bkg) override;
            void close() override;
            ~SFML() override;
        private:
            sf::RenderWindow *window;
            sf::Event event;
            sf::Text text;
            sf::Font font;
    };
}

#endif /* !SFML_HPP_ */
