///*
//** EPITECH PROJECT, 2023
//** B-OOP-400-NCE-4-1-arcade-roman.lopes
//** File description:
//** libmylib
//*/
//
//#include <iostream>
//#include "IDisplay.hpp"
//
//class DisplayModule : public Arcade::ADisplay {
//    public:
//        DisplayModule() { std::cout << "DisplayModuleA created" << std::endl; }
//        ~DisplayModule() { std::cout << "DisplayModuleA destroyed" << std::endl; }
//        void init() override { std::cout << "DisplayModuleA initialized" << std::endl; }
//        void stop() override { std::cout << "DisplayModuleA stopped" << std::endl; }
//        const std::string& getName() const override { static const std::string name = "DisplayModuleA"; return name; }
//};
//
//extern "C" DisplayModule* create_display_module() {
//    return new DisplayModule();
//}
