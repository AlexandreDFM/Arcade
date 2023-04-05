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
        _apple = { 0, 0, RED, 'a' };
        _score = 0;
        _highScore = 0;
        _direction = EventType::NOTHING;
        _event = EventType::NOTHING;
        _isRunning = true;
    }

    void SnakeGame::init()
    {
        srand(time(nullptr));
        // Set Variables
        this->_score = 0;
        this->_highScore = 0;
        this->_isRunning = true;
        this->_event = EventType::NOTHING;
        this->_direction = EventType::NOTHING;

        // Set Assets
        this->_assets.insert({{'w', "./Assets/Games/Snake/wall.png"}});
        this->_assets.insert({{'h', "./Assets/Games/Snake/head.png"}});
        this->_assets.insert({{'b', "./Assets/Games/Snake/body.png"}});
        this->_assets.insert({{'t', "./Assets/Games/Snake/tail.png"}});
        this->_assets.insert({{'a', "./Assets/Games/Snake/apple.png"}});

        // Place Background
        for (int x = 5; x < 31; x++) {
            this->_wall.push_back({x, 5, WHITE, 'w'});
            this->_wall.push_back({x, 20, WHITE, 'w'});
        }

        for (int y = 6; y < 20; y++) {
            this->_wall.push_back({5, y, WHITE, 'w'});
            this->_wall.push_back({30, y, WHITE, 'w'});
        }

        this->_text.push_back({ 33, 7, 12, WHITE, "Score: " + std::to_string(this->_score), std::string("Poppins-Black")});

        this->_text.push_back({ 33, 10, 12, WHITE, "HighScore: " + std::to_string(this->_highScore), std::string("Poppins-WHITE")});

//        int snakeX = 5 + (rand() % 28 + 1);
//        int snakeY = 6 + (rand() % 18 + 1);

        this->_snake.push_back({ 13, 12, WHITE, 'h'});
        this->_snake.push_back({ 12, 12, WHITE, 'b'});
        this->_snake.push_back({ 11, 12, WHITE, 'b'});
        this->_snake.push_back({ 10, 12, WHITE, 'b'});
        this->_snake.push_back({ 9, 12, WHITE, 't'});

        this->placeApple();
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

    void SnakeGame::placeApple()
    {
        std::map<int, int> appleCoord;
        for (int x = 6; x < 30; x++) {
            for (int y = 7; y < 20; y++) {
                appleCoord.insert({y, x});
            }
        }
        for (auto &i : this->_snake) {
            for (auto &j : appleCoord) {
                if (i.x == j.first && i.y == j.second) {
                    appleCoord.erase(j.first);
                    appleCoord.erase(j.second);
                }
            }
        }
        for (auto &i : this->_wall) {
            for (auto &j : appleCoord) {
                if (i.x == j.second && i.y == j.first) {
                    appleCoord.erase(j.first);
                    appleCoord.erase(j.second);
                }
            }
        }

        if (appleCoord.empty()) {
            _apple = { 1, 1, RED, 'a' };
            this->_apple.x = 1; this->_apple.y = 1; this->_apple.draw = 'a';
        } else {
            int appleCoordIndex = (rand() % appleCoord.size());
            for (auto &i : appleCoord) {
                if (appleCoordIndex == 0) {
                    this->_apple.x = i.second;
                    this->_apple.y = i.first;
                    this->_apple.draw = 'a';
                    break;
                }
                appleCoordIndex--;
            }
        }
    }

    void SnakeGame::update(EventType event)
    {
        switch (event) {
            case EventType::CLOSE:
                this->close();
                return;
            case EventType::RESTART:
                this->close();
                this->init();
                return;
            case EventType::LEFT:
                if (this->_direction != EventType::RIGHT)   this->_direction = EventType::LEFT;
                break;
            case EventType::RIGHT:
                if (this->_direction != EventType::LEFT)    this->_direction = EventType::RIGHT;
                break;
            case EventType::DOWN:
                if (this->_direction != EventType::UP)      this->_direction = EventType::DOWN;
                break;
            case EventType::UP:
                if (this->_direction != EventType::DOWN)    this->_direction = EventType::UP;
                break;
            default: break;
        }
        static auto start = std::chrono::steady_clock::now();
        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsed_seconds = end - start;
        if (elapsed_seconds.count() > 0.1) start = std::chrono::steady_clock::now();
        else return;
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
            switch (this->_direction) {
                case EventType::UP:
                    this->_snake.push_back({this->_snake[this->_snake.size() - 1].x, this->_snake[this->_snake.size() - 1].y + 1, WHITE, 'b'});
                    break;
                case EventType::DOWN:
                    this->_snake.push_back({this->_snake[this->_snake.size() - 1].x, this->_snake[this->_snake.size() - 1].y - 1, WHITE, 'b'});
                    break;
                case EventType::LEFT:
                    this->_snake.push_back({this->_snake[this->_snake.size() - 1].x + 1, this->_snake[this->_snake.size() - 1].y, WHITE, 'b'});
                    break;
                case EventType::RIGHT:
                    this->_snake.push_back({this->_snake[this->_snake.size() - 1].x - 1, this->_snake[this->_snake.size() - 1].y, WHITE, 'b'});
                    break;
                default: break;
            }
            this->placeApple();
            this->_score += 1;
        }
        for (auto &i : this->_wall) {
            if (this->_snake[0].x == i.x && this->_snake[0].y == i.y) {
                this->close();
                return;
            }
        }
        for (auto it = this->_snake.begin() + 1; it != this->_snake.end(); it++) {
            if (this->_snake[0].x == it->x && this->_snake[0].y == it->y) {
                this->close();
                return;
            }
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
            return new SnakeGame();
        }
        char *getType()
        {
            return (char *) "Game";
        }
    }
}
