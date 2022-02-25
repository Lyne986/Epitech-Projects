##
## EPITECH PROJECT, 2020
## Corewar
## File description:
## Makefile
##

CC	=	gcc

SRC		=	main.c	\
			parse_asm_info.c	\
			parse_command.c	\
			split_string.c	\
			utilities.c	\
			linked_list.c	\
			print_champion.c	\
			update_parameters.c	\
			search_label.c	\
			init_parsing.c	\
			error_handling.c	\


OBJ		= $(SRC:.c=.o)

NOM		=	asm

LDFLAGS	=	-I./../include -L./../lib/my -lmy

CFLAGS	=	-W -Wall -Wextra

all:	$(NOM)

$(NOM):	$(OBJ)
	$(CC) $(OBJ) -o $(NOM) $(LDFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NOM)

re:	fclean all