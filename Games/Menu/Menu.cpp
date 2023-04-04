/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-arcade-roman.lopes
** File description:
** Menu
*/

#include "Menu.hpp"

namespace Arcade {
    void Menu::init()
    {
        this->_isRunning = true;
//        std::string path = "./lib";
//        std::vector <std::string> libList;
//        std::vector <std::string> gameList;
//        for (const auto & entry : std::filesystem::directory_iterator(path)) {
//            DLLoader *loader = new DLLoader(entry.path());
//            void *load = loader->getFunction<void *>("entrypoint");
//            if (std::dynamic_pointer_cast<IGame>(load) != nullptr) {
//                gameList.push_back(entry.path());
//                load->close();
//            } else if (std::dynamic_pointer_cast<IDisplay>(load) != nullptr) {
//                libList.push_back(entry.path());
//                load->close();
//            } else {
//                load->close();
//            }
//        }
//        // Create DrawablesText
//        this->_drawableText.push_back({ 10, 10, 12, BLACK, std::string("Libs :"), std::string("Poppins-Black")});
//        // Loop in libList
//        int i = 20;
//        for (auto &lib : libList) {
//            this->_drawableText.push_back({ 10, i, 12, BLACK, lib.data(), std::string("Poppins-Black")});
//            i += 10;
//        }
//        this->_drawableText.push_back({ 10, i, 12, BLACK, std::string("Games :"), std::string("Poppins-Black")});
//        i += 10;
//        for (auto &game : gameList) {
//            this->_drawableText.push_back({ 10, i, 12, BLACK, game.data(), std::string("Poppins-Black")});
//            i += 10;
//        }
    }

    void Menu::update(Arcade::EventType event)
    {
        switch (event) {
            case EventType::UP:
                std::cout << "Up" << std::endl;
                break;
            case EventType::DOWN:
                std::cout << "Down" << std::endl;
                break;
            default: break;
        }
    }

    void Menu::close()
    {
        this->_isRunning = false;
    }

    bool Menu::isRunning()
    {
        return this->_isRunning;
    }

    const std::vector<Drawable> &Menu::getDrawable()
    {
        return _drawable;
    }

    const std::map<char, std::string> &Menu::getAssets()
    {
        return _assets;
    }

    const std::vector<DrawableText> &Menu::getDrawableText()
    {
        return _drawableText;
    }

    Arcade::EventType Menu::getDirection()
    {
        return _event;
    }

    void Menu::setIsRunning(bool isRunning)
    {
        _isRunning = isRunning;
    }

//    std::vector <std::string> Menu::getLib()
//    {
//        return _liblist;
//    }
//
//    std::vector <std::string> Menu::getGame()
//    {
//        return _gamelist;
//    }

    extern "C" IGame *entryPoint()
    {
        return new Menu();
    }
}
