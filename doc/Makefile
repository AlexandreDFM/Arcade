##
## EPITECH PROJECT, 2023
## B-NWP-400-NCE-4-1-myteams-roman.lopes
## File description:
## Makefile
##

NAME	=	documentation

SRC 	=	./src/main.tex													   \

all:
			pdflatex -output-directory ./src ./src/$(NAME).tex
			mv ./src/$(NAME).pdf ./$(NAME).pdf

clean:
			rm -rf ./src/*.aux
			rm -rf ./src/*.log
			rm -rf ./src/*.out

fclean:		clean
			rm -rf ./$(NAME).pdf

re:			fclean all

.PHONY:		all clean fclean re
