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
        private:
            size_t _index;
            bool _isUsernameSet;
            std::string _username;
            int _alphabetIndex;
            std::vector<std::string> _alphabet;
            std::pair<std::string, std::string> _selectedLib;
            std::pair<std::string, std::string> _selectedGame;
            std::vector<std::pair<std::string, std::string>> _libs;
            std::vector<std::pair<std::string, std::string>> _games;
    };
}

#endif /* !MENU_HPP_ */
