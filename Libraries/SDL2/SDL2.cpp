/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-arcade-roman.lopes
** File description:
** SDL2.cpp
*/

#include "SDL2.hpp"

namespace Arcade {
    SDL2::SDL2()
    {
    }

    void SDL2::init(const std::map<char, std::string> &gameAssets)
    {
        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
            std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl; exit(84);
        }
        if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
            std::cerr << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << std::endl; exit(84);
        }
        if (TTF_Init() == -1) {
            std::cerr << "SDL_ttf could not initialize! SDL_ttf Error: " << TTF_GetError() << std::endl; exit(84);
        }
        this->_window = SDL_CreateWindow("Arcade", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1920, 1080,
        SDL_WINDOW_SHOWN);
        if (_window == nullptr) {
            std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl; exit(84);
        }
        this->_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
        if (_renderer == nullptr) {
            std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
            exit(84);
        }
        this->_font = TTF_OpenFont("./Assets/Police/Poppins-Black.ttf", 12);
        if (_font == nullptr) {
            std::cerr << "Font could not be created! SDL_ttf Error: " << TTF_GetError() << std::endl; exit(84);
        }
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

    void SDL2::update()
    {
        SDL_RenderPresent(_renderer);
    }

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

    void SDL2::clear()
    {
        SDL_RenderClear(_renderer);
    }

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

    extern "C" {
        IDisplay *entryPoint()
        {
            return new SDL2();
        }
        char *getType()
        {
            return (char *) "libSDL2";
        }
    }
}
