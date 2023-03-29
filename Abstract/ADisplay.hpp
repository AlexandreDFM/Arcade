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
            void init(const std::map<char, std::string>& gameAssets) override;
            void update() override;
            void close() override;
            void display(std::vector<Drawable>) override;
            void display(std::vector<DrawableText>) override;
            //////////////////////// Getters //////////////////////////
            Arcade::EventType getEvent() override;
            //////////////////////// Setters //////////////////////////
        protected:
            bool _isRunning;
            std::map<char, std::string> _assets;
    };
}


#endif /*ADISPLAYMODULE_HPP_*/
