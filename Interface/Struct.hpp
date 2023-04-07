/*
** EPITECH PROJECT, 2026
** Arkade
** File description:
** Created by victor delamonica et dieu
*/

#ifndef STRUCT_HPP_
    #define STRUCT_HPP_

    #include <map>
    #include <vector>
    #include <iostream>
    #include <filesystem>

namespace Arcade {
    enum Color {
        BLACK = 1,
        RED,
        GREEN,
        BLUE,
        WHITE,
        MAGENTA,
        CYAN,
        YELLOW,
    };

    enum EventType {
        NOTHING,
        UP,
        DOWN,
        RIGHT,
        LEFT,
        LIBPREV,
        LIBNEXT,
        GAMEPREV,
        GAMENEXT,
        CLOSE,
        RESTART,
        ACTION1,
        ACTION2,
        MENU,
        SAVE
    };

    enum Direction {
        NO_DIRECTION,
        NORTH,
        SOUTH,
        EAST,
        WEST
    };

    struct Rect {
        int left;
        int top;
        int width;
        int height;
    };
    struct Drawable {
        int x;
        int y;
        Color color;
        char draw;
        enum Direction rotation = NO_DIRECTION;
        struct Rect rect = {0, 0, 0, 0};
    };

    struct MenuInfo {
        std::string game_path;
        std::string lib_path;
    };
    struct DrawableText {
        int x;
        int y;
        int size;
        Color color;
        std::string text;
        std::string font;
        enum Direction rotation = NO_DIRECTION;
    };
}

#endif /*STRUCT_HPP_*/
