/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-arcade-roman.lopes
** File description:
** NibblerGame.cpp
*/

#include "Nibbler.hpp"

namespace Arcade {
    NibblerGame::NibblerGame() : AGame()
    {
        _apple = {};
        _score = 0;
        _highScore = 0;
        _direction = EventType::NOTHING;
        _event = EventType::NOTHING;
        _isRunning = true;
    }

    void NibblerGame::setMap(int i)
    {
        std::string line;
        std::string path;

        if (i == 1)
            path = "./Assets/Games/Nibbler/Nibbler_LVL_1.txt";
        else if (i == 2)
            path = "./Assets/Games/Nibbler/Nibbler_LVL_2.txt";
        else
            path = "./Assets/Games/Nibbler/Nibbler_LVL_3.txt";

        std::ifstream inputFile(path);

        for (int y = 5 ;std::getline(inputFile, line); y++) {
            for (int i = 0; line[i]; i++) {
                if (line[i] == '#') this->_wall.push_back({i + 15, y, NORTH, BLACK, 'w'});
                else if (line[i] == 'P') this->_apples.push_back({i + 15, y, NORTH, BLACK, 'a'});
            }
        }
    }

    void NibblerGame::init()
    {
        srand(time(nullptr));
        this->_score = 0;
        std::ifstream file("./Assets/Games/Snake/HighScore.txt");
        std::string highscore = "";
            for (int i = 0; i < 1; i++)
            getline(file, highscore);
        file.close();
        this->_highScore = std::stoi(highscore);
        this->_event = EventType::NOTHING;
        this->_direction = EventType::NOTHING;

        this->_assets.insert({{'w', "./Assets/Games/Nibbler/Wall.png"}});
        this->_assets.insert({{'h', "./Assets/Games/Snake/Head.png"}});
        this->_assets.insert({{'b', "./Assets/Games/Snake/Body.png"}});
        this->_assets.insert({{'t', "./Assets/Games/Snake/Tail.png"}});
        this->_assets.insert({{'a', "./Assets/Games/Snake/Apple.png"}});

        this->setMap(1);

        this->_text.push_back({ 38, 7, 12, WHITE, "Score: " + std::to_string(this->_score), std::string("Poppins-Black")});
        this->_text.push_back({ 38, 10, 12, WHITE, "HighScore: " + std::to_string(this->_highScore), std::string("Poppins-Black")});

        this->_snake.push_back({ 25, 12, EAST, WHITE, 'h'});
        this->_snake.push_back({ 24, 12, NO_DIRECTION, WHITE, 'b'});
        this->_snake.push_back({ 23, 12, NO_DIRECTION, WHITE, 'b'});
        this->_snake.push_back({ 22, 12, NO_DIRECTION, WHITE, 'b'});
        this->_snake.push_back({ 21, 12, NO_DIRECTION, WHITE, 't'});
    }

    void NibblerGame::setHighScore()
    {
        std::ofstream file;
        file.open("./Assets/Games/Snake/HighScore.txt");
        file << this->_highScore << std::endl;
        file.close();
    }

    const std::vector<Drawable> &NibblerGame::getDrawable()
    {
        this->_all.clear();
        this->_all.push_back(this->_apple);
        for (auto &i : this->_wall)     this->_all.push_back(i);
        for (auto &i : this->_snake)    this->_all.push_back(i);
        for (auto &i : this->_apples)   this->_all.push_back(i);
        return this->_all;
    }

    const std::vector<DrawableText> &NibblerGame::getDrawableText()
    {
        this->_text[0].text = "Score: " + std::to_string(this->_score);
        return this->_text;
    }

    const std::map<char, std::string> &NibblerGame::getAssets()
    {
        return this->_assets;
    }

    EventType NibblerGame::getDirection()
    {
        return this->_direction;
    }

    void NibblerGame::placeApple()
    {

    }

    void NibblerGame::update(EventType event)
    {
        switch (event) {
            case EventType::CLOSE:  this->_isRunning = false; break;
            case EventType::RIGHT:  if (this->_direction != EventType::LEFT)    this->_direction = EventType::RIGHT;    break;
            case EventType::DOWN:   if (this->_direction != EventType::UP)      this->_direction = EventType::DOWN;     break;
            case EventType::LEFT:   if (this->_direction != EventType::RIGHT)   this->_direction = EventType::LEFT;     break;
            case EventType::UP:     if (this->_direction != EventType::DOWN)    this->_direction = EventType::UP;       break;
            default:                break;
        }
        for (auto &i : this->_wall) {
            switch (this->_direction) {
                case EventType::RIGHT:  if (this->_snake[0].x + 1 == i.x && this->_snake[0].y == i.y) this->_direction = EventType::NOTHING; break;
                case EventType::LEFT:   if (this->_snake[0].x - 1 == i.x && this->_snake[0].y == i.y) this->_direction = EventType::NOTHING; break;
                case EventType::DOWN:   if (this->_snake[0].x == i.x && this->_snake[0].y + 1 == i.y) this->_direction = EventType::NOTHING; break;
                case EventType::UP:     if (this->_snake[0].x == i.x && this->_snake[0].y - 1 == i.y) this->_direction = EventType::NOTHING; break;
                default:                break;
            }
        }
        if (this->_score == 10)         this->setMap(2);
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
                this->_snake[0].y -= 1; break;
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
                this->_snake[0].x -= 1; break;
            case EventType::RIGHT:
                for (int i = this->_snake.size() - 1; i > 0; i--) {
                    this->_snake[i].x = this->_snake[i - 1].x;
                    this->_snake[i].y = this->_snake[i - 1].y;
                }
                this->_snake[0].x += 1; break;
            default: break;
        }
        int index = 0;
        for (auto &i : this->_apples) {
            if (this->_snake[0].x == i.x && this->_snake[0].y == i.y) {
                this->_apples.erase(this->_apples.begin() + index);
                switch (this->_direction) {
                    case EventType::UP:
                        this->_snake.push_back(
                                {this->_snake[this->_snake.size() - 1].x,
                                 this->_snake[this->_snake.size() - 1].y + 1,
                                 NO_DIRECTION, BLACK, 'b'});
                        break;
                    case EventType::DOWN:
                        this->_snake.push_back(
                                {this->_snake[this->_snake.size() - 1].x,
                                 this->_snake[this->_snake.size() - 1].y - 1,
                                 NO_DIRECTION, BLACK, 'b'});
                        break;
                    case EventType::LEFT:
                        this->_snake.push_back(
                                {this->_snake[this->_snake.size() - 1].x + 1,
                                 this->_snake[this->_snake.size() - 1].y,
                                 NO_DIRECTION, BLACK, 'b'});
                        break;
                    case EventType::RIGHT:
                        this->_snake.push_back(
                                {this->_snake[this->_snake.size() - 1].x - 1,
                                 this->_snake[this->_snake.size() - 1].y,
                                 NO_DIRECTION, BLACK, 'b'});
                    default: break;
                }
                std::cout << "Snake Resized" << std::endl;
                this->placeApple();
                this->_score += 1;
            }
            index++;
        }
        for (auto it = this->_snake.begin() + 1; it != this->_snake.end(); it++) {
            if (this->_snake[0].x == it->x && this->_snake[0].y == it->y) {
                this->close(); return;
            }
        }
    }

    void NibblerGame::close()
    {
        this->_isRunning = false;
        this->_snake.clear();
        this->_all.clear();
        this->_wall.clear();
    }

    extern "C" IGame *entryPoint()
    {
        return new NibblerGame();
    }
}
