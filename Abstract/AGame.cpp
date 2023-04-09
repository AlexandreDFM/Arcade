/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-arcade-roman.lopes
** File description:
** AGame.cpp
*/

#include "AGame.hpp"

namespace Arcade {
    /**
     * This is the constructor for the AGame class, which initializes several
     * member variables.
     */
    AGame::AGame()
    {
        _isRunning = true;
        _drawable = std::vector<Drawable>();
        _assets = std::map<char, std::string>();
        _drawableText = std::vector<DrawableText>();
    }

    /**
     * This is an empty initialization function for a C++ game.
     */
    void AGame::init()
    {
    }

    /**
     * The function "update" in the AGame class takes an EventType parameter and
     * does nothing with it.
     *
     * @param event The parameter "event" is of type Arcade::EventType and is
     * being passed to the update function of the AGame class. However, the
     * function body does not use this parameter and simply casts it to void,
     * indicating that it is not being used in the function.
     */
    void AGame::update(Arcade::EventType event)
    {
        (void) event;
    }

    /**
     * The function "close" is defined within the AGame class, but it does not
     * contain any code.
     */
    void AGame::close()
    {
    }

    /**
     * The function returns a boolean value indicating whether the game is
     * currently running or not.
     *
     * @return The function `isRunning()` is returning the value of the private
     * member variable `_isRunning`.
     */
    bool AGame::isRunning() const
    {
        return _isRunning;
    }

    /**
     * This function returns a constant reference to a vector of Drawable objects
     * in a C++ game.
     *
     * @return A constant reference to a vector of Drawable objects named
     * `_drawable`.
     */
    const std::vector<Drawable> &AGame::getDrawable() const
    {
        return _drawable;
    }

    /**
     * This function returns a constant reference to a map of characters and
     * strings representing game assets.
     *
     * @return A constant reference to a `std::map` object with `char` keys and
     * `std::string` values, named `_assets`.
     */
    const std::map<char, std::string> &AGame::getAssets() const
    {
        return _assets;
    }

    /**
     * This function returns a constant reference to a vector of DrawableText
     * objects in an AGame class.
     *
     * @return A constant reference to a vector of `DrawableText` objects named
     * `_drawableText`.
     */
    const std::vector<DrawableText> &AGame::getDrawableText() const
    {
        return _drawableText;
    }

    /**
     * The function sets the menu information for a game.
     *
     * @param menuInfo `menuInfo` is an object of the `MenuInfo` class that
     * contains information about the game menu. This function `setMenuInfo` takes
     * a `MenuInfo` object as a parameter and sets the `_menuInfo` member variable
     * of the `AGame` class to the passed `menu
     */
    void AGame::setMenuInfo(MenuInfo menuInfo)
    {
        _menuInfo = menuInfo;
    }

    /**
     * This function sets the value of a boolean variable called "_isRunning".
     *
     * @param isRunning isRunning is a boolean parameter that represents the new
     * value to be set for the private member variable _isRunning. If isRunning is
     * true, it means the game is running, and if it is false, it means the game
     * is not running.
     */
    void AGame::setIsRunning(bool isRunning)
    {
        _isRunning = isRunning;
    }

    /**
     * The function returns the menu information of a game.
     *
     * @return The function `getMenuInfo` is returning the `_menuInfo` object of
     * type `MenuInfo`.
     */
    MenuInfo AGame::getMenuInfo(void) const
    {
        return _menuInfo;
    }
}
