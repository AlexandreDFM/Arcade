//
// Created by wino on 3/22/23.
//

#ifndef B_OOP_400_NCE_4_1_ARCADE_ROMAN_LOPES_STRUCT_HPP
#define B_OOP_400_NCE_4_1_ARCADE_ROMAN_LOPES_STRUCT_HPP

#include <iostream>

struct drawable {
    int x;
    int y;
    char draw;
};

struct drawableText{
    int x;
    int y;
    std::string text;
    std::string font;
    int size;
};
#endif //B_OOP_400_NCE_4_1_ARCADE_ROMAN_LOPES_STRUCT_HPP
