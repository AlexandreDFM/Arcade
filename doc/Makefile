##
## EPITECH PROJECT, 2023
## B-NWP-400-NCE-4-1-myteams-roman.lopes
## File description:
## Makefile
##

NAME	=	documentation

SRC 	=	./src/main.tex													   \

all:
			latexmk -f -cd -lualatex -silent src/$(NAME).tex				   \
			&& mv ./src/$(NAME).pdf ./$(NAME).pdf

clean:
			rm -rf ./src/*.aux
			rm -rf ./src/*.log
			rm -rf ./src/*.out
			rm -rf ./src/*.fdb_latexmk
			rm -rf ./src/*.fls
			rm -rf ./src/*.markdown.in
			rm -rf ./src/_markdown_documentation

fclean:		clean
			rm -rf ./$(NAME).pdf

re:			fclean all

.PHONY:		all clean fclean re
