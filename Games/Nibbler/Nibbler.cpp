/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-arcade-roman.lopes
** File description:
** NibblerGame.cpp
*/

#include "Nibbler.hpp"

namespace Arcade {
    /**
     * This is the constructor for the NibblerGame class that initializes its
     * member variables.
     */
    NibblerGame::NibblerGame() : AGame()
    {
        _apple = {};
        _score = 0;
        _highScore = 0;
        _direction = EventType::NOTHING;
        _isRunning = true;
    }

    /**
     * The function resets the game state and initializes the game assets for the
     * Nibbler game.
     */
    void NibblerGame::reset()
    {
        this->_snake.clear();
        this->_wall.clear();
        this->_apples.clear();
        this->_drawableText.clear();
        this->_drawable.clear();
        this->_pushATail = false;
        this->_direction = EventType::NOTHING;

        if (this->_mapIndex == 3) {
            this->_mapIndex = 1; this->_speed += 0.1;
        } else {
            this->_mapIndex++; this->_speed += 0.1;
        }
        this->setMap(_mapIndex);

        this->_assets.insert({{'w', "./Assets/Games/Nibbler/Images/Wall.png"}});
        this->_assets.insert({{'h', "./Assets/Games/Nibbler/Images/Head.png"}});
        this->_assets.insert({{'b', "./Assets/Games/Nibbler/Images/Body.png"}});
        this->_assets.insert({{'t', "./Assets/Games/Nibbler/Images/Tail.png"}});
        this->_assets.insert({{'a', "./Assets/Games/Nibbler/Images/Apple.png"}});
        this->_drawableText.push_back({ 38, 7, 12, WHITE, "Score: " + std::to_string(this->_score), std::string("Poppins-Black")});

        this->_drawableText.push_back({ 33, 4, 12, WHITE, std::string("Username: ") + this->_menuInfo.username, std::string("Poppins-Black")});
        this->_drawableText.push_back({ 38, 10, 12, WHITE, "HighScore: " + std::to_string(this->_highScore), std::string("Poppins-Black")});
    }

    /**
     * This function sets the map for the Nibbler game by reading a text file and
     * creating objects based on the characters in the file.
     *
     * @param i The parameter `i` is an integer representing the level number of
     * the Nibbler game. It is used to determine the path of the configuration
     * file for the level.
     */
    void NibblerGame::setMap(int i)
    {
        std::string line; std::string path;
        if (std::ifstream("./Assets/Games/Nibbler/Config/NibblerLvl" + std::to_string(i) + ".txt")) {
            path = "./Assets/Games/Nibbler/Config/NibblerLvl" + std::to_string(i) + ".txt";
        } else {
            std::cerr << "Couldn't find the file." << std::endl;
            exit(84);
        }
        std::ifstream inputFile(path);
        for (int y = 5 ;std::getline(inputFile, line); y++) {
            for (int i = 0; line[i]; i++) {
                switch (line[i]) {
                    case '#':   this->_wall.push_back({i + 15, y, WHITE, 'w', WEST, {0, 0, this->_spriteSize, this->_spriteSize}}); break;
                    case 'P':   this->_apples.push_back({i + 15, y, RED, 'a', WEST, {0, 0, this->_spriteSize, this->_spriteSize}}); break;
                    case 'h':   this->_snake.push_back({i + 15, y, BLUE, 'h', WEST, {0, 0, this->_spriteSize, this->_spriteSize}}); break;
                    case 'b':   this->_snake.push_back({i + 15, y, BLUE, 'b', WEST, {0, 0, this->_spriteSize, this->_spriteSize}}); break;
                    case 't':   this->_snake.push_back({i + 15, y, BLUE, 'b', WEST, {0, 0, this->_spriteSize, this->_spriteSize}}); break;
                    default:    break;
                }
            }
        }
    }

    /**
     * The function initializes the game variables and loads assets for the
     * Nibbler game.
     */
    void NibblerGame::init()
    {
        srand(time(nullptr));
        this->_score = 0;
        this->_speed = 1;
        this->_mapIndex = 1;
        this->_highScore = 0;
        this->_spriteSize = 40;
        this->_pushATail = false;
        this->_direction = EventType::NOTHING;

        if (std::ifstream("./Assets/Games/Nibbler/Config/HighScore.txt")) {
            std::ifstream file("./Assets/Games/Nibbler/Config/HighScore.txt");
            std::string highScore = "";
            for (int i = 0; i < 1; i++) getline(file, highScore);
            file.close();
            this->_highScore = std::stoi(highScore);
        }

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

        if (std::ifstream("./Assets/Games/Nibbler/Config/Save.txt")) {
            this->loadSave();
        } else {
            this->setMap(_mapIndex);
        }

        this->_assets.insert({{'w', "./Assets/Games/Nibbler/Images/Wall.png"}});
        this->_assets.insert({{'h', "./Assets/Games/Nibbler/Images/Head.png"}});
        this->_assets.insert({{'b', "./Assets/Games/Nibbler/Images/Body.png"}});
        this->_assets.insert({{'t', "./Assets/Games/Nibbler/Images/Tail.png"}});
        this->_assets.insert({{'a', "./Assets/Games/Nibbler/Images/Apple.png"}});

        this->_drawableText.push_back({ 35, 13, 12, WHITE, "Score: " + std::to_string(this->_score), std::string("Poppins-Black")});

        this->_drawableText.push_back({ 23, 1, 24, WHITE, "NIBBLER", std::string("Poppins-Black")});
        this->_drawableText.push_back({ 35, 10, 12, WHITE, std::string("Username: ") + this->_menuInfo.username, std::string("Poppins-Black")});
        this->_drawableText.push_back({ 35, 16, 12, WHITE, "HighScore: " + std::to_string(this->_highScore), std::string("Poppins-Black")});
    }

    /**
     * The function sets the high score of the Nibbler game in a text file.
     */
    void NibblerGame::setHighScoreInFile()
    {
        std::ofstream file("./Assets/Games/Nibbler/Config/HighScore.txt");
        if (file.is_open()) file << std::to_string(this->_score) << std::endl;
        else std::cerr << "File for HighScore not found" << std::endl;
        file.close();
    }

    /**
     * The function checks if the snake hits a wall and changes its direction
     * accordingly.
     *
     * @param event The parameter "event" is of type EventType and represents the
     * direction in which the player is trying to move the snake. It is used to
     * check if the snake can move in that direction without hitting a wall.
     */
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

    /**
     * The function checks if the snake head has collided with an apple and
     * updates the game state accordingly.
     */
    void NibblerGame::checkApple()
    {
        int index = 0;
        for (auto &i : this->_apples) {
            if (this->_snake[0].x == i.x && this->_snake[0].y == i.y) {
                this->_apples.erase(this->_apples.begin() + index);
                this->_pushATail = true;
                this->_score += 1;
                this->_drawableText[0].text = "Score: " + std::to_string(this->_score);
            }
            index++;
        }
    }

    /**
     * This function moves the body of a snake in a Nibbler game based on a given
     * rotation direction.
     *
     * @param rotation The parameter "rotation" is of type "Direction" and
     * represents the direction in which the snake's head should move. It can take
     * one of four values: NORTH, SOUTH, WEST, or EAST.
     */
    void NibblerGame::moveSnakeBody(Direction rotation)
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

    /**
     * The function handles the movements of the snake in a game, taking into
     * account the walls and changing direction accordingly.
     *
     * @return nothing (void). However, there are several instances where the
     * function uses the keyword "return" to exit the function early under certain
     * conditions.
     */
    void NibblerGame::movements()
    {
        switch (this->_direction) {
            case EventType::UP:
                for (auto i : this->_wall) {
                    if (this->_snake[0].x == i.x && this->_snake[0].y - 1 == i.y) {
                        for (auto j : this->_wall) {
                            if (this->_snake[0].x + 1 == j.x && this->_snake[0].y == j.y) {
                                this->_direction = EventType::LEFT; return;
                            }
                            if (this->_snake[0].x - 1 == j.x && this->_snake[0].y == j.y) {
                                this->_direction = EventType::RIGHT; return;
                            }
                        }
                        return;
                    }
                }
                this->moveSnakeBody(Direction::NORTH); break;
            case EventType::DOWN:
                for (auto i : this->_wall) {
                    if (this->_snake[0].x == i.x && this->_snake[0].y + 1 == i.y) {
                        for (auto j : this->_wall) {
                            if (this->_snake[0].x + 1 == j.x && this->_snake[0].y == j.y) {
                                this->_direction = EventType::LEFT; return;
                            }
                            if (this->_snake[0].x - 1 == j.x && this->_snake[0].y == j.y) {
                                this->_direction = EventType::RIGHT; return;
                            }
                        }
                        return;
                    }
                }
                this->moveSnakeBody(Direction::SOUTH); break;
            case EventType::LEFT:
                for (auto &i : this->_wall) {
                    if (this->_snake[0].x - 1 == i.x && this->_snake[0].y == i.y) {
                        for (auto j : this->_wall) {
                            if (this->_snake[0].x == j.x && this->_snake[0].y + 1 == j.y) {
                                this->_direction = EventType::UP; return;
                            }
                            if (this->_snake[0].x == j.x && this->_snake[0].y - 1 == j.y) {
                                this->_direction = EventType::DOWN; return;
                            }
                        }
                        return;
                    }
                }
                this->moveSnakeBody(Direction::WEST); break;
            case EventType::RIGHT:
                for (auto &i : this->_wall) {
                    if (this->_snake[0].x + 1 == i.x && this->_snake[0].y == i.y) {
                        for (auto j : this->_wall) {
                            if (this->_snake[0].x == j.x && this->_snake[0].y + 1 == j.y) {
                                this->_direction = EventType::UP; return;
                            }
                            if (this->_snake[0].x == j.x && this->_snake[0].y - 1 == j.y) {
                                this->_direction = EventType::DOWN; return;
                            }
                        }
                        return;
                    }
                }
                this->moveSnakeBody(Direction::EAST); break;
            default: break;
        }
    }

    /**
     * The function saves the current state of the Nibbler game to a text file.
     */
    void NibblerGame::save()
    {
        std::ofstream file("./Assets/Games/Nibbler/Config/Save.txt");
        file << this->_score << std::endl;
        file << this->_mapIndex << std::endl;
        file << this->_speed << std::endl;
        file << this->_direction << std::endl;
        file << this->_snake.size() << std::endl;
        file << "Snake:" << std::endl;
        file << this->_snake[0].x << " " << this->_snake[0].y << " " << this->_snake[0].rotation << std::endl;
        for (auto &i : this->_snake) {
            file << i.x << " " << i.y << " " << i.rotation << std::endl;
        }
        file << "Apples:" << std::endl;
        file << this->_apples.size() << std::endl;
        for (auto &i : this->_apples) {
            file << i.x << " " << i.y << std::endl;
        }
        file << "Walls:" << std::endl;
        file << this->_wall.size() << std::endl;
        for (auto &i : this->_wall) {
            file << i.x << " " << i.y << std::endl;
        }
        file.close();
    }

    /**
     * This function loads saved game data from a file for the Nibbler game.
     */
    void NibblerGame::loadSave()
    {
        std::ifstream file;
        file.open("./Assets/Games/Nibbler/Config/Save.txt");
        std::string line;
        std::getline(file, line);
        this->_score = std::stoi(line);
        std::getline(file, line);
        this->_mapIndex = std::stoi(line);
        std::getline(file, line);
        this->_speed = std::stoi(line);
        std::getline(file, line);
        this->_direction = static_cast<EventType>(std::stoi(line));
        std::getline(file, line);
        int size = std::stoi(line);
        std::getline(file, line);
        std::getline(file, line);
        std::getline(file, line);
        std::string x = line.substr(0, line.find(" "));
        std::string y = line.substr(line.find(" ") + 1, line.find(" ", line.find(" ") + 1));
        std::string rot = line.substr(line.find(" ", line.find(" ") + 1) + 1, line.size());
        this->_snake.clear();
        this->_snake.push_back({std::stoi(x), std::stoi(y), BLUE, 'h', static_cast<Direction>(std::stoi(rot)), {0, 0, this->_spriteSize, this->_spriteSize}});
        for (int i = 1; i < size; i++) {
            std::getline(file, line);
            x = line.substr(0, line.find(" "));
            y = line.substr(line.find(" ") + 1, line.find(" ", line.find(" ") + 1));
            rot = line.substr(line.find(" ", line.find(" ") + 1) + 1, line.size());
            this->_snake.push_back({std::stoi(x), std::stoi(y), BLUE, 'b', static_cast<Direction>(std::stoi(rot)), {0, 0, this->_spriteSize, this->_spriteSize}});
        }
        std::getline(file, line);
        std::getline(file, line);
        size = std::stoi(line);
        this->_apples.clear();
        for (int i = 0; i < size; i++) {
            std::getline(file, line);
            x = line.substr(0, line.find(" "));
            y = line.substr(line.find(" ") + 1, line.size());
            this->_apples.push_back({std::stoi(x), std::stoi(y), RED, 'a', Direction::NO_DIRECTION, {0, 0, this->_spriteSize, this->_spriteSize}});
        }
        std::getline(file, line);
        std::getline(file, line);
        size = std::stoi(line);
        this->_wall.clear();
        for (int i = 0; i < size; i++) {
            std::getline(file, line);
            x = line.substr(0, line.find(" "));
            y = line.substr(line.find(" ") + 1, line.size());
            this->_wall.push_back({std::stoi(x), std::stoi(y), WHITE, 'w', Direction::NO_DIRECTION, {0, 0, this->_spriteSize, this->_spriteSize}});
        }
    }

    /**
     * This function deletes the save file for the Snake game in the specified
     * directory.
     */
    void NibblerGame::deleteSave()
    {
        std::remove("./Assets/Games/Nibbler/Config/Save.txt");
    }

    /**
     * The function checks if the game can start by ensuring that the snake and
     * walls do not overlap.
     *
     * @return The function `beforeStart()` returns a boolean value.
     */
    bool NibblerGame::beforeStart()
    {
        if (!this->_isStart) {
            for (auto &i : this->_wall) {
                switch (this->_direction) {
                    case EventType::UP:     if (this->_snake[0].x == i.x && this->_snake[0].y - 1 == i.y) return false; else break;
                    case EventType::LEFT:   if (this->_snake[0].x - 1 == i.x && this->_snake[0].y == i.y) return false; else break;
                    case EventType::DOWN:   if (this->_snake[0].x == i.x && this->_snake[0].y + 1 == i.y) return false; else break;
                    case EventType::RIGHT:  if (this->_snake[0].x + 1 == i.x && this->_snake[0].y == i.y) return false; else break;
                    default:                return false;
                }
            }
            for (auto &i : this->_snake) {
                if (i.draw == 'h') continue;
                switch (this->_direction) {
                    case EventType::UP:     if (this->_snake[0].x == i.x && this->_snake[0].y - 1 == i.y) return false; else break;
                    case EventType::LEFT:   if (this->_snake[0].x - 1 == i.x && this->_snake[0].y == i.y) return false; else break;
                    case EventType::DOWN:   if (this->_snake[0].x == i.x && this->_snake[0].y + 1 == i.y) return false; else break;
                    case EventType::RIGHT:  if (this->_snake[0].x + 1 == i.x && this->_snake[0].y == i.y) return false; else break;
                    default:                return false;
                }
            }
            this->_isStart = true;
        }
        return true;
    }

    /**
     * The function updates the state of the Nibbler game based on the given event
     * and checks for collisions between the snake and walls or apples.
     *
     * @param event The parameter "event" is of type EventType and represents the
     * user input event that triggers the update function. It can be one of the
     * following values: CLOSE, SAVE, RIGHT, DOWN, LEFT, UP.
     *
     * @return If the condition `elapsed_seconds.count() * _speed > 0.1` is not
     * met, the function returns without executing the remaining code. If the
     * snake collides with itself, the function returns after closing the game.
     * Otherwise, the function does not return anything.
     */
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
            case EventType::SAVE:     this->save(); break;
            case EventType::GAMENEXT: this->save(); break;
            case EventType::GAMEPREV: this->save(); break;
            case EventType::CLOSE:    if (this->_score > this->_highScore) setHighScoreInFile(); this->close(); break;
            case EventType::RIGHT:    if (this->_direction != EventType::LEFT)    this->_direction = EventType::RIGHT;    break;
            case EventType::DOWN:     if (this->_direction != EventType::UP)      this->_direction = EventType::DOWN;     break;
            case EventType::LEFT:     if (this->_direction != EventType::RIGHT)   this->_direction = EventType::LEFT;     break;
            case EventType::UP:       if (this->_direction != EventType::DOWN)    this->_direction = EventType::UP;       break;
            default:                  break;
        }

        this->beforeStart();
        this->checkWall(tmp);

        static auto start = std::chrono::steady_clock::now();
        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsed_seconds = end - start;
        if (elapsed_seconds.count() * _speed > 0.1) start = std::chrono::steady_clock::now();
        else return;

        this->movements();
        this->checkApple();

        for (auto it = this->_snake.begin() + 1; it != this->_snake.end(); it++) {
            if (this->_snake[0].x == it->x && this->_snake[0].y == it->y) {
                if (this->_score > this->_highScore) this->setHighScoreInFile();
                this->deleteSave(); this->close(); return;
            }
        }
    }

    /**
     * The function closes the Nibbler game by resetting various game elements.
     */
    void NibblerGame::close()
    {
        this->_isRunning = false;
        this->_snake.clear();
        this->_drawable.clear();
        this->_wall.clear();
    }

    /* The above code is implementing the entry point and type functions for a
    game called "Nibbler". The `entryPoint()` function returns a pointer to a
    new instance of the `NibblerGame` class that implements the `IGame`
    interface. The `getType()` function returns a string literal "gameNibbler"
    as a pointer to a character array. These functions are declared as `extern
    "C"` to ensure that they have C linkage and can be called from a C program. */
    extern "C" {
        /**
         * The function returns a pointer to a new instance of the NibblerGame
         * class, which implements the IGame interface.
         *
         * @return An instance of the `NibblerGame` class that implements the
         * `IGame` interface is being returned.
         */
        IGame *entryPoint()
        {
            return new NibblerGame();
        }

        /**
         * The function returns a string indicating the type of game, which is
         * "gameNibbler".
         *
         * @return A string literal "gameNibbler" is being returned as a pointer
         * to a character array.
         */
        char *getType()
        {
            return (char *) "gameNibbler";
        }
    }
}
