/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-arcade-roman.lopes
** File description:
** SDL2.cpp
*/

#include "SDL2.hpp"

namespace Arcade {
    /**
     * This is a constructor for a class called SDL2 with no parameters.
     */
    SDL2::SDL2()
    {
    }

    /**
     * This function initializes SDL2 and loads game assets such as textures and
     * fonts.
     *
     * @param gameAssets gameAssets is a std::map that contains pairs of
     * characters and strings. The characters represent the keys for the sprite
     * assets, while the strings represent the file paths for the corresponding
     * sprite assets. These sprite assets are loaded into the program and stored
     * in the _spriteAssets member variable of the SDL2 class
     */
    void SDL2::init(const std::map<char, std::string> &gameAssets)
    {
        SDL_Init(SDL_INIT_VIDEO);
        IMG_Init(IMG_INIT_PNG);
        TTF_Init();
        this->_window = SDL_CreateWindow("Arcade", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1920, 1080,
        SDL_WINDOW_SHOWN);
        this->_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
        this->_font = TTF_OpenFont("./Assets/Police/Poppins-Black.ttf", 12);
        this->_event = SDL_Event();
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
        for (auto &asset: gameAssets) {
            SDL_Surface *surface = IMG_Load(asset.second.c_str());
            SDL_Texture *texture = SDL_CreateTextureFromSurface(_renderer, surface);
            SDL_FreeSurface(surface);
            this->_spriteAssets[asset.first] = texture;
        }
    }

    /**
     * This function updates the SDL2 renderer to present the rendered output.
     */
    void SDL2::update()
    {
        SDL_RenderPresent(_renderer);
    }

    /**
     * This function closes all SDL2 assets and quits the SDL2 library.
     */
    void SDL2::close()
    {
        for (auto &asset : this->_spriteAssets) SDL_DestroyTexture(asset.second);
        this->_spriteAssets.clear();
        SDL_DestroyRenderer(this->_renderer);
        TTF_CloseFont(this->_font);
        SDL_DestroyWindow(this->_window);
        TTF_Quit();
        IMG_Quit();
        SDL_Quit();
    }

    /**
     * This function displays a vector of drawable objects on an SDL2 renderer
     * with optional rotation.
     *
     * @param drawables A vector of Drawable objects that contain information
     * about what to draw and how to draw it on the screen.
     *
     * @return If the input vector `drawables` is empty, the function returns
     * without doing anything.
     */
    void SDL2::display(std::vector <Drawable> drawables)
    {
        if (drawables.empty()) return;
        for (auto &drawable : drawables) {
            SDL_Rect rect = {drawable.rect.left, drawable.rect.top, drawable.rect.width, drawable.rect.height};
            SDL_Rect pos = {drawable.x * this->_spriteSize, drawable.y * this->_spriteSize, drawable.rect.width, drawable.rect.height};
            if (drawable.draw != 'h' && drawable.draw != 'b') {
                SDL_RenderCopy(_renderer, _spriteAssets[drawable.draw], &rect, &pos); continue;
            }
            SDL_Point rotation_point = { drawable.rect.width / 2, drawable.rect.height / 2 };
            switch (drawable.rotation) {
                case Direction::NO_DIRECTION: SDL_RenderCopy(_renderer, _spriteAssets[drawable.draw], &rect, &pos); break;
                case Direction::WEST:         SDL_RenderCopyEx(_renderer, _spriteAssets[drawable.draw], &rect, &pos, 0, &rotation_point, SDL_FLIP_NONE); break;
                case Direction::EAST:         SDL_RenderCopyEx(_renderer, _spriteAssets[drawable.draw], &rect, &pos, 180, &rotation_point, SDL_FLIP_NONE); break;
                case Direction::NORTH:        SDL_RenderCopyEx(_renderer, _spriteAssets[drawable.draw], &rect, &pos, 90, &rotation_point, SDL_FLIP_NONE); break;
                case Direction::SOUTH:        SDL_RenderCopyEx(_renderer, _spriteAssets[drawable.draw], &rect, &pos, 270, &rotation_point, SDL_FLIP_NONE); break;
            }
        }
    }

    /**
     * The function displays a vector of DrawableText objects on an SDL2 window.
     *
     * @param drawables A vector of DrawableText objects that contain information
     * about the text to be displayed, including the text string, position, size,
     * and color.
     *
     * @return If the `drawables` vector is empty, the function returns without
     * doing anything. Otherwise, the function displays the text in each
     * `DrawableText` object in the vector on the SDL window.
     */
    void SDL2::display(std::vector <DrawableText> drawables)
    {
        if (drawables.empty()) return;
        for (auto &drawable : drawables) {
            SDL_Color color = {255, 255, 255, 255};
            SDL_Rect size = {0, 0, (int) drawable.text.length() * drawable.size, drawable.size * 2};
            SDL_Rect pos = {drawable.x * this->_spriteSize, drawable.y * this->_spriteSize, (int) drawable.text.length() * drawable.size, drawable.size * 2};
            switch (drawable.color) {
                case Color::BLACK:   color = {0, 0, 0, 255};         break;
                case Color::RED:     color = {255, 0, 0, 255};       break;
                case Color::BLUE:    color = {0, 0, 255, 255};       break;
                case Color::GREEN:   color = {0, 255, 0, 255};       break;
                case Color::CYAN:    color = {0, 255, 255, 255};     break;
                case Color::YELLOW:  color = {255, 255, 0, 255};     break;
                case Color::MAGENTA: color = {255, 0, 255, 255};     break;
                case Color::WHITE:   color = {255, 255, 255, 255};   break;
                default:                                             break;
            }
            SDL_Surface *surface = TTF_RenderText_Solid(_font, drawable.text.c_str(), color);
            SDL_Texture *texture = SDL_CreateTextureFromSurface(_renderer, surface);
            SDL_RenderCopy(_renderer, texture, &size, &pos);
            SDL_FreeSurface(surface);
            SDL_DestroyTexture(texture);
        }
    }

    /**
     * This function clears the renderer in SDL2.
     */
    void SDL2::clear()
    {
        SDL_RenderClear(_renderer);
    }

    /**
     * This function returns the corresponding Arcade event type based on the SDL2
     * event type.
     *
     * @return an Arcade::EventType enum value based on the SDL2 event that was
     * polled. The possible return values are CLOSE, RESTART, RIGHT, LEFT, DOWN,
     * UP, LIBPREV, LIBNEXT, GAMEPREV, GAMENEXT, ACTION1, ACTION2, SAVE, MENU, or
     * NOTHING.
     */
    Arcade::EventType SDL2::getEvent()
    {
        if (SDL_PollEvent(&_event)) {
            switch (_event.type) {
                case SDL_QUIT:
                    return Arcade::EventType::CLOSE;
                case SDL_KEYDOWN:
                    switch (_event.key.keysym.sym) {
                        case SDLK_ESCAPE: return Arcade::EventType::CLOSE;
                        case SDLK_SPACE:  return Arcade::EventType::RESTART;
                        case SDLK_RIGHT:  return Arcade::EventType::RIGHT;
                        case SDLK_LEFT:   return Arcade::EventType::LEFT;
                        case SDLK_DOWN:   return Arcade::EventType::DOWN;
                        case SDLK_UP:     return Arcade::EventType::UP;
                        case SDLK_l:      return Arcade::EventType::LIBPREV;
                        case SDLK_m:      return Arcade::EventType::LIBNEXT;
                        case SDLK_o:      return Arcade::EventType::GAMEPREV;
                        case SDLK_p:      return Arcade::EventType::GAMENEXT;
                        case SDLK_e:      return Arcade::EventType::ACTION1;
                        case SDLK_r:      return Arcade::EventType::ACTION2;
                        case SDLK_t:      return Arcade::EventType::SAVE;
                        case SDLK_y:      return Arcade::EventType::MENU;
                        default:          return Arcade::EventType::NOTHING;
                    }
                default: return Arcade::EventType::NOTHING;
            }
        }
        return Arcade::EventType::NOTHING;
    }

    /* The `extern "C"` block is used to specify that the functions inside it
    should be compiled using C linkage instead of C++ linkage. This is
    necessary when creating a C++ library that needs to be used by a C program
    or by a program written in another language that uses C linkage. In this
    case, the `entryPoint()` and `getType()` functions are defined inside the
    `extern "C"` block to ensure that they are compiled using C linkage. */
    extern "C" {
        /**
         * The function returns a new instance of the SDL2 class that implements
         * the IDisplay interface.
         *
         * @return A pointer to an instance of the SDL2 class is being returned.
         */
        IDisplay *entryPoint()
        {
            return new SDL2();
        }

        /**
         * The function returns a string indicating the type of library as
         * "libSDL2".
         *
         * @return A string literal "libSDL2" is being returned as a pointer to a
         * character array.
         */
        char *getType()
        {
            return (char *) "libSDL2";
        }
    }
}
