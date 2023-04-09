/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-arcade-roman.lopes
** File description:
** Core
*/

#include "Core.hpp"

namespace Arcade {
    /**
     * This is a constructor for a C++ class called "Core".
     */
    Core::Core()
    {
    }

    /**
     * This is the destructor for the Core class in C++.
     */
    Core::~Core()
    {
    }

    /**
     * The function initializes the Core object by loading the graphic and game
     * libraries, and storing the paths of all valid libraries in the "./lib"
     * directory.
     *
     * @param lib The parameter `lib` is a string representing the path to a
     * dynamic library file that will be loaded by the program using the
     * `DLLoader` class. This library is expected to contain a function called
     * `entryPoint` that returns an object implementing the `IDisplay` interface,
     * which will be used
     */
    Core::Core(std::string lib)
    {
        this->_indexLib = 0; this->_indexGame = 0;
        this->graphicDll = new DLLoader(lib);
        char *str = this->graphicDll->getFunction<char>("getType");
        if (str == nullptr) {
            std::cout << "Error: " << lib << " is not a valid library" << std::endl; exit(84);
        } else if (strncmp(str, "lib", 3) != 0) {
            std::cout << "Error: " << lib << " is not a valid library" << std::endl; exit(84);
        }
        this->setGraphic(this->graphicDll->getFunction<IDisplay>("entryPoint"));
        if (!std::filesystem::exists("./lib/arcade_menu.so")) {
            std::cout << "Error: ./lib/arcade_menu.so does not exist" << std::endl; exit(84);
        }
        this->gameDll = new DLLoader("./lib/arcade_menu.so");
        this->setGame(this->gameDll->getFunction<IGame>("entryPoint"));
        std::string path = "./lib";
        for (const auto & entry : std::filesystem::directory_iterator(path)) {
            if (entry.path().extension() != ".so") {
                std::cout << "Error: " << entry.path() << " is not a library" << std::endl; continue;
            }
            DLLoader *loader = new DLLoader(entry.path());
            char *string = loader->getFunction<char>("getType");
            if (string == nullptr) {
                std::cout << "Error: " << entry.path() << " is not a valid library" << std::endl; continue;
            }
            if (strncmp(string, "lib", 3) == 0) _libs.push_back(entry.path());
            else if (strncmp(string, "game", 4) == 0) _games.push_back(entry.path());
            else std::cout << "Error: " << entry.path() << " is not a valid library" << std::endl;
        }
    }

    /**
     * The Core constructor initializes the graphic and game DLLs and sets their
     * entry points.
     *
     * @param lib A string representing the file path of the dynamic library
     * (shared object) containing the implementation of the graphical user
     * interface (GUI) for the game.
     * @param game The "game" parameter is a string that represents the path to
     * the dynamic library file that contains the implementation of the game
     * logic.
     */
    Core::Core(std::string lib, std::string game)
    {
        this->graphicDll = new DLLoader(lib);
        this->setGraphic(this->graphicDll->getFunction<IDisplay>("entryPoint"));
        this->gameDll = new DLLoader(game);
        this->setGame(this->gameDll->getFunction<IGame>("entryPoint"));
    }

    /**
     * The function sets the graphic display for the Core object.
     *
     * @param graphic A pointer to an object of type IDisplay, which is likely an
     * interface or abstract class representing a display or graphics system. The
     * function sets the "graphic" member variable of the Core class to the
     * provided pointer.
     */
    void Core::setGraphic(IDisplay *graphic)
    {
        this->graphic = graphic;
    }

    /**
     * This function sets the game object for the Core class.
     *
     * @param game game is a pointer to an object of type IGame, which is an
     * interface for a game. The function setGame() sets the value of the private
     * member variable game in the Core class to the value of the parameter game.
     * This allows the Core class to access and interact with the game object.
     */
    void Core::setGame(IGame *game)
    {
        this->game = game;
    }

    /**
     * This function runs the game loop, initializing the game and graphics,
     * displaying the game and text, updating the game based on user input, and
     * handling changes in the library or game.
     */
    void Core::loop()
    {
        this->game->init();
        this->graphic->init(this->game->getAssets());
        while (this->game->isRunning()) {
            this->graphic->display(this->game->getDrawable());
            this->graphic->display(this->game->getDrawableText());
            Arcade::EventType eventKey = this->graphic->getEvent();
            if (eventKey == EventType::MENU) this->setMenu();
            this->game->update(eventKey);
            this->setChangeLib(eventKey);
            this->setChangeGame(eventKey);
            this->MenuGetChange();
            if (!this->game->isRunning()) break;
            this->graphic->update();
            this->graphic->clear();
        }
        this->graphic->close();
    }

    /**
     * The function sets the menu for the arcade game by loading a dynamic library
     * and initializing the game and graphics.
     *
     * @return If the condition in the if statement is true (i.e.,
     * "./lib/arcade_menu.so" does not exist), then the function returns without
     * executing the rest of the code. If the condition is false, then nothing is
     * returned explicitly, as the function does not have a return type.
     */
    void Core::setMenu()
    {
        if (!std::filesystem::exists("./lib/arcade_menu.so")) {
            std::cout << "Error: ./lib/arcade_menu.so does not exist" << std::endl; return;
        }
        this->game->close();
        this->graphic->close();
        this->gameDll = new DLLoader("./lib/arcade_menu.so");
        this->setGame(this->gameDll->getFunction<IGame>("entryPoint"));
        this->game->init();
        this->graphic->init(this->game->getAssets());
        this->graphic->display(this->game->getDrawable());
        this->graphic->display(this->game->getDrawableText());
        this->graphic->update();
        this->graphic->clear();
    }

    /**
     * The function sets the library to the next or previous one in a list of
     * libraries.
     *
     * @param event An enum value of the EventType enum class, which can be either
     * LIBNEXT or LIBPREV.
     */
    void Core::setChangeLib(EventType event)
    {
        if (event == EventType::LIBNEXT) {
            if (this->_indexLib == this->_libs.size() - 1) this->_indexLib = 0;
            else this->_indexLib++;
            this->changeLib(this->_libs[this->_indexLib]);
        } else if (event == EventType::LIBPREV) {
            if (this->_indexLib == 0) this->_indexLib = this->_libs.size() - 1;
            else this->_indexLib--;
            this->changeLib(this->_libs[this->_indexLib]);
        }
    }

    /**
     * The function changes the current game to the next or previous game in a
     * list of games.
     *
     * @param event The event parameter is an enumeration of the EventType type,
     * which can have two possible values: GAMENEXT or GAMEPREV. This function is
     * used to change the current game being played by the Core object, either to
     * the next game in the list or to the previous game in the list, depending
     */
    void Core::setChangeGame(EventType event)
    {
        if (event == EventType::GAMENEXT) {
            if (this->_indexGame == this->_games.size() - 1) this->_indexGame = 0;
            else this->_indexGame++;
            this->changeGame(this->_games[this->_indexGame]);
        } else if (event == EventType::GAMEPREV) {
            if (this->_indexGame == 0) this->_indexGame = this->_games.size() - 1;
            else this->_indexGame--;
            this->changeGame(this->_games[this->_indexGame]);
        }
    }

    /**
     * The function checks if the game and library paths exist, and if so, changes
     * the game and library to the specified paths.
     *
     * @return If `tmp.gamePath` or `tmp.libPath` is empty, nothing is returned
     * and the function exits. If either of the paths is not a valid path, an
     * error message is printed and the function exits. If both paths are valid,
     * the `_menuInfo` variable is updated with the new paths and the `changeLib`
     * and `changeGame` functions are called. No value is
     */
    void Core::MenuGetChange()
    {
        MenuInfo tmp = this->game->getMenuInfo();
        if (tmp.gamePath == "" || tmp.libPath == "") {
            return;
        } else {
            if (!std::filesystem::exists(tmp.gamePath)) {
                std::cout << "Error: " << tmp.gamePath << " is not a valid path" << std::endl; return;
            } else if (!std::filesystem::exists(tmp.libPath)) {
                std::cout << "Error: " << tmp.libPath << " is not a valid path" << std::endl; return;
            }
            this->_menuInfo = tmp;
            this->changeLib(this->_menuInfo.libPath);
            this->changeGame(this->_menuInfo.gamePath);
        }
    }

    /**
     * The function changes the graphics library used by the program.
     *
     * @param lib A string representing the name of a dynamic link library (DLL)
     * that contains a graphic display implementation. This function is used to
     * switch between different graphic display implementations at runtime by
     * loading a new DLL and initializing it.
     */
    void Core::changeLib(std::string lib)
    {
        this->graphic->close();
        this->graphicDll->~DLLoader();
        this->graphicDll = new DLLoader(lib);
        this->setGraphic(this->graphicDll->getFunction<IDisplay>("entryPoint"));
        this->graphic->init(this->game->getAssets());
    }

    /**
     * The function changes the current game by closing the current game and
     * graphic, loading a new game DLL, initializing the new game and graphic, and
     * setting the menu information.
     *
     * @param game A string representing the name of the game to be loaded.
     */
    void Core::changeGame(std::string game)
    {
        this->game->close();
        this->gameDll->~DLLoader();
        this->gameDll = new DLLoader(game);
        this->setGame(this->gameDll->getFunction<IGame>("entryPoint"));
        this->game->setMenuInfo({this->_menuInfo.username, "", "" });
        this->game->init();
        this->graphic->close();
        this->graphic->init(this->game->getAssets());
    }
}
