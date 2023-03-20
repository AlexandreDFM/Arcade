/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-arcade-roman.lopes
** File description:
** SFML
*/

#include "SFML.hpp"

SFML::SFML()
{
}

SFML::~SFML()
{
}

void SFML::init()
{
    this->window->create(sf::VideoMode(800, 600), "SFML window");
    this->font.loadFromFile("arial.ttf");
    this->text.setFont(this->font);
    this->text.setCharacterSize(24);
    this->text.setStyle(sf::Text::Bold);
}

int SFML::getEvent()
{
    return 1;
}

void SFML::update()
{
    this->window->clear();
    this->window->display();
}

void SFML::drawText(std::string text, int x, int y)
{
    this->text.setString(text);
    this->text.setPosition(x, y);
    this->window->draw(this->text);
}
