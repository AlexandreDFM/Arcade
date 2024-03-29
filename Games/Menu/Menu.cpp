/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-arcade-roman.lopes
** File description:
** Menu
*/

#include "Menu.hpp"

namespace Arcade {
    /**
     * The function initializes various variables and loads libraries and assets
     * for a menu.
     */
    void Menu::init()
    {
        this->_isRunning = true;
        this->_username = "Player 1";
        this->_isUsernameSet = false;
        this->_alphabetIndex = 0;
        this->_alphabet = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "_", "DEL"};
        this->_index = 0;
        std::string path = "./lib";
        for (const auto & entry : std::filesystem::directory_iterator(path)) {
            if (entry.path().extension() != ".so") {
                std::cout << "Error: " << entry.path() << " is not a library" << std::endl; continue;
            }
            DLLoader *loader = new DLLoader(entry.path());
            char *string = loader->getFunction<char>("getType");
            if (string == nullptr) {
                std::cout << "Error: " << entry.path() << " is not a valid library" << std::endl;
                continue;
            }
            if (strncmp(string, "lib", 3) == 0) _libs.emplace_back(std::string(string += 3), entry.path().string());
            else if (strncmp(string, "game", 4) == 0) _games.emplace_back(std::string(string += 4), entry.path().string());
            else std::cout << "Error: " << entry.path() << " is not a valid library" << std::endl;
        }
        this->_assets.insert({{'b', "./Assets/Games/Menu/Images/Background.png"}});
        this->_drawable.push_back({0, 0, BLACK, 'b', NO_DIRECTION, {0, 0, 1920, 1080}});
        this->_drawableText.push_back({ 18, 1, 12, WHITE, std::string("Username :"), std::string("Poppins-Black")});
    }

    /**
     * The function updates the menu based on the given event, allowing the user
     * to select a username and choose a game and library to play.
     *
     * @param event The parameter "event" is of type Arcade::EventType and
     * represents the event that occurred in the menu. It is used to update the
     * state of the menu accordingly.
     *
     * @return The function does not return anything, as its return type is void.
     */
    void Menu::update(Arcade::EventType event)
    {
        this->_drawableText.clear();
        if (!this->_isUsernameSet) {
            this->_drawableText.push_back({ 19, 1, 12, WHITE, std::string("Username :"), std::string("Poppins-Black")});
            this->_drawableText.push_back({ 19 + 6, 1, 12, WHITE, this->_username, std::string("Poppins-Black")});
            int line = 3;
            int index = 0;
            int indexInAlphabet = 0;
            for (auto &letter : this->_alphabet) {
                if (index == 20) { index = 0; line += 1; }
                Color color = this->_alphabetIndex == indexInAlphabet ? RED : WHITE;
                this->_drawableText.push_back({ 14 + index, line, 12, color, letter, std::string("Poppins-Black")});
                index += 1; indexInAlphabet += 1;
            }
            switch (event) {
                case Arcade::EventType::LEFT:
                    this->_alphabetIndex -= 1;
                    if (this->_alphabetIndex < 0) this->_alphabetIndex = this->_alphabet.size() - 1;
                    break;
                case Arcade::EventType::RIGHT:
                    this->_alphabetIndex += 1;
                    if (this->_alphabetIndex >= (int) this->_alphabet.size()) this->_alphabetIndex = 0;
                    break;
                case Arcade::EventType::ACTION1:
                    if (this->_alphabet[this->_alphabetIndex] == "DEL") {
                        if (this->_username.size() > 0) this->_username.pop_back();
                    } else if (this->_alphabet[this->_alphabetIndex] == " ") {
                        if (this->_username.size() < 10) this->_username += " ";
                    } else {
                        if (this->_username.size() < 10) this->_username += this->_alphabet[this->_alphabetIndex];
                    }
                    break;
                case Arcade::EventType::CLOSE: this->_isRunning = false; break;
                case Arcade::EventType::ACTION2: this->_isUsernameSet = true; break;
                default: break;
            }
            return;
        }
        int index = 2;
        size_t indexSelector = 0;
        this->_drawableText.push_back({ 10, 1, 12, WHITE, std::string("Libs :"), std::string("Poppins-Black")});
        for (auto &lib : _libs) {
            Color color = indexSelector == this->_index ? RED : this->_selectedLib.first == lib.first ? GREEN : WHITE;
            this->_drawableText.push_back({ 10, index, 12, color, lib.first, std::string("Poppins-Black")});
            indexSelector += 1; index += 1;
        }
        this->_drawableText.push_back({ 10, index, 12, WHITE, std::string("Games :"), std::string("Poppins-Black")});
        index += 1;
        for (auto &game : _games) {
            Color color = indexSelector == this->_index ? RED : this->_selectedGame.first == game.first ? GREEN : WHITE;
            this->_drawableText.push_back({ 10, index, 12, color, game.first, std::string("Poppins-Black")});
            indexSelector += 1; index += 1;
        }
        switch (event) {
            case EventType::CLOSE:   this->close(); return;
            case EventType::RESTART: this->close(); this->init(); return;
            case EventType::LEFT:   this->_isUsernameSet = false; break;
            case EventType::UP:
                if (this->_index == 0) this->_index = _libs.size() + _games.size() - 1;
                else this->_index--;
                break;
            case EventType::DOWN:
                if (this->_index == _libs.size() + _games.size() - 1) this->_index = 0;
                else this->_index++;
                break;
            case EventType::ACTION1:
                if (this->_index >= _libs.size()) this->_selectedGame = _games[this->_index - _libs.size()];
                else this->_selectedLib = _libs[this->_index];
                break;
            case EventType::ACTION2:
                this->setMenuInfo((MenuInfo) {this->_username, this->_selectedGame.second, this->_selectedLib.second});
                break;
            default: break;
        }
    }

    /**
     * The function "close" sets the "_isRunning" variable to false and clears the
     * "_libs" and "_games" vectors.
     */
    void Menu::close()
    {
        this->_isRunning = false;
        this->_libs.clear();
        this->_games.clear();
    }

    /* The `extern "C"` block is used to specify that the functions inside it
    should be compiled using C linkage instead of C++ linkage. This is
    necessary when the code is being used in a C++ program but the functions
    need to be called from a C program or a library that uses C linkage. In
    this case, the `entryPoint()` and `getType()` functions are being declared
    with C linkage so that they can be called from a C program or library that
    uses C linkage. */
    extern "C" {
        /**
         * The function returns a pointer to a new instance of the Menu class,
         * which implements the IGame interface.
         *
         * @return An instance of the `Menu` class, which implements the `IGame`
         * interface, is being returned.
         */
        IGame *entryPoint()
        {
            return new Menu();
        }

        /**
         * The function returns a string "gameMenu" as a character pointer.
         *
         * @return A string literal "gameMenu" is being returned as a pointer to a
         * character array.
         */
        char *getType()
        {
            return (char *) "gameMenu";
        }
    }
}
