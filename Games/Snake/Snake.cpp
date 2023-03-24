/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-arcade-roman.lopes
** File description:
** SnakeGame.cpp
*/

#include "Snake.hpp"

namespace Arcade {
    SnakeGame::SnakeGame()
    {
    }

    void SnakeGame::init()
    {
        this->_score = 0;
        this->_apple.x = rand() % 59 + 1;
        this->_apple.y = rand() % 39 + 1;
        this->_snake.push_back({ 13, 12, 1, 'o'}); // draw value char
        this->_assets.push_back({{'o', "assets/snake/snake.png"}});
        this->_assets.push_back({{'x', "assets/snake/apple.png"}});
    }

    const std::vector<Drawable> &SnakeGame::getDrawable()
    {
        this->_all.clear();
        this->_all.push_back(this->_apple);
        for (auto &i : this->_snake)
            this->_all.push_back(i);
        return this->_all;
    }

    const std::map<char, std::string> &SnakeGame::getAssets()
    {
        return this->_assets;
    }

    EventType SnakeGame::getDirection()
    {
        return this->_direction;
    }

    void SnakeGame::update (EventType key)
    {
        if (key == EventType::LEFT && this->_direction != EventType::RIGHT)
            this->_direction = EventType::LEFT;
        if (key == EventType::RIGHT && this->_direction != EventType::LEFT)
            this->_direction = EventType::RIGHT;
        if (key == EventType::UP && this->_direction != EventType::DOWN)
            this->_direction = EventType::UP;
        if (key == EventType::DOWN && this->_direction != EventType::UP)
            this->_direction = EventType::DOWN;
        if (this->_direction == EventType::LEFT)
            this->_snake[0].x -= 1;
        if (this->_direction == EventType::RIGHT)
            this->_snake[0].x += 1;
        if (this->_direction == EventType::UP)
            this->_snake[0].y -= 1;
        if (this->_direction == EventType::DOWN)
            this->_snake[0].y += 1;

        if (this->_snake[0].x == this->_apple.x && this->_snake[0].y == this->_apple.y) {
            this->_snake.push_back({this->_apple.x, this->_apple.y, 1, 'o'});
            this->_apple.x = rand() % 59 + 1;
            this->_apple.y = rand() % 39 + 1;
            this->_score += 1;
        }

        for (auto &i : this->_snake)
            if (this->_snake[0].x == i.x && this->_snake[0].y == i.y)
                this->close();

        if (this._snake[0].x == 0 || this._snake[0].x == 60 || this._snake[0].y == 0 || this._snake[0].y == 40)
            this->close();
    }

    void SnakeGame::close()
    {
        this->_isRunning = false;
        this->_snake.clear();
        this->_all.clear();
        this->_assets.clear();
    }

    SnakeGame::~SnakeGame()
    {
    }
}
