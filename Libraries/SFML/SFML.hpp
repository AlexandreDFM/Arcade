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

#include <iostream>
#include <SFML/Graphics.hpp>

namespace Arcade {

    struct SFMLSprite {
        sf::Texture texture;
        sf::Sprite sprite;
    };

    class SFML : public ADisplay {
        public:
            SFML();
            ~SFML() override = default;
            void init(const std::map<char, std::string> &gameAssets) override;
            Arcade::EventType getEvent() override;
            void update() override;
            void clear() override;
            void close() override;
            void display(std::vector<Drawable>) override;
            void display(std::vector<DrawableText>) override;
        private:
            sf::RenderWindow *window;
            sf::Sprite sprite;
            sf::Event event;
            sf::Text text;
            sf::Font font;
            std::map<char, SFMLSprite> _spriteAssets;
    };
}

#endif /* !SFML_HPP_ */
