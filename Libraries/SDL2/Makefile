##
## EPITECH PROJECT, 2026
## Makefile
## File description:
## it does compile
##

NAME			=	../../lib/arcade_sdl2.so

SRC				=   SDL2.cpp                        						\
        			../../Abstract/ADisplay.cpp								\

OBJ				=    $(SRC:.cpp=.o)

CXXFLAGS		=    -Wall -Wextra -Werror -fPIC

all:    			$(OBJ)
					g++ -shared -o $(NAME) $(OBJ) -lSDL2 -lSDL2_image -lSDL2_ttf

clean:
					rm -f $(OBJ)

fclean: 			clean
					rm -f $(NAME)

re: 				fclean all

.PHONY: 			all clean fclean re
