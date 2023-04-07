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
            void update(Arcade::EventType event) override;
            void close() override;
            //////////////////////// Getters //////////////////////////
            bool isRunning() const override;
            const std::vector<Drawable> &getDrawable() const override;
            const std::map<char, std::string> &getAssets() const override;
            const std::vector<DrawableText> &getDrawableText() const override;
            MenuInfo getMenuInfo(void) const override;
            //////////////////////// Setters //////////////////////////
            void setMenuInfo(MenuInfo menuInfo) override;
            void setIsRunning(bool isRunning) override;
        protected:
            bool _isRunning;
            MenuInfo _menuInfo;
            std::vector<Drawable> _drawable;
            std::map<char, std::string> _assets;
            std::vector<DrawableText> _drawableText;
    };
}

#endif /*AGAMEMODULE_HPP_*/
