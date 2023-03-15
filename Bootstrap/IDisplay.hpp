/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-arcade-roman.lopes
** File description:
** IDisplay
*/

#ifndef IDISPLAY_HPP_
#define IDISPLAY_HPP_

#include <string>

class IDisplayModule {
public:
    virtual ~IDisplayModule() = default;
    virtual void init() = 0;
    virtual void stop() = 0;
    virtual const std::string& getName() const = 0;
};

#endif /* !IDISPLAY_HPP_ */
