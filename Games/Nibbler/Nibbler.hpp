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
            void init();
            const std::vector<Drawable> &getDrawable();
            const std::map<char, std::string> &getAssets();
            void update(EventType key);
            void close();
            ~NibblerGame();
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

#endif /*NIBBLERGAME_HPP_*/
