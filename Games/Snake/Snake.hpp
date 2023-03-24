/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-arcade-roman.lopes
** File description:
** SnakeGame.hpp
*/

#ifndef SNAKEGAME_HPP_
	#define SNAKEGAME_HPP_

    #include "../../Abstract/AGame.hpp"

namespace Arcade {
    class SnakeGame : virtual public AGame {
        public:
            SnakeGame();
            void init();
            const std::vector<Drawable> &getDrawable();
            const std::map<char, std::string> &getAssets();
            void update(EventType key);
            void close();

            ~SnakeGame();
        private:
            std::map<char, std::string> _assets;
            std::vector<Drawable> _snake;
            std::vector<Drawable> _all;
            Drawable _apple;
            EventType _event;
            EventType _direction;
            int _score;
    };
}

#endif /*SNAKEGAME_HPP_*/
