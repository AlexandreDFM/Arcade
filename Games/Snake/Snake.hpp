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
            void update(EventType event) override;
            void placeApple();
            const std::vector<Drawable> &getDrawable() override;
            const std::vector<DrawableText> &getDrawableText() override;
            const std::map<char, std::string> &getAssets() override;
            Arcade::EventType getDirection() override;
            void close() override;
        private:
            int _score;
            int _highScore;
            Drawable _apple;
            EventType _event;
            EventType _direction;
            std::vector<Drawable> _all;
            std::vector<Drawable> _wall;
            std::vector<Drawable> _snake;
            std::vector<DrawableText> _text;
            std::map<char, std::string> _assets;
    };
}
#endif /*SNAKEGAME_HPP_*/
