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
            ~SnakeGame() override = default;
            void init() override;
            const std::vector<Drawable> &getDrawable() override;
            const std::map<char, std::string> &getAssets() override;
            void update(EventType key);
            Arcade::EventType getDirection() override;
            void close() override;
        private:
            std::map<char, std::string> _assets;
            std::vector<Drawable> _snake;
            std::vector<Drawable> _all;
            std::vector<Drawable> _wall;
            Drawable _apple;
            EventType _event;
            EventType _direction;
            int _score;
    };
}
#endif /*SNAKEGAME_HPP_*/
