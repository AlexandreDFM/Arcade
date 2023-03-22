/*
** EPITECH PROJECT, 2026
** Arkade
** File description:
** Created by victor delamonica et dieu
*/

#ifndef ARKADE_IGRAPHIC_HPP
#define ARKADE_IGRAPHIC_HPP

#include <ios>
#include <vector>
#include "../struct.hpp"

class IGraphic {
    public:
    virtual void init() = 0;
    virtual int getEvent() = 0;
    virtual void update() = 0;
    virtual void display(std::vector<drawableText>) = 0;
    virtual void display(std::vector<drawable>) = 0;
    virtual void close() = 0;
};

#endif //ARKADE_IGRAPHIC_HPP
