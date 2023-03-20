/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-arcade-roman.lopes
** File description:
** SDL2.hpp
*/

#ifndef SDL2_HPP_
	#define SDL2_HPP_

#include "IGraphic.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

class SDL2 : public IGraphic {
	public:
		SDL2();
		~SDL2();
        init();
        int getEvent();
        void update();
        void drawText(std::string text, int x, int y);
        void drawSprite(void *spt);
        void drawBackground(void *bkg);
        void close();
	private:
        SDL_Window *_window;
        SDL_Renderer *_renderer;
        TTF_Font *_font;
};

#endif /*SDL2_HPP_*/
