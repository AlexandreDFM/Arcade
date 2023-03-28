##
## EPITECH PROJECT, 2026
## makefile
## File description:
## it does compile
##

NAME				=	arcade

LIB_NAME			=	lib/lib_arcade_

SRC					=	Main.cpp												\
						Abstract/ADisplay.cpp									\
						Abstract/AGame.cpp										\
						Usage/Usage.cpp											\
						Menu/Menu.cpp											\

CORE_SRC			=	Core/Core.cpp											\
#						Core/Loader.cpp											\
#						Core/Parser.cpp											\

GAMES_SRC			=	Games/Nibbler/Nibbler.cpp								\
						Games/Snake/Snake.cpp									\

GRAPHICALS_SRC		=	Libraries/NCurses/NCurses.cpp							\
						Libraries/SDL2/SDL2.cpp									\
						Libraries/SFML/SFML.cpp									\

GRAPHICALS_NCURSES	=	Libraries/NCurses/NCurses.cpp							\

##GRAPHICALS_SDL2		=	Libraries/SDL2/SDL2.cpp									\

GRAPHICALS_SFML		=	Libraries/SFML/SFML.cpp									\

OBJ_SRC				=	$(SRC:.cpp=.o)

OBJ_CORE			=	$(CORE_SRC:.cpp=.o)

OBJ_GAMES			=	$(GAMES_SRC:.cpp=.o)

OBJ_GRAPHICALS		=	$(GRAPHICALS_SRC:.cpp=.o)

OBJ_NCURSES			=	$(GRAPHICALS_NCURSES:.cpp=.o)

OBJ_SDL2			=	$(GRAPHICALS_SDL2:.cpp=.o)

OBJ_SFML			=	$(GRAPHICALS_SFML:.cpp=.o)

INCLUDE_SRC			=	-I./Interface/											\
						-I./Abstract/											\
						-I./Core/												\
						-I./Games/												\
						-I./DLLoarder/											\

INCLUDE_CORE		=	-I./Core/												\

INCLUDE_GAMES		=	-I./Games/Nibbler										\
						-I./Games/Snake											\

INCLUDE_GRAPHICALS	=	-I./Libraries/NCurses/									\
						-I./Libraries/SDL2/										\
						-I./Libraries/SFML/										\

INCLUDE_NCURSES		=	-I./Interface/											\
						-I./Libraries/NCurses/									\

INCLUDE_SDL2		=	-I./Libraries/SDL2/										\

INCLUDE_SFML		=	-I./Libraries/SFML/										\

FLAGS				=	-g3 -Wall -Wextra -lncurses -lSDL2 -lsfml-graphics -lsfml-window -lsfml-system

FLAGS_NCURSES		=	-g3 -Wall -Wextra -lncurses

FLAGS_SDL2			=	-g3 -Wall -Wextra -lSDL2

FLAGS_SFML			=	-g3 -Wall -Wextra -lsfml-graphics -lsfml-window -lsfml-system

all: 					lib_ncurses $(NAME)

$(NAME):				$(OBJ_SRC) $(OBJ_CORE)
						g++ -o $(NAME) -L./lib $(OBJ_SRC) $(OBJ_CORE)			\

core: 					$(OBJ_CORE)
						g++ -o $(NAME) $(OBJ_CORE) $(INCLUDE_CORE) $(FLAGS)

lib_ncurses:
						g++ -o ./lib/Ncurses.o -c -fpic $(FLAGS_NCURSES)		\
						$(GRAPHICALS_NCURSES) &&								\
						g++ -shared -o $(LIB_NAME)ncurses.so ./lib/Ncurses.o	\

##lib_sdl2:				$(OBJ)
##						g++ -shared -o $(LIB_NAME)sdl2.so $(OBJ_SDL2)			\
##						$(INCLUDE_SDL2) $(FLAGS)
##
lib_sfml:				$(OBJ)
						g++ -shared -o $(LIB_NAME)sfml.so $(OBJ_SFML)			\
						$(INCLUDE_SFML) $(FLAGS)

games: 					lib_ncurses lib_sdl2 lib_sfml

graphicals: 			$(OBJ)
						g++ -o $(NAME) $(OBJ_GRAPHICALS) $(INCLUDE_GRAPHICALS)	\
						$(FLAGS)

clean:
						rm -f $(OBJ_SRC)
						rm -f $(OBJ_CORE)
						rm -f $(OBJ_GAMES)
						rm -f $(OBJ_GRAPHICALS)

fclean: 				clean
						rm -f $(NAME)

re: 					fclean all $(NAME)

.PHONY: 				all clean fclean re
