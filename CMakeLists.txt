cmake_minimum_required(VERSION 3.24)
project(B_OOP_400_NCE_4_1_arcade_roman_lopes)

set(CMAKE_CXX_STANDARD 14)

include_directories(Abstract)
include_directories(Bootstrap)
include_directories(Core)
include_directories(Games/Nibbler)
include_directories(Games/Snake)
include_directories(Interface)
include_directories(Libraries/NCurses)
include_directories(Libraries/SDL2)
include_directories(Libraries/SFML)
include_directories(Menu)
include_directories(Usage)

add_executable(B_OOP_400_NCE_4_1_arcade_roman_lopes
        Abstract/ADisplay.cpp
        Abstract/ADisplay.hpp
        Abstract/AGame.cpp
        Abstract/AGame.hpp
        Bootstrap/dllLoader.hpp
        Bootstrap/libmylib.cpp
        Bootstrap/main.cpp
        Core/Core.cpp
        Core/Core.hpp
        Games/Nibbler/Nibbler.cpp
        Games/Nibbler/Nibbler.hpp
        Games/Snake/Snake.cpp
        Games/Snake/Snake.hpp
        Interface/IGame.hpp
        Interface/IDisplay.hpp
        Libraries/NCurses/NCurses.cpp
        Libraries/NCurses/NCurses.hpp
        Libraries/SDL2/SDL2.cpp
        Libraries/SDL2/SDL2.hpp
        Libraries/SFML/SFML.cpp
        Libraries/SFML/SFML.hpp
        Menu/Menu.cpp
        Menu/Menu.hpp
        Usage/Usage.cpp
        Usage/Usage.hpp
        Main.cpp)
