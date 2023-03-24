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
            void init(const std::vector<std::map<char, std::string>>& gameAssets) override;
            Arcade::EventType getEvent() override;
            void update() override;
            void close() override;
            void display(std::vector<Drawable>) override;
            void display(std::vector<DrawableText>) override;
            ~SFML() override;
        private:
            sf::RenderWindow *window;
            sf::Event event;
            sf::Text text;
            sf::Font font;
            std::vector<std::map<char, sf::Sprite>> _spriteAssets;
    };
}

#endif /* !SFML_HPP_ */
