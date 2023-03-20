/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-arcade-roman.lopes
** File description:
** SDL2.cpp
*/

#include "SDL2.hpp"

SDL2::SDL2()
{
}

SDL2::~SDL2() {
}

SDL2::init() {
    // Init SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }
    // Init SDL_image
    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
        std::cerr << "SDL_image Error: " << IMG_GetError() << std::endl; return 1;
    }
    // Init SDL_ttf
    if (TTF_Init() == -1) {
        std::cerr << "SDL_ttf Error: " << TTF_GetError() << std::endl; return 1;
    }
    // Create window
    _window = SDL_CreateWindow("Arcade", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    if (_window == nullptr) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        return 1;
    }
    // Create renderer
    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (_renderer == nullptr) {
        std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        return 1;
    }
    // Set renderer color
    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
    // Load font
    _font = TTF_OpenFont("assets/arial.ttf", 24);
    if (_font == nullptr) {
        std::cerr << "TTF_OpenFont Error: " << TTF_GetError() << std::endl;
        return 1;
    }
}

int SDL2::getEvent() {
    // Event handler
    SDL_Event e;
    // Handle events on queue
    SDL_PollEvent(&e)
    return e;
}

void SDL2::update() {
    // Clear screen
    SDL_RenderClear(_renderer);
    // Update screen
    SDL_RenderPresent(_renderer);
}

void SDL2::drawText(std::string text, int x, int y) {
    // Create surface
    SDL_Surface *surface = TTF_RenderText_Solid(_font, text.c_str(), {255, 255, 255, 255});
    if (surface == nullptr) {
        std::cerr << "TTF_RenderText_Solid Error: " << TTF_GetError() << std::endl;
        return;
    }
    // Create texture
    SDL_Texture *texture = SDL_CreateTextureFromSurface(_renderer, surface);
    if (texture == nullptr) {
        std::cerr << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
        return;
    }
    // Create rect
    SDL_Rect rect = {x, y, surface->w, surface->h};
    // Draw text
    SDL_RenderCopy(_renderer, texture, NULL, &rect);
    // Free surface
    SDL_FreeSurface(surface);
    // Free texture
    SDL_DestroyTexture(texture);
}

void SDL2::drawSprite(void *spt) {
    // Create texture
    SDL_Texture *texture = SDL_CreateTextureFromSurface(_renderer, (SDL_Surface *)spt);
    if (texture == nullptr) {
        std::cerr << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
        return;
    }
    // Create rect
    SDL_Rect rect = {0, 0, ((SDL_Surface *)spt)->w, ((SDL_Surface *)spt)->h};
    // Draw sprite
    SDL_RenderCopy(_renderer, texture, NULL, &rect);
    // Free texture
    SDL_DestroyTexture(texture);
}

void SDL2::drawBackground(void *bkg) {
    // Create texture
    SDL_Texture *texture = SDL_CreateTextureFromSurface(_renderer, (SDL_Surface *)bkg);
    if (texture == nullptr) {
        std::cerr << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
        return;
    }
    // Create rect
    SDL_Rect rect = {0, 0, ((SDL_Surface *)bkg)->w, ((SDL_Surface *)bkg)->h};
    // Draw background
    SDL_RenderCopy(_renderer, texture, NULL, &rect);
    // Free texture
    SDL_DestroyTexture(texture);
}

void SDL2::close() {
    // Destroy window
    SDL_DestroyWindow(_window);
    // Destroy renderer
    SDL_DestroyRenderer(_renderer);
    // Destroy font
    TTF_CloseFont(_font);
    // Quit SDL_ttf
    TTF_Quit();
    // Quit SDL_image
    IMG_Quit();
    // Quit SDL
    SDL_Quit();
}
