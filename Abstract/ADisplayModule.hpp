/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-arcade-roman.lopes
** File description:
** ADisplayModule.hpp
*/

#ifndef ADISPLAYMODULE_HPP_
	#define ADISPLAYMODULE_HPP_

    #include "../Interface/IGraphic.hpp"

class ADisplayModule : virtual public IGraphic {
	public:
		ADisplayModule();
		~ADisplayModule();
};

#endif /*ADISPLAYMODULE_HPP_*/
