/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-arcade-roman.lopes
** File description:
** IGame.hpp
*/

#ifndef ARKADE_IGAME_HPP
    #define ARKADE_IGAME_HPP

class IGame {
    public:
        virtual void init() = 0;
        virtual int handleEvent(int event) = 0;
        virtual void update() = 0;
        virtual bool getIsRunning() = 0;
        virtual bool setIsRunning() = 0;
        virtual void close() = 0;
};

#endif //ARKADE_IGAME_HPP
