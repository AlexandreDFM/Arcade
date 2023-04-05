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
        this->_index = 0;
        std::string path = "./lib";
        for (const auto & entry : std::filesystem::directory_iterator(path)) {
            if (entry.path().extension() != ".so") {
                std::cout << "Error: " << entry.path() << " is not a library" << std::endl;
                continue;
            }
            DLLoader *loader = new DLLoader(entry.path());
            char *string = loader->getFunction<char>("getType");
            if (string == nullptr) {
                std::cout << "Error: " << entry.path() << " is not a valid library" << std::endl;
                delete loader; continue;
            }
            if (strcmp(string, "Lib") == 0) _libs.push_back(entry.path());
            else if (strcmp(string, "Game") == 0) _games.push_back(entry.path());
            else std::cout << "Error: " << entry.path() << " is not a valid library" << std::endl;
            delete loader;
        }
    }

    void Menu::update(Arcade::EventType event)
    {
        switch (event) {
            case EventType::CLOSE:
                this->close();
                return;
            case EventType::RESTART:
                this->close();
                this->init();
                return;
            case EventType::UP:
                if (this->_index == 0) this->_index = _libs.size() + _games.size() - 1;
                else this->_index--;
                break;
            case EventType::DOWN:
                if (this->_index == _libs.size() + _games.size() - 1) this->_index = 0;
                else this->_index++;
                break;
            case EventType::LEFT:
                if (this->_index >= _libs.size()) this->_selectedGame = _games[this->_index - _libs.size()];
                else this->_selectedLib = _libs[this->_index];
                break;
            case EventType::RIGHT:
                if (this->_index >= _libs.size()) this->_selectedGame = _games[this->_index - _libs.size()];
                else this->_selectedLib = _libs[this->_index];
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
        _drawable.clear();
        return _drawable;
    }

    const std::map<char, std::string> &Menu::getAssets()
    {
        return _assets;
    }

    const std::vector<DrawableText> &Menu::getDrawableText()
    {
        _drawableText.clear();
        int index = 2;
        size_t indexSelector = 0;
        this->_drawableText.push_back({ 10, 1, 12, WHITE, std::string("Libs :"), std::string("Poppins-Black")});
        for (auto &lib : _libs) {
            int color = indexSelector == this->_index ? RED : this->_selectedLib == lib.data() ? GREEN : WHITE;
            this->_drawableText.push_back({ 10, index, 12, color, lib.data(), std::string("Poppins-Black")});
            indexSelector += 1; index += 1;
        }
        this->_drawableText.push_back({ 10, index, 12, WHITE, std::string("Games :"), std::string("Poppins-Black")});
        index += 1;
        for (auto &game : _games) {
            int color = indexSelector == this->_index ? RED : this->_selectedGame == game.data() ? GREEN : WHITE;
            this->_drawableText.push_back({ 10, index, 12, color, game.data(), std::string("Poppins-Black")});
            indexSelector += 1; index += 1;
        }
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

    extern "C" {
        IGame *entryPoint()
        {
            return new Menu();
        }
        char *getType()
        {
            return (char *) "Game";
        }
    }
}
