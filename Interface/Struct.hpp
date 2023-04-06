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
        WHITE
    };

    enum SpriteDirection {
        NO_DIRECTION,
        NORTH,
        SOUTH,
        EAST,
        WEST
    };

    struct Drawable {
        int x;
        int y;
        enum SpriteDirection rotation;
        Color color;
        char draw;
    };

    struct DrawableText {
        int x;
        int y;
        int size;
        int color;
        std::string text;
        std::string font;
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
        ACTION2
    };
}

#endif /*STRUCT_HPP_*/
