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
            ~NibblerGame();
    };
}

#endif /*NIBBLERGAME_HPP_*/
