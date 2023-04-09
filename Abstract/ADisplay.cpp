/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-arcade-roman.lopes
** File description:
** ADisplay.cpp
*/

#include "ADisplay.hpp"

namespace Arcade {
    /**
     * This is the constructor for the ADisplay class in C++.
     */
    ADisplay::ADisplay()
    {
    }

    /**
     * This is the destructor for the ADisplay class in C++.
     */
    ADisplay::~ADisplay()
    {
    }

    /**
     * The function "init" initializes the game assets.
     *
     * @param gameAssets gameAssets is a constant reference to a std::map object
     * that maps characters to strings. It is likely used to store and retrieve
     * game assets such as images or sounds associated with specific characters in
     * the game. However, in the given code snippet, the parameter is not used and
     * is simply cast to void
     */
    void ADisplay::init(const std::map<char, std::string>& gameAssets)
    {
        (void) gameAssets;
    }

    /**
     * This is an empty implementation of the update function in the ADisplay
     * class.
     */
    void ADisplay::update()
    {
    }

    /**
     * The function "clear" in the ADisplay class is empty and does not contain
     * any code.
     */
    void ADisplay::clear()
    {
    }

    /**
     * The function "close" in the ADisplay class has an empty body.
     */
    void ADisplay::close()
    {
    }

    /**
     * The function "display" takes a vector of Drawable objects as input and does
     * nothing with it.
     *
     * @param drawables The parameter "drawables" is a vector of objects of type
     * "Drawable". It is passed as an argument to the member function "display" of
     * the class "ADisplay". The function does not use this parameter and simply
     * casts it to void, indicating that it is not being used in the function
     */
    void ADisplay::display(std::vector<Drawable> drawables)
    {
        (void) drawables;
    }

    /**
     * The function "display" takes in a vector of DrawableText objects and does
     * nothing with it.
     *
     * @param drawables The parameter "drawables" is a vector of objects of type
     * "DrawableText". It is passed as an argument to the member function
     * "display" of the class "ADisplay". The function does not use this parameter
     * and simply casts it to void, indicating that it is not being used in the
     */
    void ADisplay::display(std::vector<DrawableText> drawables)
    {
        (void) drawables;
    }

    /**
     * The function returns an Arcade event type of "NOTHING".
     *
     * @return an Arcade::EventType value of NOTHING.
     */
    Arcade::EventType ADisplay::getEvent()
    {
        return Arcade::EventType::NOTHING;
    }
}
