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
        std::ifstream file("./Assets/Games/Snake/HighScore.txt");
        std::string highScore = "";
        for (int i = 0; i < 1; i++)
            getline(file, highScore);
        file.close();
        this->_highScore = std::stoi(highScore);
        this->_isRunning = true;
        this->_direction = EventType::NOTHING;
        this->_assets.insert({{'w', "./Assets/Games/Snake/Wall.png"}});
        this->_assets.insert({{'h', "./Assets/Games/Snake/Head.png"}});
        this->_assets.insert({{'b', "./Assets/Games/Snake/Body.png"}});
        this->_assets.insert({{'t', "./Assets/Games/Snake/Tail.png"}});
        this->_assets.insert({{'a', "./Assets/Games/Snake/Apple.png"}});

        this->setMap();

        this->_text.push_back({ 33, 7, 12, WHITE, "Score: " + std::to_string(this->_score), std::string("Poppins-Black")});
        this->_text.push_back({ 33, 10, 12, WHITE, "HighScore: " + std::to_string(this->_highScore), std::string("Poppins-WHITE")});

        this->placeApple();
    }

    void SnakeGame::setMap()
    {
        std::string line;
        std::string path = "./Assets/Games/Snake/Snake.txt";
        std::ifstream inputFile(path);

        for (int y = 3 ;std::getline(inputFile, line); y++) {
            for (int i = 0; line[i]; i++) {
                switch (line[i]) {
                    case '#':   this->_wall.push_back({i + 2, y, BLACK, 'w'});     break;
                    case 'h':   this->_snake.push_back({i + 2, y, WHITE, 'h'});    break;
                    case 'b':   this->_snake.push_back({i + 2, y, WHITE, 'b'});    break;
                    case 't':   this->_snake.push_back({i + 2, y, WHITE, 't'});    break;
                    default:    break;
                }
            }
        }
    }

    void SnakeGame::setHighScore()
    {
        std::ofstream file;
        file.open("./Assets/Games/Snake/HighScore.txt");
        file << this->_highScore << std::endl;
        file.close();
    }

    const std::vector<Drawable> &SnakeGame::getDrawable() const
    {
        return this->_all;
    }

    const std::vector<DrawableText> &SnakeGame::getDrawableText() const
    {
        return this->_text;
    }

    const std::map<char, std::string> &SnakeGame::getAssets() const
    {
        return this->_assets;
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
            int appleCoordIndex = (rand() % appleCoord.size());
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
            this->_text[0].text = "Score: " + std::to_string(this->_score);
        }
    }

    void SnakeGame::update(EventType event)
    {
        this->_all.clear();
        this->_all.push_back(this->_apple);
        for (auto &i : this->_wall) this->_all.push_back(i);
        for (auto &i : this->_snake) this->_all.push_back(i);

        switch (event) {
            case EventType::CLOSE:   this->setHighScore(); this->close(); return;
            case EventType::RESTART: this->setHighScore(); this->close(); this->init(); return;
            case EventType::UP:      if (this->_direction != EventType::DOWN)    this->_direction = EventType::UP;    break;
            case EventType::LEFT:    if (this->_direction != EventType::RIGHT)   this->_direction = EventType::LEFT;  break;
            case EventType::DOWN:    if (this->_direction != EventType::UP)      this->_direction = EventType::DOWN;  break;
            case EventType::RIGHT:   if (this->_direction != EventType::LEFT)    this->_direction = EventType::RIGHT; break;
            default:                 break;
        }
        static auto start = std::chrono::steady_clock::now();
        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsed_seconds = end - start;
        if (elapsed_seconds.count() * this->_speed > 0.1) start = std::chrono::steady_clock::now();
        else return;
        switch (this->_direction) {
            case EventType::UP:
                for (int i = this->_snake.size() - 1; i > 0; i--) {
                    if (this->_snake[i].draw == 'h') this->_snake[i].rotation = NORTH;
                    this->_snake[i].x = this->_snake[i - 1].x;
                    this->_snake[i].y = this->_snake[i - 1].y;
                }
                this->_snake[0].y -= 1;
                break;
            case EventType::DOWN:
                for (int i = this->_snake.size() - 1; i > 0; i--) {
                    if (this->_snake[i].draw == 'h') this->_snake[i].rotation = SOUTH;
                    this->_snake[i].x = this->_snake[i - 1].x;
                    this->_snake[i].y = this->_snake[i - 1].y;
                }
                this->_snake[0].y += 1;
                break;
            case EventType::LEFT:
                for (int i = this->_snake.size() - 1; i > 0; i--) {
                    if (this->_snake[i].draw == 'h') this->_snake[i].rotation = WEST;
                    this->_snake[i].x = this->_snake[i - 1].x;
                    this->_snake[i].y = this->_snake[i - 1].y;
                }
                this->_snake[0].x -= 1;
                break;
            case EventType::RIGHT:
                for (int i = this->_snake.size() - 1; i > 0; i--) {
                    if (this->_snake[i].draw == 'h') this->_snake[i].rotation = EAST;
                    this->_snake[i].x = this->_snake[i - 1].x;
                    this->_snake[i].y = this->_snake[i - 1].y;
                }
                this->_snake[0].x += 1;
                break;
            default: break;
        }
        if (this->_snake[0].x == this->_apple.x && this->_snake[0].y == this->_apple.y) {
            this->_snake[this->_snake.size() - 1].draw = 'b';
            switch (this->_direction) {
                case EventType::UP:     this->_snake.push_back({this->_snake[this->_snake.size() - 1].x, this->_snake[this->_snake.size() - 1].y + 1, BLUE, 't'}); break;
                case EventType::DOWN:   this->_snake.push_back({this->_snake[this->_snake.size() - 1].x, this->_snake[this->_snake.size() - 1].y - 1, BLUE, 't'}); break;
                case EventType::LEFT:   this->_snake.push_back({this->_snake[this->_snake.size() - 1].x + 1, this->_snake[this->_snake.size() - 1].y, BLUE, 't'}); break;
                case EventType::RIGHT:  this->_snake.push_back({this->_snake[this->_snake.size() - 1].x - 1, this->_snake[this->_snake.size() - 1].y, BLUE, 't'}); break;
                default:                break;
            }
            this->placeApple();
            this->_score += 1;
        }
        for (auto &i : this->_wall) {
            if (this->_snake[0].x == i.x && this->_snake[0].y == i.y) {
                this->setHighScore(); this->close(); return;
            }
        }
        for (auto it = this->_snake.begin() + 1; it != this->_snake.end(); it++) {
            if (this->_snake[0].x == it->x && this->_snake[0].y == it->y) {
                this->setHighScore(); this->close(); return;
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
            return (char *) "gameSnake";
        }
    }
}
