##
## EPITECH PROJECT, 2026
## makefile
## File description:
## it does compile
##

NAME				=	arcade

LIB_NAME			=	lib/arcade_

CORE_SRC			=	Main.cpp												\
						Abstract/ADisplay.cpp									\
						Abstract/AGame.cpp										\
						Usage/Usage.cpp											\
						Menu/Menu.cpp											\
						Core/Core.cpp											\

GAMES_MENU			=	Menu/Menu.cpp											\

GAMES_NIBBLER		=	Games/Nibbler/Nibbler.cpp								\

GAMES_SNAKE			=	Games/Snake/Snake.cpp									\

GRAPHICALS_SRC		=	Libraries/NCurses/NCurses.cpp							\
						Libraries/SDL2/SDL2.cpp									\
						Libraries/SFML/SFML.cpp									\

GRAPHICALS_NCURSES	=	Libraries/NCurses/NCurses.cpp							\

GRAPHICALS_SDL2		=	Libraries/SDL2/SDL2.cpp									\

GRAPHICALS_SFML		=	Libraries/SFML/SFML.cpp									\

OBJ_CORE			=	$(CORE_SRC:.cpp=.o)

OBJ_NCURSES			=	$(GRAPHICALS_NCURSES:.cpp=.o)

OBJ_SDL2			=	$(GRAPHICALS_SDL2:.cpp=.o)

OBJ_SFML			=	$(GRAPHICALS_SFML:.cpp=.o)

OBJ_MENU			=	$(GAMES_MENU:.cpp=.o)

OBJ_NIBBLER			=	$(GAMES_NIBBLER:.cpp=.o)

OBJ_SNAKE			=	$(GAMES_SNAKE:.cpp=.o)

INCLUDE_CORE		=	-I./Core/												\
						-I./Interface/											\
						-I./Games/												\
						-I./Abstract/											\
						-I./DLLoarder/											\

INCLUDE_MENU		=	-I./Menu												\
						-I./Interface/											\

INCLUDE_NIBBLER		=	-I./Interface/											\
						-I./Games/Nibbler/										\

INCLUDE_SNAKE		=	-I./Interface/											\
						-I./Games/Snake/										\

INCLUDE_NCURSES		=	-I./Interface/											\
						-I./Libraries/NCurses/									\

INCLUDE_SDL2		=	-I./Interface/											\
						-I./Libraries/SDL2/										\

INCLUDE_SFML		=	-I./Interface/											\
						-I./Libraries/SFML/										\

FLAGS				=	-g3 -Wall -Wextra -Werror

FLAGS_NCURSES		=	-Wall -Wextra -lncurses

FLAGS_SDL2			=	-Wall -Wextra -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer

FLAGS_SFML			=	-Wall -Wextra -lsfml-graphics -lsfml-window -lsfml-system

all: 					core graphicals games

core: 					$(OBJ_CORE)
						g++ -o $(NAME) $(OBJ_CORE) $(INCLUDE_CORE) $(FLAGS)

lib_ncurses:
						g++ -o ./lib/Ncurses.o -c -fpic $(FLAGS_NCURSES)		\
						$(GRAPHICALS_NCURSES) &&								\
						g++ -shared -o $(LIB_NAME)ncurses.so ./lib/Ncurses.o	\

lib_sdl2:
						g++ -o ./lib/SDL2.o -c -fpic $(FLAGS_SDL2)				\
						$(GRAPHICALS_SDL2) &&									\
						g++ -shared -o $(LIB_NAME)sdl2.so ./lib/SDL2.o			\

lib_sfml:
						g++ -o ./lib/SFML.o -c -fpic ${FLAGS_SFML}				\
						$(GRAPHICALS_SFML) &&									\
						g++ -shared -o $(LIB_NAME)sfml.so ./lib/SFML.o			\

graphicals: 			lib_ncurses lib_sfml lib_sdl2

menu:
						g++ -o ./lib/Menu.o -c -fpic $(FLAGS)					\
						$(GAMES_MENU) &&										\
						g++ -shared -o $(LIB_NAME)menu.so ./lib/Menu.o			\

snake:
						g++ -o ./lib/Snake.o -c -fpic $(FLAGS)					\
						$(GAMES_SNAKE) &&										\
						g++ -shared -o $(LIB_NAME)snake.so ./lib/Snake.o		\

nibbler:
						g++ -o ./lib/Nibbler.o -c -fpic $(FLAGS)				\
						$(GAMES_NIBBLER) &&										\
						g++ -shared -o $(LIB_NAME)nibbler.so ./lib/Nibbler.o	\

games: 					menu snake nibbler

clean:
						rm -f $(OBJ_CORE)
						rm -f $(OBJ_NCURSES)
						rm -f $(OBJ_SDL2)
						rm -f $(OBJ_SFML)
						rm -f $(OBJ_MENU)
						rm -f $(OBJ_NIBBLER)
						rm -f $(OBJ_SNAKE)
						rm -f ./lib/*.o
						rm -f ./lib/*.so

fclean: 				clean
						rm -f $(NAME)

re: 					fclean all $(NAME)

.PHONY: 				all clean fclean re core graphicals games menu snake nibbler lib_ncurses lib_sdl2 lib_sfml
