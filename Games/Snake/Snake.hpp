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
            ~SnakeGame();
    };
}

#endif /*SNAKEGAME_HPP_*/
