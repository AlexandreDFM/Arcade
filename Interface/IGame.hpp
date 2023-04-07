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
    #include <fstream>
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
        virtual bool isRunning() const = 0;
        virtual const std::map<char, std::string> &getAssets() const = 0;
        virtual const std::vector<Drawable> &getDrawable() const = 0;
        virtual const std::vector<DrawableText> &getDrawableText() const = 0;
        virtual MenuInfo getMenuInfo(void) const = 0;
        //////////////////////// Setters //////////////////////////
        virtual void setMenuInfo(MenuInfo menuInfo) = 0;
        virtual void setIsRunning(bool isRunning) = 0;
    };
}

#endif //ARKADE_IGAME_HPP
