/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-arcade-roman.lopes
** File description:
** AGame.hpp
*/

#ifndef AGAMEMODULE_HPP_
	#define AGAMEMODULE_HPP_

    #include "../Interface/IGame.hpp"

namespace Arcade {
    class AGame : virtual public IGame {
        public:
            AGame();
            ~AGame() override = default;
            //////////////////////// Functions ////////////////////////
            void init() override;
            void update() override;
            void close() override;
            //////////////////////// Handlers /////////////////////////
            int handleEvent(int event) override;
            //////////////////////// Getters //////////////////////////
            bool isRunning() override;
            const std::vector<Drawable> &getDrawable() override;
            const std::map<char, std::string> &getAssets() override;
            const std::vector<DrawableText> &getDrawableText() override;
            Arcade::EventType getDirection() override;
            //////////////////////// Setters //////////////////////////
            void setIsRunning() override;
    protected:
        bool _isRunning;
        std::map<char, std::string> _assets;
        std::vector<Drawable> _drawable;
        std::vector<DrawableText> _drawableText;
    };
}

#endif /*AGAMEMODULE_HPP_*/
