##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC	=

MAIN = src/main.c

INCLUDE = include/

NAME	=	poke_anim

CFLAGS = $(INCLUDE:%=-I%) -g

CSFML = 	-lcsfml-graphics	\
			-lcsfml-system		\
			-lcsfml-audio		\
			-lcsfml-window

OBJ	=	$(SRC:.c=.o)

OBM =	$(MAIN:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ) $(OBM)
	gcc -o $(NAME) $(OBJ) $(OBM) $(CSFML)

clean:
	rm -f $(OBJ) $(OBM)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.SILENT:
