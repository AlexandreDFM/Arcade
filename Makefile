##
## EPITECH PROJECT, 2026
## makefile
## File description:
## it does compile
##

NAME		=	arcade

SRC			=	Main.cpp														\
				Abstract/ADisplayModule.cpp										\
				Abstract/AGameModule.cpp										\
				Games/NibblerGame.cpp											\
				Games/SnakeGame.cpp												\
				Usage/Usage.cpp												\
				Menu/Menu.cpp													\

OBJ			=	$(SRC:.cpp=.o)

INCLUDE		=	-I./Interface/													\
				-I./Abstract/													\
				-I./Core/														\
				-I./Games/														\

FLAGS		=	-g3 -Wall -Wextra

all: 		$(NAME)

$(NAME):	$(OBJ)
			g++ -o $(NAME) $(OBJ) $(FLAGS) $(INCLUDE)

clean:
			rm -f $(OBJ)

fclean: 	clean
			rm -f $(NAME)
			rm -f $(MAINOBJ)

re: 		fclean all $(NAME)

.PHONY: 	all clean fclean re
