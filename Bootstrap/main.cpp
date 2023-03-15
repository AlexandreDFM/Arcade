/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-arcade-roman.lopes
** File description:
** main
*/

#include <iostream>
#include "dllLoader.hpp"

int main() {
    DLLoader<IDisplayModule> loader("./libmylib.so");
    auto instance = loader.getInstance("create_display_module");
    instance->init();
    instance->getName();
    instance->stop();
    instance->~IDisplayModule();
    return 0;
}
