/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-arcade-roman.lopes
** File description:
** AGame.hpp
*/

#ifndef AGAMEMODULE_HPP_
	#define AGAMEMODULE_HPP_

    #include "../Interface/IGame.hpp"

namespace Arcade {
    class AGame : virtual public IGame {
        public:
            /////////////////////// Constructors //////////////////////
            AGame();
            ~AGame() override = default;
            //////////////////////// Functions ////////////////////////
            void init() override;
            void update() override;
            void close() override;
            //////////////////////// Getters //////////////////////////
            //////////////////////// Setters //////////////////////////
            //////////////////////// Handlers /////////////////////////
            //////////////////////// Creators /////////////////////////
    private:
    };
}

#endif /*AGAMEMODULE_HPP_*/
