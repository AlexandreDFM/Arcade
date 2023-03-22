/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-arcade-roman.lopes
** File description:
** Menu
*/

#ifndef MENU_HPP_
    #define MENU_HPP_

    #include "../Abstract/AGame.hpp"

namespace Arcade {
    class Menu : virtual public AGame {
        public:
            //////////////////////// Functions ////////////////////////
            void init() override;
            void update() override;
            void close() override;

            //////////////////////// Getters //////////////////////////
            bool getIsRunning() override;

            //////////////////////// Setters //////////////////////////
            bool setIsRunning() override;

            //////////////////////// Drawers //////////////////////////


            int handleEvent(int event) override;
            std::vector <std::string> getLib();
            std::vector <std::string> getGame();
            const std::map<char, std::string> &getassets();
        private:
            std::vector <std::string> _liblist;
            std::vector <std::string> _gamelist;
    };
}

#endif /* !MENU_HPP_ */
