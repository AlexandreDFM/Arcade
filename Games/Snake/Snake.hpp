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
            void moveSnakeBody(Direction rotation);
            void placeApple();
            void setHighScoreInFile();
            void getHighScoreFromFile();
            void getSpriteSizeFromFile();
            void save();
            void loadSave();
            void deleteSave();
            void setMap();
            void close() override;
        private:
            int _score;
            float _speed;
            bool _isStart;
            int _highScore;
            int _spriteSize;
            bool _pushATail;
            Drawable _apple;
            EventType _direction;
            std::vector<Drawable> _wall;
            std::vector<Drawable> _snake;
    };
}
#endif /*SNAKEGAME_HPP_*/
