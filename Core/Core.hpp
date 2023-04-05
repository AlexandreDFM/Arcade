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
            //////////////////////// Functions ////////////////////////
            void loop();
            void changeLib(EventType event);
        private:
            IDisplay *graphic;
            IGame *game;
            DLLoader *gameDll;
            DLLoader *graphicDll;
    };
}

#endif /* !CORE_HPP_ */
