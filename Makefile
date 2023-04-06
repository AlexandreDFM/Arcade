##
## EPITECH PROJECT, 2026
## makefile
## File description:
## it does compile
##

NAME				=	arcade

LIB_NAME			=	lib/arcade_

CORE_SRC			=	Main.cpp												\
						Core/Core.cpp											\
						Usage/Usage.cpp											\

OBJ_CORE			=	$(CORE_SRC:.cpp=.o)

INCLUDE_CORE		=	-I./Core/												\
						-I./Interface/											\
						-I./Games/												\
						-I./Abstract/											\
						-I./DLLoarder/											\

CXXFLAGS			=	-g3 -Wall -Wextra -Werror

all: 					core graphicals games

core: 					$(OBJ_CORE)
						g++ -o $(NAME) $(OBJ_CORE) $(INCLUDE_CORE)

lib_ncurses:
						make -C Libraries/NCurses/

lib_sdl2:
						make -C Libraries/SDL2/

lib_sfml:
						make -C Libraries/SFML/

graphicals: 			lib_ncurses lib_sfml lib_sdl2

menu:
						make -C Games/Menu/

snake:
						make -C Games/Snake/

nibbler:
						make -C Games/Nibbler/

games: 					menu snake nibbler

clean:
						rm -f $(OBJ_CORE)
						make -C Libraries/NCurses/ clean
						make -C Libraries/SDL2/ clean
						make -C Libraries/SFML/ clean
						make -C Games/Menu/ clean
						make -C Games/Snake/ clean
						make -C Games/Nibbler/ clean

fclean: 				clean
						rm -f $(NAME)
						rm -f ./lib/*.so

re: 					fclean all $(NAME)

.PHONY: 				all clean fclean re core graphicals games menu snake nibbler lib_ncurses lib_sdl2 lib_sfml
