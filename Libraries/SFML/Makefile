##
## EPITECH PROJECT, 2026
## makefile
## File description:
## it does compile
##

NAME			=	../../lib/arcade_sfml.so

SRC				=   SFML.cpp                        						\
        			../../Abstract/ADisplay.cpp								\

OBJ				=    $(SRC:.cpp=.o)

CXXFLAGS		=    -Wall -Wextra -Werror -fPIC

all:    			$(OBJ)
					g++ -shared -o ${NAME} $(OBJ) -lsfml-graphics -lsfml-window -lsfml-system

clean:
					rm -f $(OBJ)

fclean: 			clean
					rm -f $(NAME)

re: 				fclean all

.PHONY: 			all clean fclean re
