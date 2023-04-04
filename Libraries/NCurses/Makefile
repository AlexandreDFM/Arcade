##
## EPITECH PROJECT, 2026
## makefile
## File description:
## it does compile
##

NAME			=	../../lib/arcade_ncurses.so

SRC				=   NCurses.cpp                        						\
        			../../Abstract/ADisplay.cpp								\

OBJ				=    $(SRC:.cpp=.o)

CXXFLAGS		=    -Wall -Wextra -Werror -fPIC

all:    			$(OBJ)
					g++ -shared -o ${NAME} $(OBJ) -lncurses

clean:
					rm -f $(OBJ)

fclean: 			clean
					rm -f $(NAME)

re: 				fclean all

.PHONY: 			all clean fclean re
