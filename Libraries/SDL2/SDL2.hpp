/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-arcade-roman.lopes
** File description:
** SDL2.hpp
*/

#ifndef SDL2_HPP_
	#define SDL2_HPP_

    #include <SDL2/SDL.h>
    #include <SDL2/SDL_ttf.h>
    #include <SDL2/SDL_image.h>
    #include "../../Abstract/ADisplay.hpp"

namespace Arcade {
    class SDL2 : public ADisplay {
        public:
            /////////////////////// Constructors //////////////////////
            SDL2();
            ~SDL2();
            //////////////////////// Functions ////////////////////////
            void init(const std::map<char, std::string> &gameAssets) override;
            void update() override;
            void close() override;
            void display(std::vector<Drawable>) override;
            void display(std::vector<DrawableText>) override;
            //////////////////////// Getters //////////////////////////
            Arcade::EventType getEvent() override;
        private:
            SDL_Window *_window;
            SDL_Renderer *_renderer;
            SDL_Event _event;
            TTF_Font *_font;
            std::map<char, SDL_Texture *> _spriteAssets;
    };
}

#endif /*SDL2_HPP_*/
