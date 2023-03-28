/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-arcade-roman.lopes
** File description:
** ADisplay.hpp
*/

#ifndef ADISPLAYMODULE_HPP_
	#define ADISPLAYMODULE_HPP_

    #include "../Interface/IDisplay.hpp"

namespace Arcade {
    class ADisplay : public IDisplay {
        public:
            ADisplay();
            ~ADisplay() override;
            //////////////////////// Functions ////////////////////////
            void init() override;
            void update() override;
            void close() override;
            void display(std::vector<Drawable>) override;
            void display(std::vector<DrawableText>) override;
            //////////////////////// Getters //////////////////////////
            int getEvent() override;
            //////////////////////// Setters //////////////////////////
        private:
            bool _isRunning;
    };
}

extern "C" Arcade::ADisplay *create_display_module() {
    return new Arcade::ADisplay();
}


#endif /*ADISPLAYMODULE_HPP_*/
