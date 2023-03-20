##
## EPITECH PROJECT, 2026
## makefile
## File description:
## it does compile
##

NAME				=	arcade

SRC					=	Main.cpp												\
						Abstract/ADisplayModule.cpp								\
						Abstract/AGameModule.cpp								\
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

OBJ_SRC				=	$(SRC:.cpp=.o)

OBJ_CORE			=	$(CORE_SRC:.cpp=.o)

OBJ_GAMES			=	$(GAMES_SRC:.cpp=.o)

OBJ_GRAPHICALS		=	$(GRAPHICALS_SRC:.cpp=.o)

INCLUDE_SRC			=	-I./Interface/											\
						-I./Abstract/											\
						-I./Core/												\
						-I./Games/												\

INCLUDE_CORE		=	-I./Core/												\

INCLUDE_GAMES		=	-I./Games/Nibbler										\
						-I./Games/Snake											\

INCLUDE_GRAPHICALS	=	-I./Libraries/NCurses/									\
						-I./Libraries/SDL2/										\
						-I./Libraries/SFML/										\

FLAGS				=	-g3 -Wall -Wextra -lncurses -lSDL2 -lsfml-graphics -lsfml-window -lsfml-system

all: 					$(NAME)

$(NAME):				$(OBJ_SRC) $(OBJ_CORE) $(OBJ_GAMES) $(OBJ_GRAPHICALS)
						g++ -o $(NAME)	$(OBJ_SRC) $(OBJ_CORE) $(OBJ_GAMES)		\
						$(OBJ_GRAPHICALS) $(INCLUDE_SRC) $(INCLUDE_CORE)		\
						$(INCLUDE_GAMES) $(INCLUDE_GRAPHICALS) $(FLAGS)

core: 					$(OBJ_CORE)
						g++ -o $(NAME) $(OBJ_CORE) $(INCLUDE_CORE) $(FLAGS)

games: 					$(OBJ)
						g++ -o $(NAME) $(OBJ_GAMES) $(INCLUDE_GAMES) $(FLAGS)

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
