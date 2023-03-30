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

    SDL2::~SDL2()
    {
    }

    void SDL2::init(const std::map<char, std::string> &gameAssets)
    {
           // Init SDL
            if (SDL_Init(SDL_INIT_VIDEO) < 0) {
                std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
                exit(84);
            }
            // Init SDL_image
            if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
                std::cerr << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << std::endl;
                exit(84);
            }
            // Init SDL_ttf
            if (TTF_Init() == -1) {
                std::cerr << "SDL_ttf could not initialize! SDL_ttf Error: " << TTF_GetError() << std::endl;
                exit(84);
            }
            // Create window
            _window = SDL_CreateWindow("Arcade", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1920, 1080, SDL_WINDOW_SHOWN);
            if (_window == nullptr) {
                std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
                exit(84);
            }
            // Create renderer
            _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
            if (_renderer == nullptr) {
                std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
                exit(84);
            }
            // Create font
            _font = TTF_OpenFont("Assets/Fonts/arial.ttf", 24);
            if (_font == nullptr) {
                std::cerr << "Font could not be created! SDL_ttf Error: " << TTF_GetError() << std::endl;
                exit(84);
            }
            // Load assets
            for (auto &asset : gameAssets) {
                SDL_Surface *surface = IMG_Load(asset.second.c_str());
                SDL_Texture *texture = SDL_CreateTextureFromSurface(_renderer, surface);
                SDL_FreeSurface(surface);
                _spriteAssets[asset.first] = texture;
            }
    }

    void SDL2::update()
    {
        // Clear screen
        SDL_RenderClear(_renderer);
        // Update screen
        SDL_RenderPresent(_renderer);
    }

    void SDL2::close()
    {
        // Destroy window
        SDL_DestroyWindow(_window);
        // Destroy renderer
        SDL_DestroyRenderer(_renderer);
        // Destroy font
    //    TTF_CloseFont(_font);
        // Quit SDL_ttf
    //    TTF_Quit();
        // Quit SDL_image
    //    IMG_Quit();
        // Quit SDL
        SDL_Quit();
    }

    void SDL2::display(std::vector<Drawable> drawables)
    {
        // Display SDL
        (void) drawables;
//        for (auto &drawable : drawables) {
//            SDL_Rect rect = {drawable.x, drawable.y, drawable.width, drawable.height};
//            SDL_SetRenderDrawColor(_renderer, drawable.color.r, drawable.color.g, drawable.color.b, drawable.color.a);
//            SDL_RenderFillRect(_renderer, &rect);
//        }
    }

    void SDL2::display(std::vector<DrawableText> drawables)
    {
        // Display SDL
        (void) drawables;
//        for (auto &drawable : drawables) {
//            SDL_Color color =
//            SDL_Surface *surface = TTF_RenderText_Solid(_font, drawable.text.c_str(), drawable.color);
//            SDL_Texture *texture = SDL_CreateTextureFromSurface(_renderer, surface);
//            SDL_Rect rect = {drawable.x, drawable.y, drawable.width, drawable.height};
//            SDL_RenderCopy(_renderer, texture, NULL, &rect);
//            SDL_FreeSurface(surface);
//            SDL_DestroyTexture(texture);
//        }
    }

    Arcade::EventType SDL2::getEvent()
    {
        // getEvent SDL
//        _event = SDL_PollEvent(&_event);
        if (_event.type == SDL_QUIT) {
            return Arcade::EventType::CLOSE;
        }
        return Arcade::EventType::NOTHING;
    }
}
