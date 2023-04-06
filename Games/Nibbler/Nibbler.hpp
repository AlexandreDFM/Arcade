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
            const std::vector<Drawable> &getDrawable() override;
            const std::vector<DrawableText> &getDrawableText() override;
            const std::map<char, std::string> &getAssets() override;
            Arcade::EventType getDirection() override;
            void setMap(int i);
            void checkApple();
            void bodyMove();
            void close() override;
            void reset();
        private:
            int _score;
            int _highScore;
            Drawable _apple;
            EventType _event;
            EventType _direction;
            std::vector<Drawable> _all;
            std::vector<Drawable> _wall;
            std::vector<Drawable> _snake;
            std::vector<Drawable> _apples;
            std::vector<DrawableText> _text;
            std::map<char, std::string> _assets;
    };
}

#endif /*NIBBLERGAME_HPP_*/
