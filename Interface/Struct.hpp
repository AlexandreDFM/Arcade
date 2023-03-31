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
    struct Drawable {
        int x;
        int y;
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

    enum Color {
        BLACK = 0x000000,
        RED = 0xFF0000,
        GREEN = 0x00FF00,
        BLUE = 0x0000FF,
        White = 0xFFFFFF
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
