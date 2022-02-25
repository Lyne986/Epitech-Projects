##
## EPITECH PROJECT, 2020
## libmy.a
## File description:
## Makefile
##

CC	= 	gcc

SRC1	=	${wildcard *.c}

OBJ1	=	$(SRC1:.c=.o)

LIB	=	libmy.a

CFLAGS	=	-W -Wall -Wextra -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

all:	$(LIB)

$(LIB): $(OBJ1)
	$(AR) rsc $(LIB) $(OBJ1)

clean:
	$(RM) $(OBJ1)

fclean: clean
	$(RM) -f $(NAME)
	$(RM) $(LIB)

re:	fclean all