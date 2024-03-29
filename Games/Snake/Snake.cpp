/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-arcade-roman.lopes
** File description:
** SnakeGame.cpp
*/

#include "Snake.hpp"

namespace Arcade {
    /**
     * This is the constructor for the SnakeGame class that initializes its member
     * variables.
     */
    SnakeGame::SnakeGame() : AGame()
    {
        _apple = { 0, 0, RED, 'a'};
        _score = 0;
        _highScore = 0;
        _direction = EventType::NOTHING;
        _isRunning = true;
    }

    /**
     * The function initializes the SnakeGame object by setting various attributes
     * and loading assets.
     */
    void SnakeGame::init()
    {
        srand(time(nullptr));
        this->_score = 0;
        this->_speed = 1;
        this->_highScore = 0;
        this->_spriteSize = 40;
        this->_isStart = false;
        this->_pushATail = false;
        this->getHighScoreFromFile();
        this->getSpriteSizeFromFile();
        this->_isRunning = true;
        this->_direction = EventType::NOTHING;
        this->_assets.insert({{'w', "./Assets/Games/Snake/Images/Wall.png"}});
        this->_assets.insert({{'h', "./Assets/Games/Snake/Images/Head.png"}});
        this->_assets.insert({{'b', "./Assets/Games/Snake/Images/Body.png"}});
        this->_assets.insert({{'t', "./Assets/Games/Snake/Images/Tail.png"}});
        this->_assets.insert({{'a', "./Assets/Games/Snake/Images/Apple.png"}});
        this->_drawableText.push_back({ 33, 7, 12, WHITE, "Score: " + std::to_string(this->_score), std::string("Poppins-Black")});
        this->_drawableText.push_back({ 15, 1, 24, WHITE, "SNAKE", std::string("Poppins-Black")});
        this->_drawableText.push_back({ 33, 4, 12, WHITE, std::string("Username: ") + this->_menuInfo.username, std::string("Poppins-Black")});
        this->_drawableText.push_back({ 33, 10, 12, WHITE, "HighScore: " + std::to_string(this->_highScore), std::string("Poppins-WHITE")});
        if (std::ifstream("./Assets/Games/Snake/Config/Save.txt")) {
            this->loadSave();
        } else {
            this->setMap(); this->placeApple();
        }
    }

    /**
     * This function reads the high score from a file and sets it as the high
     * score for the Snake game.
     */
    void SnakeGame::getHighScoreFromFile()
    {
        if (std::ifstream("./Assets/Games/Snake/Config/HighScore.txt")) {
            std::ifstream file("./Assets/Games/Snake/Config/HighScore.txt");
            std::string highScore = "";
            for (int i = 0; i < 1; i++) getline(file, highScore);
            file.close();
            try {
                this->_highScore = std::stoi(highScore);
            } catch (std::exception &e) {
                this->_highScore = 0;
            }
        }
    }

    /**
     * This function reads the sprite size from a file and sets it as a member
     * variable in the SnakeGame class.
     */
    void SnakeGame::getSpriteSizeFromFile()
    {
        if (std::ifstream("./Assets/Config/SpriteSize.txt")) {
            std::ifstream file("./Assets/Config/SpriteSize.txt");
            std::string spriteSize = "";
            for (int i = 0; i < 1; i++) getline(file, spriteSize);
            file.close();
            try {
                this->_spriteSize = std::stoi(spriteSize);
            } catch (std::exception &e) {
                this->_spriteSize = 40;
            }
        }
    }

    void SnakeGame::setMap()
    {
        std::string line;
        std::string path = "./Assets/Games/Snake/Config/Snake.txt";
        if (!std::ifstream(path)) {
            std::cerr << "Error: File 'Snake.txt' not found." << std::endl; return;
        }
        std::ifstream inputFile(path);
        for (int y = 3 ;std::getline(inputFile, line); y++) {
            for (int i = 0; line[i]; i++) {
                switch (line[i]) {
                    case '#':   this->_wall.push_back({i + 2, y, WHITE, 'w', WEST, {0, 0, this->_spriteSize, this->_spriteSize}}); break;
                    case 'h':   this->_snake.push_back({i + 2, y, BLUE, 'h', WEST, {0, 0, this->_spriteSize, this->_spriteSize}}); break;
                    case 'b':   this->_snake.push_back({i + 2, y, BLUE, 'b', WEST, {0, 0, this->_spriteSize, this->_spriteSize}}); break;
                    case 't':   this->_snake.push_back({i + 2, y, BLUE, 'b', WEST}); break;
                    default:    break;
                }
            }
        }
    }

    /**
     * The function saves the current state of the Snake game to a text file.
     */
    void SnakeGame::save()
    {
        std::ofstream file("./Assets/Games/Snake/Config/Save.txt");
        file << this->_score << std::endl;
        file << this->_speed << std::endl;
        file << this->_highScore << std::endl;
        file << this->_direction << std::endl;
        file << "Snake: " << this->_snake.size() << std::endl;
        file << this->_snake[0].x << " " << this->_snake[0].y << " " << this->_snake[0].rotation << std::endl;
        for (auto &i : this->_snake) {
            file << i.x << " " << i.y << " " << i.rotation << std::endl;
        }
        file << "Wall: " << this->_wall.size() << std::endl;
        for (auto &i : this->_wall) {
            file << i.x << " " << i.y << std::endl;
        }
        file << "Apple: " << this->_apple.x << " " << this->_apple.y << std::endl;
        file.close();
    }

    /**
     * This function loads saved game data from a file for a Snake game.
     */
    void SnakeGame::loadSave()
    {
        std::ifstream file("./Assets/Games/Snake/Config/Save.txt");
        std::string line;
        std::getline(file, line);
        this->_score = std::stoi(line);
        std::getline(file, line);
        this->_speed = std::stoi(line);
        std::getline(file, line);
        this->_highScore = std::stoi(line);
        std::getline(file, line);
        this->_direction = static_cast<EventType>(std::stoi(line));
        std::getline(file, line);
        int snakeSize = std::stoi(line.substr(line.find(" ") + 1, line.size()));
        std::getline(file, line);
        std::string x = line.substr(0, line.find(" "));
        std::string y = line.substr(line.find(" ") + 1, line.find(" ", line.find(" ") + 1));
        std::string rotation = line.substr(line.find(" ", line.find(" ") + 1) + 1, line.size());
        this->_snake.clear();
        this->_snake.push_back({std::stoi(x), std::stoi(y), BLUE, 'h', static_cast<Direction>(std::stoi(rotation)), {0, 0, this->_spriteSize, this->_spriteSize}});
        for (int i = 0; i < snakeSize; i++) {
            std::getline(file, line);
            x = line.substr(0, line.find(" "));
            y = line.substr(line.find(" ") + 1, line.find(" ", line.find(" ") + 1));
            rotation = line.substr(line.find(" ", line.find(" ") + 1) + 1, line.size());
            this->_snake.push_back({std::stoi(x), std::stoi(y), BLUE, 'b', static_cast<Direction>(std::stoi(rotation)), {0, 0, this->_spriteSize, this->_spriteSize}});
        }
        std::getline(file, line);
        int wallSize = std::stoi(line.substr(line.find(" ") + 1, line.size()));
        this->_wall.clear();
        for (int i = 0; i < wallSize; i++) {
            std::getline(file, line);
            x = line.substr(0, line.find(" "));
            y = line.substr(line.find(" ") + 1, line.find(" ", line.find(" ") + 1));
            this->_wall.push_back({std::stoi(x), std::stoi(y), WHITE, 'w', NO_DIRECTION, {0, 0, this->_spriteSize, this->_spriteSize}});
        }
        std::getline(file, line);
        this->_apple = {std::stoi(line.substr(line.find(" ") + 1, line.find(" ", line.find(" ") + 1))), std::stoi(line.substr(line.find(" ", line.find(" ") + 1) + 1, line.size())), RED, 'a', WEST, {0, 0, this->_spriteSize, this->_spriteSize}};
        file.close();
    }

    /**
     * This function deletes the save file for the Snake game.
     */
    void SnakeGame::deleteSave()
    {
        std::remove("./Assets/Games/Snake/Config/Save.txt");
    }

    /**
     * The function sets the high score for the Snake game by writing it to a
     * file.
     */
    void SnakeGame::setHighScoreInFile()
    {
        std::ofstream file("./Assets/Games/Snake/Config/HighScore.txt");
        if (file.is_open()) file << std::to_string(this->_score) << std::endl;
        else std::cerr << "File for HighScore not found" << std::endl;
        file.close();
    }

    void SnakeGame::placeApple()
    {
        std::vector<std::pair<int, int>> appleCoord;
        for (int x = 6; x < 30; x++) {
            for (int y = 7; y < 20; y++) {
                appleCoord.push_back({x, y});
            }
        }
        int index = 0;
        for (auto &i : this->_snake) {
            for (auto &j : appleCoord) {
                if (i.x == j.first && i.y == j.second) appleCoord.erase(appleCoord.begin() + index);
                index += 1;
            }
            index = 0;
        }
        index = 0;
        for (auto &i : this->_wall) {
            for (auto &j : appleCoord) {
                if (i.x == j.first && i.y == j.second) appleCoord.erase(appleCoord.begin() + index);
                index += 1;
            }
            index = 0;
        }

        if (appleCoord.empty()) {
            _apple = { 1, 1, RED, 'a'};
        } else {
            size_t appleCoordIndex = (rand() % appleCoord.size());
            for (auto &i : appleCoord) {
                if (appleCoordIndex == 0) {
                    this->_apple.x = i.first;
                    this->_apple.y = i.second;
                    this->_apple.draw = 'a';
                    break;
                }
                appleCoordIndex--;
            }
            if (this->_score != 0 && this->_score % 5 == 0) this->_speed += 0.1;
            this->_drawableText[0].text = "Score: " + std::to_string(this->_score);
        }
    }

    /**
     * This function moves the snake's body in the specified direction and updates
     * its rotation.
     *
     * @param rotation The parameter "rotation" is of type "Direction" and
     * represents the direction in which the snake's head should move. It can take
     * one of four values: NORTH, SOUTH, WEST, or EAST.
     */
    void SnakeGame::moveSnakeBody(Direction rotation)
    {
        std::pair<int, int> tmp = {this->_snake[this->_snake.size() - 1].x, this->_snake[this->_snake.size() - 1].y};
        for (size_t i = this->_snake.size() - 1; i > 0; i--) {
            this->_snake[i].rotation = this->_snake[i - 1].rotation;
            this->_snake[i].x = this->_snake[i - 1].x;
            this->_snake[i].y = this->_snake[i - 1].y;
        }
        if (this->_pushATail) {
            this->_snake[this->_snake.size() - 1].draw = 'b';
            this->_snake.push_back({tmp.first, tmp.second, BLUE, 'b', WEST, {0, 0, this->_spriteSize, this->_spriteSize}});
            this->_pushATail = false;
        }
        switch (rotation) {
            case Direction::NORTH:  this->_snake[0].y -= 1; break;
            case Direction::SOUTH:  this->_snake[0].y += 1; break;
            case Direction::WEST:   this->_snake[0].x -= 1; break;
            case Direction::EAST:   this->_snake[0].x += 1; break;
            default:                break;
        }
        this->_snake[0].rotation = rotation;
    }

    void SnakeGame::update(EventType event)
    {
        this->_drawable.clear();
        this->_drawable.push_back(this->_apple);
        for (auto &i : this->_wall) this->_drawable.push_back(i);
        for (auto &i : this->_snake) this->_drawable.push_back(i);

        switch (event) {
            case EventType::SAVE:     this->save(); break;
            case EventType::CLOSE:    if (this->_score > this->_highScore) this->setHighScoreInFile(); this->close(); return;
            case EventType::RESTART:  if (this->_score > this->_highScore) this->setHighScoreInFile(); this->close(); this->init(); return;
            case EventType::GAMENEXT: this->save(); return;
            case EventType::GAMEPREV: this->save(); return;
            case EventType::UP:       if (this->_direction != EventType::DOWN)    this->_direction = EventType::UP;    break;
            case EventType::LEFT:     if (this->_direction != EventType::RIGHT)   this->_direction = EventType::LEFT;  break;
            case EventType::DOWN:     if (this->_direction != EventType::UP)      this->_direction = EventType::DOWN;  break;
            case EventType::RIGHT:    if (this->_direction != EventType::LEFT)    this->_direction = EventType::RIGHT; break;
            default:                  break;
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
            case EventType::UP: this->moveSnakeBody(Direction::NORTH); break;
            case EventType::LEFT: this->moveSnakeBody(Direction::WEST); break;
            case EventType::DOWN: this->moveSnakeBody(Direction::SOUTH); break;
            case EventType::RIGHT: this->moveSnakeBody(Direction::EAST); break;
            default: break;
        }
        if (this->_snake[0].x == this->_apple.x && this->_snake[0].y == this->_apple.y) {
            this->_pushATail = true;
            this->_score += 1;
            this->placeApple();
        }
        for (auto &i : this->_wall) {
            if (this->_snake[0].x == i.x && this->_snake[0].y == i.y) {
                if (this->_score > this->_highScore) this->setHighScoreInFile();
                this->deleteSave(); this->close(); return;
            }
        }
        for (auto it = this->_snake.begin() + 1; it != this->_snake.end(); it++) {
            if (this->_snake[0].x == it->x && this->_snake[0].y == it->y) {
                if (this->_score > this->_highScore) this->setHighScoreInFile();
                this->deleteSave(); this->close(); return;
            }
        }
    }

    /**
     * The close function sets the game to not running and clears all snake,
     * drawable, and asset data.
     */
    void SnakeGame::close()
    {
        this->_isRunning = false;
        this->_snake.clear();
        this->_drawable.clear();
        this->_assets.clear();
    }

    /* The above code is implementing the entry point and type functions for a
    Snake game in C++. The entryPoint function returns a new instance of the
    SnakeGame class as an IGame pointer, while the getType function returns a
    string "gameSnake" as a character pointer. These functions are declared as
    extern "C" to ensure that they have C linkage and can be called from C
    code. */
    extern "C" {
        /**
         * The function returns a new instance of the SnakeGame class as an IGame
         * pointer.
         *
         * @return An instance of the SnakeGame class is being returned as a
         * pointer to an IGame interface.
         */
        IGame *entryPoint()
        {
            return new SnakeGame();
        }

        /**
         * The function returns a string "gameSnake" as a character pointer.
         *
         * @return A string literal "gameSnake" is being returned as a pointer to
         * a character array.
         */
        char *getType()
        {
            return (char *) "gameSnake";
        }
    }
}
