/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-arcade-roman.lopes
** File description:
** SnakeGame.cpp
*/

#include "Snake.hpp"

namespace Arcade {
    SnakeGame::SnakeGame() : AGame()
    {
        _apple = {
                0, 0, BLACK, 'a'
        };
        _score = 0;
        _direction = EventType::NOTHING;
        _event = EventType::NOTHING;
        _isRunning = true;
    }

    void SnakeGame::init()
    {
        this->_score = 0;
        this->_event = EventType::NOTHING;
        this->_direction = EventType::NOTHING;
        this->_assets.insert({{'w', "./Assets/Games/Snake/wall.png"}});
        this->_assets.insert({{'h', "./Assets/Games/Snake/head.png"}});
        this->_assets.insert({{'b', "./Assets/Games/Snake/body.png"}});
        this->_assets.insert({{'t', "./Assets/Games/Snake/tail.png"}});
        this->_assets.insert({{'a', "./Assets/Games/Snake/apple.png"}});

        this->_snake.push_back({ 13, 12, BLACK, 'h'});
        this->_snake.push_back({ 12, 12, BLACK, 'b'});
        this->_snake.push_back({ 11, 12, BLACK, 'b'});
        this->_snake.push_back({ 10, 12, BLACK, 'b'});
//        this->_snake.push_back({ 9, 12, BLACK, 't'});
        this->_apple.x = 6 + (rand() % 28 + 1);
        this->_apple.y = 7 + (rand() % 18 + 1);
        this->_apple.draw = 'a';
        this->_text.push_back({ 33 * 40, 7 * 40, 12, BLACK, "Score: " + std::to_string(this->_score), std::string("Poppins-Black")});
        for (int x = 5; x < 31; x++) {
            this->_wall.push_back({x, 5, BLACK, 'w'});
            this->_wall.push_back({x, 20, BLACK, 'w'});
        }

        for (int y = 6; y < 20; y++) {
            this->_wall.push_back({5, y, BLACK, 'w'});
            this->_wall.push_back({30, y, BLACK, 'w'});
        }

//         for (auto &i : this->_wall)
//             std::cout << i.x << " " << i.y << " " << i.color << std::endl;

        std::cout << "Snake Init Leave" << std::endl;
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

    const std::vector<DrawableText> &SnakeGame::getDrawableText()
    {
        this->_text[0].text = "Score: " + std::to_string(this->_score);
        return this->_text;
    }

    const std::map<char, std::string> &SnakeGame::getAssets()
    {
        return this->_assets;
    }

    EventType SnakeGame::getDirection()
    {
        return this->_direction;
    }

    void SnakeGame::update(EventType key)
    {
        if (key == EventType::LEFT && this->_direction != EventType::RIGHT) this->_direction = EventType::LEFT;
        if (key == EventType::RIGHT && this->_direction != EventType::LEFT) this->_direction = EventType::RIGHT;
        if (key == EventType::DOWN && this->_direction != EventType::UP)    this->_direction = EventType::DOWN;
        if (key == EventType::UP && this->_direction != EventType::DOWN)    this->_direction = EventType::UP;
        static auto start = std::chrono::steady_clock::now();
        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsed_seconds = end - start;
        if (elapsed_seconds.count() > 0.1) {
            start = std::chrono::steady_clock::now();
        } else {
            return;
        }
        switch (this->_direction) {
            case EventType::UP:
                for (int i = this->_snake.size() - 1; i > 0; i--) {
                    this->_snake[i].x = this->_snake[i - 1].x;
                    this->_snake[i].y = this->_snake[i - 1].y;
                }
                this->_snake[0].y -= 1;
                break;
            case EventType::DOWN:
                for (int i = this->_snake.size() - 1; i > 0; i--) {
                    this->_snake[i].x = this->_snake[i - 1].x;
                    this->_snake[i].y = this->_snake[i - 1].y;
                }
                this->_snake[0].y += 1;
                break;
            case EventType::LEFT:
                for (int i = this->_snake.size() - 1; i > 0; i--) {
                    this->_snake[i].x = this->_snake[i - 1].x;
                    this->_snake[i].y = this->_snake[i - 1].y;
                }
                this->_snake[0].x -= 1;
                break;
            case EventType::RIGHT:
                for (int i = this->_snake.size() - 1; i > 0; i--) {
                    this->_snake[i].x = this->_snake[i - 1].x;
                    this->_snake[i].y = this->_snake[i - 1].y;
                }
                this->_snake[0].x += 1;
                break;
            default: break;
        }

        if (this->_snake[0].x == this->_apple.x && this->_snake[0].y == this->_apple.y) {
            int x = this->_snake[this->_snake.size() - 1].x;
            int y = this->_snake[this->_snake.size() - 1].y;
            this->_snake.push_back({x, y, BLACK, 'b'});
            this->_apple.x = rand() % 59 + 1;
            this->_apple.y = rand() % 39 + 1;
            this->_score += 1;
        }

        // Check if the _snake is in the _wall
        for (auto &i : this->_wall) {
            if (this->_snake[0].x == i.x && this->_snake[0].y == i.y)
                this->close();
        }
        // Check if the _snake is in the _snake with iterator
        for (auto it = this->_snake.begin() + 1; it != this->_snake.end(); it++) {
            if (this->_snake[0].x == it->x && this->_snake[0].y == it->y)
                this->close();
        }
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
            std::cout << "Snake entryPoint" << std::endl;
            return new SnakeGame();
        }
    }
}
