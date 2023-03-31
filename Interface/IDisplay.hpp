/*
** EPITECH PROJECT, 2026
** Arkade
** File description:
** Created by victor delamonica et dieu
*/

#ifndef ARKADE_IGRAPHIC_HPP
    #define ARKADE_IGRAPHIC_HPP

    #include "Struct.hpp"

#include <ios>
#include <iostream>
#include <vector>
#include <map>
#include "Struct.hpp"

namespace Arcade {
    class IDisplay {
    public:
        virtual ~IDisplay() = default;
        //////////////////////// Functions ////////////////////////
        virtual void init(const std::map<char, std::string>& gameAssets) = 0;
        virtual void update() = 0;
        virtual void close() = 0;
        virtual void display(std::vector<Drawable> drawables) = 0;
        virtual void display(std::vector<DrawableText> drawables) = 0;
        //////////////////////// Getters //////////////////////////
        virtual Arcade::EventType getEvent() = 0;
        //////////////////////// Setters //////////////////////////
    };
}

#endif //ARKADE_IGRAPHIC_HPP
