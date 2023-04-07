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
        _isRunning = true;
    }

    void NibblerGame::reset()
    {
        this->_snake.clear();
        this->_wall.clear();
        this->_apples.clear();
        this->_drawableText.clear();
        this->_drawable.clear();
        this->_direction = EventType::NOTHING;

        if (this->_score == 20)
            this->setMap(2);
        else if (this->_score == 40)
            this->setMap(3);
        else
            std::cout << "You Win" << std::endl;

        this->_assets.insert({{'w', "./Assets/Games/Nibbler/Wall.png"}});
        this->_assets.insert({{'h', "./Assets/Games/Snake/Head.png"}});
        this->_assets.insert({{'b', "./Assets/Games/Snake/Body.png"}});
        this->_assets.insert({{'t', "./Assets/Games/Snake/Tail.png"}});
        this->_assets.insert({{'a', "./Assets/Games/Snake/Apple.png"}});

        this->_drawableText.push_back({ 38, 7, 12, WHITE, "Score: " + std::to_string(this->_score), std::string("Poppins-Black")});
        this->_drawableText.push_back({ 38, 10, 12, WHITE, "HighScore: " + std::to_string(this->_highScore), std::string("Poppins-Black")});
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
                switch (line[i]) {
                    case '#':   this->_wall.push_back({i + 15, y, WHITE, 'w'}); break;
                    case 'P':   this->_apples.push_back({i + 15, y, RED, 'a'}); break;
                    case 'h':   this->_snake.push_back({i + 15, y, BLUE, 'h'}); break;
                    case 'b':   this->_snake.push_back({i + 15, y, BLUE, 'b'}); break;
                    case 't':   this->_snake.push_back({i + 15, y, BLUE, 't'}); break;
                    default:    break;
                }
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
        this->_direction = EventType::NOTHING;

        this->_assets.insert({{'w', "./Assets/Games/Nibbler/Wall.png"}});
        this->_assets.insert({{'h', "./Assets/Games/Snake/Head.png"}});
        this->_assets.insert({{'b', "./Assets/Games/Snake/Body.png"}});
        this->_assets.insert({{'t', "./Assets/Games/Snake/Tail.png"}});
        this->_assets.insert({{'a', "./Assets/Games/Snake/Apple.png"}});

        this->setMap(1);

        this->_drawableText.push_back({ 38, 7, 12, WHITE, "Score: " + std::to_string(this->_score), std::string("Poppins-Black")});
        this->_drawableText.push_back({ 38, 10, 12, WHITE, "HighScore: " + std::to_string(this->_highScore), std::string("Poppins-Black")});
    }

    void NibblerGame::setHighScore()
    {
        std::ofstream file;
        file.open("./Assets/Games/Snake/HighScore.txt");
        file << this->_highScore << std::endl;
        file.close();
    }

    void NibblerGame::checkWall(EventType event)
    {
        for (auto &i : this->_wall) {
            switch (this->_direction) {
                case EventType::RIGHT:  if (this->_snake[0].x + 1 == i.x && this->_snake[0].y == i.y && this->_snake[1].x != this->_snake[0].x - 1) this->_direction = event; break;
                case EventType::LEFT:   if (this->_snake[0].x - 1 == i.x && this->_snake[0].y == i.y && this->_snake[1].x != this->_snake[0].x + 1) this->_direction = event; break;
                case EventType::DOWN:   if (this->_snake[0].x == i.x && this->_snake[0].y + 1 == i.y && this->_snake[1].y != this->_snake[0].y - 1) this->_direction = event; break;
                case EventType::UP:     if (this->_snake[0].x == i.x && this->_snake[0].y - 1 == i.y && this->_snake[1].y != this->_snake[0].y + 1) this->_direction = event; break;
                default:                break;
            }

        }
    }

    void NibblerGame::checkApple()
    {
        int index = 0;
        for (auto &i : this->_apples) {
            if (this->_snake[0].x == i.x && this->_snake[0].y == i.y) {
                this->_apples.erase(this->_apples.begin() + index);
                this->_snake[this->_snake.size() - 1].draw = 'b';
                switch (this->_direction) {
                    case EventType::UP:     this->_snake.push_back({this->_snake[this->_snake.size() - 1].x,this->_snake[this->_snake.size() - 1].y + 1, BLUE, 't'});    break;
                    case EventType::DOWN:   this->_snake.push_back({this->_snake[this->_snake.size() - 1].x,this->_snake[this->_snake.size() - 1].y - 1, BLUE, 't'});    break;
                    case EventType::LEFT:   this->_snake.push_back({this->_snake[this->_snake.size() - 1].x + 1,this->_snake[this->_snake.size() - 1].y, BLUE, 't'});     break;
                    case EventType::RIGHT:  this->_snake.push_back({this->_snake[this->_snake.size() - 1].x - 1,this->_snake[this->_snake.size() - 1].y, BLUE, 't'});     break;
                    default:                break;
                }
                this->_score += 1;
                this->_drawableText[0].text = "Score: " + std::to_string(this->_score);
            }
            index++;
        }
    }

    void NibblerGame::bodyMove()
    {
        switch (this->_direction) {
            case EventType::UP:
                for (auto i : this->_wall) {
                    if (this->_snake[0].x == i.x && this->_snake[0].y - 1 == i.y) {
                        for (auto j : this->_wall) {
                            if (this->_snake[0].x + 1 == j.x && this->_snake[0].y == j.y) {
                                this->_direction = EventType::LEFT;
                                return;
                            }
                            if (this->_snake[0].x - 1 == j.x && this->_snake[0].y == j.y) {
                                this->_direction = EventType::RIGHT;
                                return;
                            }
                        }
                        return;
                    }
                }
                for (size_t i = this->_snake.size() - 1; i > 0; i--) {
                    this->_snake[i].x = this->_snake[i - 1].x;
                    this->_snake[i].y = this->_snake[i - 1].y;
                }
                this->_snake[0].y -= 1; break;
            case EventType::DOWN:
                for (auto i : this->_wall) {
                    if (this->_snake[0].x == i.x && this->_snake[0].y + 1 == i.y) {
                        for (auto j : this->_wall) {
                            if (this->_snake[0].x + 1 == j.x && this->_snake[0].y == j.y) {
                                this->_direction = EventType::LEFT;
                                return;
                            }
                            if (this->_snake[0].x - 1 == j.x && this->_snake[0].y == j.y) {
                                this->_direction = EventType::RIGHT;
                                return;
                            }
                        }
                        return;
                    }
                }
                for (size_t i = this->_snake.size() - 1; i > 0; i--) {
                    this->_snake[i].x = this->_snake[i - 1].x;
                    this->_snake[i].y = this->_snake[i - 1].y;
                }
                this->_snake[0].y += 1;
                break;
            case EventType::LEFT:
                for (auto &i : this->_wall) {
                    if (this->_snake[0].x - 1 == i.x && this->_snake[0].y == i.y) {
                        for (auto j : this->_wall) {
                            if (this->_snake[0].x == j.x && this->_snake[0].y + 1 == j.y) {
                                this->_direction = EventType::UP;
                                return;
                            }
                            if (this->_snake[0].x == j.x && this->_snake[0].y - 1 == j.y) {
                                this->_direction = EventType::DOWN;
                                return;
                            }
                        }
                        return;
                    }
                }
                for (size_t i = this->_snake.size() - 1; i > 0; i--) {
                    this->_snake[i].x = this->_snake[i - 1].x;
                    this->_snake[i].y = this->_snake[i - 1].y;
                }
                this->_snake[0].x -= 1; break;
            case EventType::RIGHT:
                for (auto &i : this->_wall) {
                    if (this->_snake[0].x + 1 == i.x && this->_snake[0].y == i.y) {
                        for (auto j : this->_wall) {
                            if (this->_snake[0].x == j.x && this->_snake[0].y + 1 == j.y) {
                                this->_direction = EventType::UP;
                                return;
                            }
                            if (this->_snake[0].x == j.x && this->_snake[0].y - 1 == j.y) {
                                this->_direction = EventType::DOWN;
                                return;
                            }
                        }
                        return;
                    }
                }
                for (size_t i = this->_snake.size() - 1; i > 0; i--) {
                    this->_snake[i].x = this->_snake[i - 1].x;
                    this->_snake[i].y = this->_snake[i - 1].y;
                }
                this->_snake[0].x += 1; break;
            default: break;
        }
    }

    void NibblerGame::update(EventType event)
    {
        this->_drawable.clear();
        this->_drawable.push_back(this->_apple);
        for (auto &i : this->_wall)     this->_drawable.push_back(i);
        for (auto &i : this->_snake)    this->_drawable.push_back(i);
        for (auto &i : this->_apples)   this->_drawable.push_back(i);

        EventType tmp = this->_direction;
        if (this->_apples.size() == 0) this->reset();

        switch (event) {
            case EventType::CLOSE:  this->_isRunning = false; break;
            case EventType::RIGHT:  if (this->_direction != EventType::LEFT)    this->_direction = EventType::RIGHT;    break;
            case EventType::DOWN:   if (this->_direction != EventType::UP)      this->_direction = EventType::DOWN;     break;
            case EventType::LEFT:   if (this->_direction != EventType::RIGHT)   this->_direction = EventType::LEFT;     break;
            case EventType::UP:     if (this->_direction != EventType::DOWN)    this->_direction = EventType::UP;       break;
            default:                break;
        }

        this->checkWall(tmp);

        static auto start = std::chrono::steady_clock::now();
        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsed_seconds = end - start;
        if (elapsed_seconds.count() > 0.1) start = std::chrono::steady_clock::now();
        else return;

        this->bodyMove();
        this->checkApple();

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
        this->_drawable.clear();
        this->_wall.clear();
    }

    extern "C" {
        IGame *entryPoint()
        {
            return new NibblerGame();
        }

        char *getType()
        {
            return (char *) "gameNibbler";
        }
    }
}
