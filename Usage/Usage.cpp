/*
** EPITECH PROJECT, 2023
** B-OOP-400-NCE-4-1-arcade-roman.lopes
** File description:
** Usage
*/

#include "Usage.hpp"

/**
 * The function Error() sets an error message based on the type of error passed as
 * an argument.
 *
 * @param type The parameter "type" is an enum type variable of ErrorType, which
 * is used to determine the type of error that occurred. It can have two possible
 * values: LIB or GAME.
 */
Usage::Error::Error(ErrorType type)
{
    switch (type) {
        case LIB:
            _message = "Error: Library not found";
            break;
        case GAME:
            _message = "Error: Game not found";
            break;
    }
}

/**
 * This function returns the error message associated with an exception.
 *
 * @return A constant reference to a string object, which is the error message
 * stored in the private member variable `_message`.
 */
const std::string &Usage::Error::what() const
{
    return _message;
}

/**
 * The function displays the usage and controls for a program.
 */
void Usage::DisplayUsage()
{
    std::cout << "USAGE" << std::endl;
    std::cout << "\t./arcade Libraries" << std::endl;
    std::cout << "DESCRIPTION" << std::endl;
    std::cout << "\tLibraries\t\tlibrary in which the game will be played" << std::endl << std::endl;
    std ::cout << "\tEscape Key\t\tClose the program" << std::endl;
    std::cout << "\tArrow Keys\t\tFor movements in game" << std::endl;
    std::cout << "\tSpace Key\t\tFor reset games" << std::endl;
    std::cout << "\tM Key\t\t\tFor graphical next library" << std::endl;
    std::cout << "\tL Key\t\t\tFor graphical previous library" << std::endl;
    std::cout << "\tO Key\t\t\tFor game previous library" << std::endl;
    std::cout << "\tP Key\t\t\tFor game next library" << std::endl;
    std::cout << "\tR Key\t\t\tFor validate choices in menu and action1" << std::endl;
    std::cout << "\tE Key\t\t\tFor action2" << std::endl;
    std::cout << "\\T Key\t\t\tFor saving the game" << std::endl;
    std::cout << "\tY Key\t\t\tFor going back to menu" << std::endl;
}

/**
 * The function checks the command line arguments and displays usage information
 * or exits the program with an error code.
 *
 * @param ac `ac` is an integer representing the number of arguments passed to the
 * program from the command line.
 * @param av `av` is a pointer to a character array, which represents the command
 * line arguments passed to the program. Each element of the array is a string
 * containing one of the arguments. In this case, `av` is being used to check if
 * the second argument is "-h" to display the usage
 */
void Usage::CheckUsage(int ac, char **av)
{
    if (ac != 2) {
        Usage::DisplayUsage();
        exit(84);
//        throw Usage::Error(Usage::Error::LIB);
    }
    if (std::string(av[1]) == "-h") {
        DisplayUsage();
        exit (0);
    }
}

/**
 * The function checks if the input library file has a ".so" extension and throws
 * an error if it doesn't.
 *
 * @param av `av` is a pointer to a character array (i.e., a string array) that
 * contains the command line arguments passed to the program. The first element of
 * this array (`av[0]`) is typically the name of the program itself, and
 * subsequent elements (`av[1]`, `
 */
void Usage::CheckLib(char **av)
{
    std::string lib = av[1];
    if (lib.find(".so") == std::string::npos) {
        DisplayUsage(); throw Usage::Error(Usage::Error::LIB);
    }
}
