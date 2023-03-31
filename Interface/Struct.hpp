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
        EMPTY,
        BLACK,
        RED,
        GREEN,
        BLUE,
        WHITE
    };

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
