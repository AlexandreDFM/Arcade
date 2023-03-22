/*
** EPITECH PROJECT, 2026
** Arkade
** File description:
** Created by victor delamonica et dieu
*/

#ifndef ARKADE_IGRAPHIC_HPP
    #define ARKADE_IGRAPHIC_HPP

    #include "Struct.hpp"

namespace Arcade {
    class IDisplay {
        public:
            virtual ~IDisplay() = default;
            //////////////////////// Functions ////////////////////////
            virtual void init() = 0;
            virtual void update() = 0;
            virtual void close() = 0;
            virtual void display(std::vector<Drawable>) = 0;
            virtual void display(std::vector<DrawableText>) = 0;
            //////////////////////// Getters //////////////////////////
            virtual int getEvent() = 0;
            //////////////////////// Setters //////////////////////////
    };
}

#endif //ARKADE_IGRAPHIC_HPP
