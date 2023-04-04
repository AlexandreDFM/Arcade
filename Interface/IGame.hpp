/*
** EPITECH PROJECT, 2026
** Arkade
** File description:
** Created by victor delamonica et dieu
*/

#ifndef ARKADE_IGAME_HPP
    #define ARKADE_IGAME_HPP

    #include <map>
    #include <vector>
    #include <chrono>
    #include "Struct.hpp"

namespace Arcade {
    class IGame {
    public:
        virtual ~IGame() = default;
        //////////////////////// Functions ////////////////////////
        virtual void init() = 0;
        virtual void update(Arcade::EventType event) = 0;
        virtual void close() = 0;
        //////////////////////// Getters //////////////////////////
        virtual bool isRunning() = 0;
        virtual const std::map<char, std::string> &getAssets() = 0;
        virtual const std::vector<Drawable> &getDrawable() = 0;
        virtual const std::vector<DrawableText> &getDrawableText() = 0;
        virtual Arcade::EventType getDirection() = 0;
        //////////////////////// Setters //////////////////////////
        virtual void setIsRunning(bool isRunning) = 0;
    };
}

#endif //ARKADE_IGAME_HPP
