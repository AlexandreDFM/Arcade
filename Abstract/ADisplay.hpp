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
            /////////////////////// Constructors //////////////////////
            ADisplay();
            ~ADisplay() override;
            //////////////////////// Functions ////////////////////////
            void init() override;
            void update() override;
            void close() override;
            void stop() override;
            //////////////////////// Creators /////////////////////////
            void createText() override;
            void createSprite() override;
            //////////////////////// Getters //////////////////////////
            int getEvent() override;
            bool getIsRunning() const override;
            //////////////////////// Setters //////////////////////////
            void setIsRunning(bool isRunning) override;
            //////////////////////// Drawers //////////////////////////
            void drawSprite(void *spt) override;
            void drawBackground(void *bkg) override;
            void drawText(std::string text, int x, int y) override;
        private:
            bool _isRunning;
    };
}

extern "C" Arcade::ADisplay *create_display_module() {
    return new Arcade::ADisplay();
}


#endif /*ADISPLAYMODULE_HPP_*/
