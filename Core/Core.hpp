/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-arcade-roman.lopes
** File description:
** Core
*/

#ifndef CORE_HPP_
    #define CORE_HPP_

    #include "../Interface/IGame.hpp"
    #include "../Interface/IDisplay.hpp"

namespace Arcade {
    class Core {
        public:
            Core();
            ~Core();
            void loop();
        private:
            IDisplay *display;
            IGame *game;
    };
}

#endif /* !CORE_HPP_ */
