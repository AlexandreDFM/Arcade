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

    void SDL2::init()
    {
        // Init SDL
        if (SDL_Init(SDL_INIT_VIDEO) != 0) {
            std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl; return;
        }
        // Create window
        _window = SDL_CreateWindow("Arcade", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
        if (_window == nullptr) {
            std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl; return;
        }
        // Create renderer
        _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        if (_renderer == nullptr) {
            std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl; return;
        }
    }

    int SDL2::getEvent()
    {
        // Event handler
        // SDL_Event e;
        // Handle events on queue
        // SDL_PollEvent(&e);
        return 1;
    }

    void SDL2::update()
    {
        // Clear screen
        SDL_RenderClear(_renderer);
        // Update screen
        SDL_RenderPresent(_renderer);
    }

    void SDL2::drawText(std::string text, int x, int y)
    {
    }

    void SDL2::drawSprite(void *spt)
    {
        // Create texture
        SDL_Texture *texture = SDL_CreateTextureFromSurface(_renderer, (SDL_Surface *)spt);
        if (texture == nullptr) {
            std::cerr << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl; return;
        }
        // Create rect
        SDL_Rect rect = {0, 0, ((SDL_Surface *)spt)->w, ((SDL_Surface *)spt)->h};
        // Draw sprite
        SDL_RenderCopy(_renderer, texture, nullptr, &rect);
        // Free texture
        SDL_DestroyTexture(texture);
    }

    void SDL2::drawBackground(void *bkg)
    {
        // Create texture
        SDL_Texture *texture = SDL_CreateTextureFromSurface(_renderer, (SDL_Surface *)bkg);
        if (texture == nullptr) {
            std::cerr << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl; return;
        }
        // Create rect
        SDL_Rect rect = {0, 0, ((SDL_Surface *)bkg)->w, ((SDL_Surface *)bkg)->h};
        // Draw background
        SDL_RenderCopy(_renderer, texture, nullptr, &rect);
        // Free texture
        SDL_DestroyTexture(texture);
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
}
