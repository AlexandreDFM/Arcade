/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-arcade-roman.lopes
** File description:
** NibblerGame.hpp
*/

#ifndef NIBBLERGAME_HPP_
	#define NIBBLERGAME_HPP_

    #include "../../Abstract/AGame.hpp"

namespace Arcade {
    class NibblerGame : virtual public AGame {
        public:
            NibblerGame();
            ~NibblerGame() override = default;
            void init() override;
            void update(EventType key) override;
            void checkWall(EventType key);
            void setHighScore();
            void setMap(int i);
            void save();
            void loadSave();
            void moveSnakeBody(Direction rotation);
            void checkApple();
            void movements();
            void close() override;
            void reset();
        private:
            int _score;
            float _speed;
            bool _isStart;
            int _highScore;
            int _spriteSize;
            bool _pushATail;
            Drawable _apple;
            size_t _mapIndex;
            EventType _direction;
            std::vector<Drawable> _wall;
            std::vector<Drawable> _snake;
            std::vector<Drawable> _apples;
    };
}

#endif /*NIBBLERGAME_HPP_*/
