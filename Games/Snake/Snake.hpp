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
    typedef struct vector2i_s {
        int x;
        int y;
    } vector2i_t;
    class SnakeGame : virtual public AGame {
        public:
            SnakeGame();
            ~SnakeGame() override = default;
            void init() override;
            void update(EventType event) override;
            void placeApple();
            void setHighScore();
            const std::vector<Drawable> &getDrawable() const override;
            const std::map<char, std::string> &getAssets() const override;
            const std::vector<DrawableText> &getDrawableText() const override;
            void setMap();
            void close() override;
        private:
            int _score;
            float _speed;
            int _highScore;
            Drawable _apple;
            EventType _direction;
            std::vector<Drawable> _all;
            std::vector<Drawable> _wall;
            std::vector<Drawable> _snake;
            std::vector<DrawableText> _text;
            std::map<char, std::string> _assets;
    };
}
#endif /*SNAKEGAME_HPP_*/
