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
        _apple = { 0, 0, RED, 'a'};
        _score = 0;
        _highScore = 0;
        _direction = EventType::NOTHING;
        _isRunning = true;
    }

    void SnakeGame::init()
    {
        srand(time(nullptr));
        this->_score = 0;
        this->_speed = 1;
        this->_highScore = 0;
        this->_isStart = false;
        if (std::ifstream("./Assets/Games/Nibbler/HighScore.txt")) {
            std::ifstream file("./Assets/Games/Nibbler/HighScore.txt");
            std::string highScore = "";
            for (int i = 0; i < 1; i++)
                getline(file, highScore);
            file.close();
            this->_highScore = std::stoi(highScore);
        }
        this->_isRunning = true;
        this->_direction = EventType::NOTHING;
        this->_assets.insert({{'w', "./Assets/Games/Snake/Wall.png"}});
        this->_assets.insert({{'h', "./Assets/Games/Snake/Head.png"}});
        this->_assets.insert({{'b', "./Assets/Games/Snake/Body.png"}});
        this->_assets.insert({{'t', "./Assets/Games/Snake/Tail.png"}});
        this->_assets.insert({{'a', "./Assets/Games/Snake/Apple.png"}});

        this->setMap();

        this->_drawableText.push_back({ 33, 4, 12, WHITE, std::string("Username: ") + this->_menuInfo.username, std::string("Poppins-Black")});
        this->_drawableText.push_back({ 33, 7, 12, WHITE, "Score: " + std::to_string(this->_score), std::string("Poppins-Black")});
        this->_drawableText.push_back({ 33, 10, 12, WHITE, "HighScore: " + std::to_string(this->_highScore), std::string("Poppins-WHITE")});

        this->placeApple();
    }

    void SnakeGame::setMap()
    {
        std::string line;
        std::string path = "./Assets/Games/Snake/Snake.txt";
        if (!std::ifstream(path)) {
            std::cerr << "Error: File 'Snake.txt' not found." << std::endl; return;
        }
        std::ifstream inputFile(path);
        for (int y = 3 ;std::getline(inputFile, line); y++) {
            for (int i = 0; line[i]; i++) {
                switch (line[i]) {
                    case '#':   this->_wall.push_back({i + 2, y, WHITE, 'w', WEST}); break;
                    case 'h':   this->_snake.push_back({i + 2, y, BLUE, 'h', WEST}); break;
                    case 'b':   this->_snake.push_back({i + 2, y, BLUE, 'b', WEST}); break;
//                    case 't':   this->_snake.push_back({i + 2, y, BLUE, 't', WEST}); break;
                    default:    break;
                }
            }
        }
    }

    void SnakeGame::setHighScore()
    {
        std::ofstream file("./Assets/Games/Snake/HighScore.txt");
        if (file.is_open()) {
            file << std::to_string(this->_score) << std::endl;
        } else {
            std::cerr << "File for HighScore not found" << std::endl;
        }
        file.close();
    }

    void SnakeGame::placeApple()
    {
        std::vector<vector2i_t> appleCoord;
        for (int x = 6; x < 30; x++) {
            for (int y = 7; y < 20; y++) {
                vector2i_t coord = {x, y};
                appleCoord.insert(appleCoord.end(), coord);
            }
        }
        int index = 0;
        for (auto &i : this->_snake) {
            for (auto &j : appleCoord) {
                if (i.x == j.x && i.y == j.y) appleCoord.erase(appleCoord.begin() + index);
                index += 1;
            }
            index = 0;
        }
        index = 0;
        for (auto &i : this->_wall) {
            for (auto &j : appleCoord) {
                if (i.x == j.x && i.y == j.y) appleCoord.erase(appleCoord.begin() + index);
                index += 1;
            }
            index = 0;
        }

        if (appleCoord.empty()) {
            _apple = { 1, 1, RED, 'a'};
            this->_apple.x = 1; this->_apple.y = 1; this->_apple.draw = 'a';
        } else {
            size_t appleCoordIndex = (rand() % appleCoord.size());
            for (auto &i : appleCoord) {
                if (appleCoordIndex == 0) {
                    this->_apple.x = i.x;
                    this->_apple.y = i.y;
                    this->_apple.draw = 'a';
                    break;
                }
                appleCoordIndex--;
            }
            if (this->_score != 0 && this->_score % 5 == 0) this->_speed += 0.1;
            this->_drawableText[1].text = "Score: " + std::to_string(this->_score);
        }
    }

    void SnakeGame::update(EventType event)
    {
        this->_drawable.clear();
        this->_drawable.push_back(this->_apple);
        for (auto &i : this->_wall) this->_drawable.push_back(i);
        for (auto &i : this->_snake) this->_drawable.push_back(i);

        switch (event) {
            case EventType::CLOSE:   this->setHighScore(); this->close(); return;
            case EventType::RESTART: this->setHighScore(); this->close(); this->init(); return;
            case EventType::UP:      if (this->_direction != EventType::DOWN)    this->_direction = EventType::UP;    break;
            case EventType::LEFT:    if (this->_direction != EventType::RIGHT)   this->_direction = EventType::LEFT;  break;
            case EventType::DOWN:    if (this->_direction != EventType::UP)      this->_direction = EventType::DOWN;  break;
            case EventType::RIGHT:   if (this->_direction != EventType::LEFT)    this->_direction = EventType::RIGHT; break;
            default:                 break;
        }

        if (!this->_isStart) {
            for (auto &i : this->_wall) {
                switch (this->_direction) {
                    case EventType::UP:     if (this->_snake[0].x == i.x && this->_snake[0].y - 1 == i.y) return; else break;
                    case EventType::LEFT:   if (this->_snake[0].x - 1 == i.x && this->_snake[0].y == i.y) return; else break;
                    case EventType::DOWN:   if (this->_snake[0].x == i.x && this->_snake[0].y + 1 == i.y) return; else break;
                    case EventType::RIGHT:  if (this->_snake[0].x + 1 == i.x && this->_snake[0].y == i.y) return; else break;
                    default:                return;
                }
            }
            for (auto &i : this->_snake) {
                if (i.draw == 'h') continue;
                switch (this->_direction) {
                    case EventType::UP:     if (this->_snake[0].x == i.x && this->_snake[0].y - 1 == i.y) return; else break;
                    case EventType::LEFT:   if (this->_snake[0].x - 1 == i.x && this->_snake[0].y == i.y) return; else break;
                    case EventType::DOWN:   if (this->_snake[0].x == i.x && this->_snake[0].y + 1 == i.y) return; else break;
                    case EventType::RIGHT:  if (this->_snake[0].x + 1 == i.x && this->_snake[0].y == i.y) return; else break;
                    default:                return;
                }
            }
            this->_isStart = true;
        }
        static auto start = std::chrono::steady_clock::now();
        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsed_seconds = end - start;
        if (elapsed_seconds.count() * this->_speed > 0.1) start = std::chrono::steady_clock::now();
        else return;
        switch (this->_direction) {
            case EventType::UP:
                for (size_t i = this->_snake.size() - 1; i > 0; i--) {
                    this->_snake[i].rotation = this->_snake[i - 1].rotation;
                    this->_snake[i].x = this->_snake[i - 1].x;
                    this->_snake[i].y = this->_snake[i - 1].y;
                }
                this->_snake[0].y -= 1; this->_snake[0].rotation = NORTH;
                break;
            case EventType::DOWN:
                for (size_t i = this->_snake.size() - 1; i > 0; i--) {
                    this->_snake[i].rotation = this->_snake[i - 1].rotation;
                    this->_snake[i].x = this->_snake[i - 1].x;
                    this->_snake[i].y = this->_snake[i - 1].y;
                }
                this->_snake[0].y += 1; this->_snake[0].rotation = SOUTH;
                break;
            case EventType::LEFT:
                for (size_t i = this->_snake.size() - 1; i > 0; i--) {
                    this->_snake[i].rotation = this->_snake[i - 1].rotation;
                    this->_snake[i].x = this->_snake[i - 1].x;
                    this->_snake[i].y = this->_snake[i - 1].y;
                }
                this->_snake[0].x -= 1; this->_snake[0].rotation = WEST;
                break;
            case EventType::RIGHT:
                for (size_t i = this->_snake.size() - 1; i > 0; i--) {
                    this->_snake[i].rotation = this->_snake[i - 1].rotation;
                    this->_snake[i].x = this->_snake[i - 1].x;
                    this->_snake[i].y = this->_snake[i - 1].y;
                }
                this->_snake[0].x += 1; this->_snake[0].rotation = EAST;
                break;
            default: break;
        }
        if (this->_snake[0].x == this->_apple.x && this->_snake[0].y == this->_apple.y) {
            this->_snake[this->_snake.size() - 1].draw = 'b';
            switch (this->_direction) {
                case EventType::UP:     this->_snake.push_back({this->_snake[this->_snake.size() - 1].x, this->_snake[this->_snake.size() - 1].y + 1, BLUE, 'b'}); break;
                case EventType::DOWN:   this->_snake.push_back({this->_snake[this->_snake.size() - 1].x, this->_snake[this->_snake.size() - 1].y - 1, BLUE, 'b'}); break;
                case EventType::LEFT:   this->_snake.push_back({this->_snake[this->_snake.size() - 1].x + 1, this->_snake[this->_snake.size() - 1].y, BLUE, 'b'}); break;
                case EventType::RIGHT:  this->_snake.push_back({this->_snake[this->_snake.size() - 1].x - 1, this->_snake[this->_snake.size() - 1].y, BLUE, 'b'}); break;
                default:                break;
            }
            this->_score += 1;
            this->placeApple();
        }
        for (auto &i : this->_wall) {
            if (this->_snake[0].x == i.x && this->_snake[0].y == i.y) {
                if (this->_score > this->_highScore) this->setHighScore();
                this->close(); return;
            }
        }
        for (auto it = this->_snake.begin() + 1; it != this->_snake.end(); it++) {
            if (this->_snake[0].x == it->x && this->_snake[0].y == it->y) {
                if (this->_score > this->_highScore) this->setHighScore();
                this->close(); return;
            }
        }
    }

    void SnakeGame::close()
    {
        this->_isRunning = false;
        this->_snake.clear();
        this->_drawable.clear();
        this->_assets.clear();
    }

    extern "C" {
        IGame *entryPoint()
        {
            return new SnakeGame();
        }
        char *getType()
        {
            return (char *) "gameSnake";
        }
    }
}
