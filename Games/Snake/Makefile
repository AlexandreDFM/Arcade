##
## EPITECH PROJECT, 2026
## makefile
## File description:
## it does compile
##

NAME			=	../../lib/arcade_snake.so

SRC				=   Snake.cpp                        						\
        			../../Abstract/AGame.cpp								\

OBJ				=    $(SRC:.cpp=.o)

CXXFLAGS		=    -Wall -Wextra -Werror -fPIC

all:    			$(OBJ)
					g++ -shared -o $(NAME) $(OBJ)

clean:
					rm -f $(OBJ)

fclean: 			clean
					rm -f $(NAME)

re: 				fclean all

.PHONY: 			all clean fclean re
