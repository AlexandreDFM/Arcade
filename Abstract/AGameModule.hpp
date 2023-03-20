/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-arcade-roman.lopes
** File description:
** AGameModule.hpp
*/

#ifndef AGAMEMODULE_HPP_
	#define AGAMEMODULE_HPP_

    #include "../Interface/IGame.hpp"

class AGameModule : virtual public IGame {
	public:
		AGameModule();
		~AGameModule();
};

#endif /*AGAMEMODULE_HPP_*/
