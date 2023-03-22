/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-arcade-roman.lopes
** File description:
** Created by victor delamonica et dieu
*/

#ifndef ARKADE_IGAME_HPP
    #define ARKADE_IGAME_HPP

    #include <map>
    #include <string>
    #include <vector>
    #include <fstream>
    #include <iostream>
    #include <filesystem>
    #include "../struct.hpp"
namespace Arcade {
    class IGame {
        public:
            virtual ~IGame() = default;
            //////////////////////// Functions ////////////////////////
            virtual void init() = 0;
            virtual void update() = 0;
            virtual void close() = 0;
            //////////////////////// Creators /////////////////////////

            //////////////////////// Getters //////////////////////////
            virtual bool getIsRunning() = 0;
            //////////////////////// Setters //////////////////////////
            virtual bool setIsRunning() = 0;
            //////////////////////// Handlers /////////////////////////
            virtual int handleEvent(int event) = 0;

            virtual const std::map<char, std::string> &getassets() = 0;
            virtual const std::vector<drawable> &getDrawable() = 0;
            virtual const std::vector<drawableText> &getDrawableText() = 0;
    };
}

#endif //ARKADE_IGAME_HPP
