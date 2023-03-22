/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-arcade-roman.lopes
** File description:
** IDisplay.hpp
*/

#ifndef ARKADE_IGRAPHIC_HPP
    #define ARKADE_IGRAPHIC_HPP

    #include <ios>
    #include <iostream>
    #include "../struct.hpp"

namespace Arcade {
    class IDisplay {
        public:
            virtual ~IDisplay() = default;
            //////////////////////// Functions ////////////////////////
            virtual void init() = 0;
            virtual void update() = 0;
            virtual void close() = 0;
            virtual void stop() = 0;
            //////////////////////// Creators /////////////////////////
            virtual void createText() = 0;
            virtual void createSprite() = 0;
            //////////////////////// Getters //////////////////////////
            virtual int getEvent() = 0;
            virtual bool getIsRunning() const = 0;
            //////////////////////// Setters //////////////////////////
            virtual void setIsRunning(bool isRunning) = 0;
            //////////////////////// Drawers //////////////////////////
            virtual void display(std::vector<drawableText>) = 0;
            virtual void display(std::vector<drawable>) = 0;
    };
}

#endif //ARKADE_IGRAPHIC_HPP
