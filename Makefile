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
						Abstract/AGame.cpp										\

GAMES_NIBBLER		=	Games/Nibbler/Nibbler.cpp								\
						Abstract/AGame.cpp										\

GAMES_SNAKE			=	Games/Snake/Snake.cpp									\
						Abstract/AGame.cpp										\

GRAPHICALS_SRC		=	Libraries/NCurses/NCurses.cpp							\
						Libraries/SDL2/SDL2.cpp									\
						Libraries/SFML/SFML.cpp									\

GRAPHICALS_NCURSES	=	Abstract/ADisplay.cpp									\
						Libraries/NCurses/NCurses.cpp							\

GRAPHICALS_SDL2		=	Libraries/SDL2/SDL2.cpp									\
						Abstract/ADisplay.cpp									\

GRAPHICALS_SFML		=	Libraries/SFML/SFML.cpp									\
						Abstract/ADisplay.cpp									\

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
						-I./Abstract/											\
						-I./Interface/											\

INCLUDE_NIBBLER		=	-I./Interface/											\
						-I./Abstract/											\
						-I./Games/Nibbler/										\

INCLUDE_SNAKE		=	-I./Interface/											\
						-I./Abstract/											\
						-I./Games/Snake/										\

INCLUDE_NCURSES		=	-I./Interface/											\
						-I./Abstract/											\
						-I./Libraries/NCurses/									\

INCLUDE_SDL2		=	-I./Interface/											\
						-I./Abstract/											\
						-I./Libraries/SDL2/										\

INCLUDE_SFML		=	-I./Interface/											\
						-I./Abstract/											\
						-I./Libraries/SFML/										\

FLAGS				=	-g3 -Wall -Wextra -Werror

FLAGS_NCURSES		=	-Wall -Wextra -lncurses

FLAGS_SDL2			=	-Wall -Wextra -lSDL2 -lSDL2_image -lSDL2_ttf

FLAGS_SFML			=	-Wall -Wextra -lsfml-graphics -lsfml-window -lsfml-system

all: 					core graphicals games

core: 					$(OBJ_CORE)
						g++ -o $(NAME) $(OBJ_CORE) $(INCLUDE_CORE) $(FLAGS)

lib_ncurses:
						g++ -shared -o $(LIB_NAME)ncurses.so -fpic				\
						$(FLAGS_NCURSES) $(GRAPHICALS_NCURSES)

lib_sdl2:
						g++ -shared -o $(LIB_NAME)sdl2.so -fpic					\
						$(FLAGS_SDL2) $(GRAPHICALS_SDL2)

lib_sfml:
						g++ -shared -o $(LIB_NAME)sfml.so -fpic					\
						${FLAGS_SFML} $(GRAPHICALS_SFML)

graphicals: 			lib_ncurses lib_sfml lib_sdl2

menu:
						g++ -shared -o $(LIB_NAME)menu.so -fpic					\
						$(FLAGS) $(GAMES_MENU)

snake:
						g++ -shared -o $(LIB_NAME)snake.so -fpic				\
						$(FLAGS) $(GAMES_SNAKE)

nibbler:
						g++ -shared -o $(LIB_NAME)nibbler.so -fpic				\
						$(FLAGS) $(GAMES_NIBBLER)

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

fclean: 				clean
						rm -f $(NAME)
						rm -f ./lib/*.so

re: 					fclean all $(NAME)

.PHONY: 				all clean fclean re core graphicals games menu snake nibbler lib_ncurses lib_sdl2 lib_sfml
