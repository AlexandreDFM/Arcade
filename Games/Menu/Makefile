##
## EPITECH PROJECT, 2026
## makefile
## File description:
## it does compile
##

NAME			=	../../lib/arcade_menu.so

SRC				=   Menu.cpp                        						\
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
