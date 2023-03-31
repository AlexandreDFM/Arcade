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
        _apple = {
                0, 0, BLACK, 'a'
        };
        _score = 0;
        _direction = EventType::NOTHING;
        _event = EventType::NOTHING;
    }

    void SnakeGame::init()
    {
        this->_score = 0;
        this->_apple.x = rand() % 59 + 1;
        this->_apple.y = rand() % 39 + 1;
        this->_snake.push_back({ 13, 12, BLACK, 'o'});
        this->_wall.push_back({ 0, 0, BLACK, 'w'});
        this->_assets.insert({{'w', "assets/snake/wall.png"}});
        this->_assets.insert({{'s', "assets/snake/snake.png"}});
        this->_assets.insert({{'a', "assets/snake/apple.png"}});

        for (int i = 1; i < 60; i++) {
            this->_wall.push_back({i, 0, BLACK, 'w'});
            this->_wall.push_back({i, 40, BLACK, 'w'});
        }

        for (int i = 1; i < 40; i++) {
            this->_wall.push_back({0, i, BLACK, 'w'});
            this->_wall.push_back({60, i, BLACK, 'w'});
        }
    }

    const std::vector<Drawable> &SnakeGame::getDrawable()
    {
        this->_all.clear();
        this->_all.push_back(this->_apple);
        for (auto &i : this->_snake)
            this->_all.push_back(i);
        for (auto &i : this->_wall)
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
            this->_snake.push_back({this->_apple.x, this->_apple.y, BLACK, 's'});
            this->_apple.x = rand() % 59 + 1;
            this->_apple.y = rand() % 39 + 1;
            this->_score += 1;
        }

        for (auto &i : this->_snake)
            if (this->_snake[0].x == i.x && this->_snake[0].y == i.y)
                this->close();

        if (this->_snake[0].x == 0 || this->_snake[0].x == 60 || this->_snake[0].y == 0 || this->_snake[0].y == 40)
            this->close();
    }

    void SnakeGame::close()
    {
        this->_isRunning = false;
        this->_snake.clear();
        this->_all.clear();
        this->_assets.clear();
    }

    extern "C" {
        IGame *entryPoint()
        {
            return new SnakeGame();
        }
    }
}
