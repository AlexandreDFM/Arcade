/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-arcade-roman.lopes
** File description:
** Menu
*/

#ifndef MENU_HPP_
    #define MENU_HPP_

    #include "../../Abstract/AGame.hpp"
    #include "../../DLLoader/DLLoader.hpp"
    #include "../../Interface/IDisplay.hpp"

namespace Arcade {
    class Menu : virtual public AGame {
        public:
            //////////////////////// Functions ////////////////////////
            void init() override;
            void update(Arcade::EventType event) override;
            void close() override;
            //////////////////////// Getters //////////////////////////
            bool isRunning() override;
            const std::vector<Drawable> &getDrawable() override;
            const std::map<char, std::string> &getAssets() override;
            const std::vector<DrawableText> &getDrawableText() override;
            Arcade::EventType getDirection() override;
            //////////////////////// Setters //////////////////////////
            void setIsRunning(bool isRunning) override;
        private:
            size_t _index;
            std::string _selectedLib;
            std::string _selectedGame;
            std::vector<std::string> _libs;
            std::vector<std::string> _games;
    };
}

#endif /* !MENU_HPP_ */
