/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-arcade-roman.lopes
** File description:
** SFML
*/

#include "SFML.hpp"

namespace Arcade {
    /**
     * This is a constructor for the SFML class that initializes the window and
     * event variables.
     */
    SFML::SFML()
    {
        this->window = nullptr;
        this->event = sf::Event();
    }

    /**
     * The function initializes the SFML window and loads game assets such as
     * textures and sprites.
     *
     * @param gameAssets gameAssets is a std::map that contains pairs of
     * characters and strings. The characters represent the keys and the strings
     * represent the file paths to the corresponding sprite assets. These sprite
     * assets are loaded into textures and sprites using the SFML library.
     */
    void SFML::init(const std::map<char, std::string> &gameAssets)
    {
        this->window = new sf::RenderWindow(sf::VideoMode(1920, 1080), "Arkade");
        this->window->setFramerateLimit(60);
        this->font.loadFromFile("./Assets/Police/Poppins-Black.ttf");
        this->text.setFont(this->font);
        this->text.setCharacterSize(24);
        this->text.setStyle(sf::Text::Bold);
        this->_spriteSize = 40;
        if (std::ifstream("./Assets/Config/SpriteSize.txt")) {
            std::ifstream file("./Assets/Config/SpriteSize.txt");
            std::string spriteSize = "";
            for (int i = 0; i < 1; i++) getline(file, spriteSize);
            file.close();
            try {
                this->_spriteSize = std::stoi(spriteSize);
            } catch (std::exception &e) {
                this->_spriteSize = 40;
            }
        }
        sf::IntRect rect = sf::IntRect(0, 0, this->_spriteSize, this->_spriteSize);
        for (auto &asset : gameAssets) {
            this->_spriteAssets[asset.first] = {sf::Texture(), sf::Sprite()};
            this->_spriteAssets[asset.first].texture.loadFromFile(asset.second);
            this->_spriteAssets[asset.first].sprite.setTexture(this->_spriteAssets[asset.first].texture);
            this->_spriteAssets[asset.first].sprite.setTextureRect(rect);
            this->_spriteAssets[asset.first].sprite.setOrigin(this->_spriteSize / 2, this->_spriteSize / 2);
        }
    }

    /**
     * This function returns the type of event that occurred in a SFML window.
     *
     * @return an EventType enum value based on the type of event that is being
     * polled from the SFML window. If the event is a closed event, it returns
     * EventType::CLOSE. If the event is a key press event, it checks which key
     * was pressed and returns the corresponding EventType value. If no event is
     * being polled, it returns EventType::NOTHING.
     */
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
                    case sf::Keyboard::E:      return EventType::ACTION1;
                    case sf::Keyboard::R:      return EventType::ACTION2;
                    case sf::Keyboard::T:      return EventType::SAVE;
                    case sf::Keyboard::Y:      return EventType::MENU;
                    default:                   return EventType::NOTHING;
                }
            }
        }
        return EventType::NOTHING;
    }

    /**
     * The function displays a vector of drawable objects using sprite assets and
     * sets their position and rotation based on their properties.
     *
     * @param drawables A vector of Drawable objects that contain information
     * about what to draw and where to draw it on the SFML window.
     *
     * @return If the `drawables` vector is empty, the function returns
     * immediately without doing anything.
     */
    void SFML::display(std::vector<Drawable> drawables)
    {
        if (drawables.empty()) return;
        for (auto &drawable : drawables) {
            for (auto &sprite : this->_spriteAssets) {
                if (sprite.first == drawable.draw) {
                    sf::IntRect rect = sf::IntRect(0, 0, drawable.rect.width, drawable.rect.height);
                    sprite.second.sprite.setTextureRect(rect);
                    sprite.second.sprite.setPosition({(float) drawable.x * this->_spriteSize, (float) drawable.y * this->_spriteSize});
                    this->window->draw(sprite.second.sprite);
                    if (drawable.draw != 'h' && drawable.draw != 'b') continue;
                    switch (drawable.rotation) {
                        case Direction::WEST:  sprite.second.sprite.setRotation(0);   break;
                        case Direction::NORTH: sprite.second.sprite.setRotation(90);  break;
                        case Direction::EAST:  sprite.second.sprite.setRotation(180); break;
                        case Direction::SOUTH: sprite.second.sprite.setRotation(270); break;
                        default:               sprite.second.sprite.setRotation(0);   break;
                    }
                }
            }
        }
    }

    /**
     * The function displays a vector of text objects with specified colors and
     * positions on an SFML window.
     *
     * @param drawables A vector of DrawableText objects that contain information
     * about the text to be displayed, its position, and color.
     *
     * @return If the `drawables` vector is empty, the function returns without
     * doing anything.
     */
    void SFML::display(std::vector<DrawableText> drawables)
    {
        if (drawables.empty()) return;
        for (auto &drawable : drawables) {
            this->text.setString(drawable.text);
            switch (drawable.color) {
                case Color::RED:     this->text.setFillColor(sf::Color::Red);     break;
                case Color::BLUE:    this->text.setFillColor(sf::Color::Blue);    break;
                case Color::BLACK:   this->text.setFillColor(sf::Color::Black);   break;
                case Color::WHITE:   this->text.setFillColor(sf::Color::White);   break;
                case Color::GREEN:   this->text.setFillColor(sf::Color::Green);   break;
                case Color::YELLOW:  this->text.setFillColor(sf::Color::Yellow);  break;
                case Color::CYAN:    this->text.setFillColor(sf::Color::Cyan);    break;
                case Color::MAGENTA: this->text.setFillColor(sf::Color::Magenta); break;
                default:             this->text.setFillColor(sf::Color::White);   break;
            }
            this->text.setPosition({(float) drawable.x * this->_spriteSize, (float) drawable.y * this->_spriteSize});
            this->window->draw(this->text);
        }
    }

    /**
     * The SFML update function displays the window.
     */
    void SFML::update()
    {
        this->window->display();

    }

    /**
     * The SFML clear function clears the window with a black color.
     */
    void SFML::clear()
    {
        this->window->clear(sf::Color::Black);
    }

    /**
     * This function closes the SFML window and deletes the window object.
     */
    void SFML::close()
    {
        this->window->close();
        delete this->window;
    }

    /* The `extern "C"` block is used to specify that the functions inside it
    should be compiled using C linkage instead of C++ linkage. This is
    necessary when creating a C++ library that needs to be used by a C program
    or a program written in another language that uses C linkage. In this case,
    the `entryPoint()` and `getType()` functions are declared as C functions
    that return a pointer to `ADisplay` and a character array, respectively.
    This allows the functions to be called from a C program or a program
    written in another language that uses C linkage. */
    extern "C" {
        /**
         * The function returns a pointer to an instance of the SFML class, which
         * is a display object.
         *
         * @return A pointer to an object of type `ADisplay` that is created using
         * the `new` operator and initialized with a `SFML` object.
         */
        ADisplay *entryPoint()
        {
            return new SFML();
        }

        /**
         * The function returns a string indicating the type of library used,
         * which is "libSFML".
         *
         * @return A string literal "libSFML" is being returned as a pointer to a
         * character array.
         */
        char *getType()
        {
            return (char *) "libSFML";
        }
    }
}
