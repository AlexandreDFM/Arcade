/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-arcade-roman.lopes
** File description:
** IGraphic.hpp
*/

#ifndef ARKADE_IGRAPHIC_HPP
    #define ARKADE_IGRAPHIC_HPP

    #include <ios>
    #include <iostream>

class IGraphic {
    public:
        virtual void init() = 0;
        virtual int getEvent() = 0;
        virtual void update() = 0;
        virtual void drawText(std::string text, int x, int y) = 0;
        virtual void drawSprite(void *spt) = 0;
        virtual void drawBackground(void *bkg) = 0;
        virtual void close() = 0;
};

#endif //ARKADE_IGRAPHIC_HPP
