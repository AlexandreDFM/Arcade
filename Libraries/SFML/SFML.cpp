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
        this->window->setFramerateLimit(60);
        this->font.loadFromFile("./Assets/Police/Poppins-Black.ttf");
        this->text.setFont(this->font);
        this->text.setCharacterSize(24);
        this->text.setStyle(sf::Text::Bold);
        sf::IntRect rect = sf::IntRect(0, 0, 40, 40);
        for (auto &asset : gameAssets) {
            this->_spriteAssets[asset.first] = {sf::Texture(), sf::Sprite()};
            this->_spriteAssets[asset.first].texture.loadFromFile(asset.second);
            this->_spriteAssets[asset.first].sprite.setTexture(this->_spriteAssets[asset.first].texture);
            this->_spriteAssets[asset.first].sprite.setTextureRect(rect);
        }
    }

    EventType SFML::getEvent() {
        while (this->window->pollEvent(this->event)) {
            if (this->event.type == sf::Event::Closed) {
                return EventType::CLOSE;
            }
            if (this->event.type == sf::Event::KeyPressed) {
                switch (this->event.key.code) {
                    case sf::Keyboard::Escape: return EventType::CLOSE;
                    case sf::Keyboard::Space:  return EventType::RESTART;
                    case sf::Keyboard::Right:  return EventType::RIGHT;
                    case sf::Keyboard::Left:   return EventType::LEFT;
                    case sf::Keyboard::Down:   return EventType::DOWN;
                    case sf::Keyboard::Up:     return EventType::UP;
                    case sf::Keyboard::L:      return EventType::LIBPREV;
                    case sf::Keyboard::M:      return EventType::LIBNEXT;
                    case sf::Keyboard::O:      return EventType::GAMEPREV;
                    case sf::Keyboard::P:      return EventType::GAMENEXT;
                    default:                   return EventType::NOTHING;
                }
            }
        }
        return EventType::NOTHING;
    }

    void SFML::display(std::vector<Drawable> drawables)
    {
        if (drawables.empty()) return;
        for (auto &drawable : drawables) {
            for (auto &sprite : this->_spriteAssets) {
                if (sprite.first == drawable.draw) {
//                    std::cout << "ROTATION: " << drawable.rotation << std::endl;
//                    switch (drawable.rotation) {
//                        case SpriteDirection::NO_DIRECTION: sprite.second.sprite.setRotation(0);   break;
//                        case SpriteDirection::NORTH:        sprite.second.sprite.setRotation(0);   break;
//                        case SpriteDirection::SOUTH:        sprite.second.sprite.setRotation(180); break;
//                        case SpriteDirection::EAST:         sprite.second.sprite.setRotation(90);  break;
//                        case SpriteDirection::WEST:         sprite.second.sprite.setRotation(270); break;
//                        default :                           sprite.second.sprite.setRotation(0);   break;
//                    }
                    sprite.second.sprite.setPosition({(float) drawable.x * 40, (float) drawable.y * 40});
                    this->window->draw(sprite.second.sprite);
                }
            }
        }
    }

    void SFML::display(std::vector<DrawableText> drawables)
    {
        if (drawables.empty()) return;
        for (auto &drawable : drawables) {
            this->text.setString(drawable.text);
            switch (drawable.color) {
                case Color::RED:    this->text.setFillColor(sf::Color::Red);    break;
                case Color::BLUE:   this->text.setFillColor(sf::Color::Blue);   break;
                case Color::BLACK:  this->text.setFillColor(sf::Color::Black);  break;
                case Color::WHITE:  this->text.setFillColor(sf::Color::White);  break;
                case Color::GREEN:  this->text.setFillColor(sf::Color::Green);  break;
//                case Color::YELLOW: this->text.setFillColor(sf::Color::Yellow); break;
                default:            this->text.setFillColor(sf::Color::White);  break;
            }
            this->text.setPosition({(float) drawable.x * 40, (float) drawable.y * 40});
            this->window->draw(this->text);
        }
    }

    void SFML::update()
    {
        this->window->display();

    }

    void SFML::clear()
    {
        this->window->clear(sf::Color::Black);
    }

    void SFML::close()
    {
        this->window->close();
        delete this->window;
    }

    extern "C" {
        ADisplay *entryPoint()
        {
            return new SFML();
        }
        char *getType()
        {
            return (char *) "Lib";
        }
    }
}
