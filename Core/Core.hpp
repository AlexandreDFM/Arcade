/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-arcade-roman.lopes
** File description:
** Core
*/

#ifndef CORE_HPP_
    #define CORE_HPP_

    #include "../Interface/IGame.hpp"
    #include "../DLLoader/DLLoader.hpp"
    #include "../Interface/IDisplay.hpp"

namespace Arcade {
    class Core {
        public:
            //////////////////////// Constructor ////////////////////////
            Core();
            Core(std::string lib);
            Core(std::string lib, std::string game);
            ~Core();
            //////////////////////// Setter ////////////////////////
            void setGraphic(IDisplay *graphic);
            void setGame(IGame *game);
            void setMenu();
            void setChangeLib(EventType event);
            void setChangeGame(EventType event);
            //////////////////////// Functions ////////////////////////
            void loop();
            void MenuGetChange();
            void changeLib(std::string lib);
            void changeGame(std::string game);
        private:
            size_t _indexLib;
            size_t _indexGame;
            MenuInfo _menuInfo;
            IGame *game;
            IDisplay *graphic;
            DLLoader *gameDll;
            DLLoader *graphicDll;
            std::vector<std::string> _libs;
            std::vector<std::string> _games;
    };
}

#endif /* !CORE_HPP_ */
