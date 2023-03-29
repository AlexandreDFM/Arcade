/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-arcade-roman.lopes
** File description:
** SFML
*/

#include "SFML.hpp"

namespace Arcade {
    SFML::SFML()
    {
        this->window = nullptr;
        this->event = sf::Event();
    }

    void SFML::init(const std::map<char, std::string> &gameAssets)
    {
        this->window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "Arkade");
        this->font.loadFromFile("arial.ttf");
        this->text.setFont(this->font);
        this->text.setCharacterSize(24);
        this->text.setStyle(sf::Text::Bold);
        sf::IntRect rect = sf::IntRect(0, 0, 8, 8);
        for (auto &asset : gameAssets) {
            (void) asset;
//            sf::Texture texture;
//            texture.loadFromFile(asset.begin()->second);
//            this->sprite.setTexture(texture);
//            this->_spriteAssets.insert({asset.begin()->first, sprite});
            rect.left += 8;
        }
    }

    EventType SFML::getEvent() {
        while (this->window->pollEvent(this->event)) {
            if (this->event.type == sf::Event::Closed)
                this->window->close();
            if (this->event.type == sf::Event::KeyPressed) {
                switch (this->event.key.code) {
                    case sf::Keyboard::Escape:
                        return (EventType::CLOSE);
                    case sf::Keyboard::Left:
                        return (EventType::LEFT);
                    case sf::Keyboard::Right:
                        return (EventType::RIGHT);
                    case sf::Keyboard::Up:
                        return (EventType::UP);
                    case sf::Keyboard::Down:
                        return (EventType::DOWN);
                    case sf::Keyboard::Space:
                        return (EventType::RESTART);
                    case sf::Keyboard::L:
                        return (EventType::LIBPREV);
                    case sf::Keyboard::M:
                        return (EventType::LIBNEXT);
                    case sf::Keyboard::O:
                        return (EventType::GAMEPREV);
                    case sf::Keyboard::P:
                        return (EventType::GAMENEXT);
                    default:
                        break;
                }
            }
        }
        return EventType::NOTHING;
    }

    void SFML::display(std::vector<Drawable> drawables)
    {
        for (auto &drawable : drawables) {
            for (auto &sprite : this->_spriteAssets) {
                if (sprite.begin()->first == drawable.draw) {
                    sprite.begin()->second.setPosition({(float) drawable.x, (float) drawable.y});
                    this->window->draw(sprite.begin()->second);
                }
            }
        }
    }

    void SFML::display(std::vector<DrawableText> drawables)
    {
        for (auto &drawable : drawables) {
            this->text.setString(drawable.text);
            this->text.setPosition({(float) drawable.x, (float) drawable.y});
            this->window->draw(this->text);
        }
    }

    void SFML::update()
    {
        this->window->clear();
        this->window->display();
    }

    void SFML::close()
    {
        this->window->close();
        delete this->window;

    }
}
