/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-arcade-roman.lopes
** File description:
** Usage
*/

#ifndef USAGE_HPP_
#define USAGE_HPP_

#include <iostream>
#include <string>

class Usage {
    public:
        Usage();
        ~Usage() = default;
        void CheckUsage(int ac, char **av);
        static void DisplayUsage();
        void CheckLib(char **av);
    protected:
    private:
};

#endif /* !USAGE_HPP_ */
