##
## EPITECH PROJECT, 2020
## Corewar
## File description:
## Makefile
##

CC	=	gcc -g3

SRC		=	main.c 					\
			get_champion_infos.c	\
			printer.c				\
			utilities.c				\
			parse_champion_cor.c

OBJ		= $(SRC:.c=.o)

NOM		=	disasm

LDFLAGS	=	-I./include -L./../lib/my -lmy -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

CFLAGS	=	-W -Wall -Wextra

all:	$(NOM)

$(NOM):	$(OBJ)
	make -C ../lib/my
	$(CC) $(OBJ) -o $(NOM) $(LDFLAGS)

clean:
	make clean -C ../lib/my
	$(RM) $(OBJ)

fclean: clean
	make fclean -C ../lib/my
	$(RM) $(NOM)

re:	fclean all
	make re -C ../lib/my