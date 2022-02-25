##
## EPITECH PROJECT, 2020
## Corewar
## File description:
## Makefile
##

CC	=	gcc

SRC		=	main.c 				\
			error_handling/error_handling.c 	\
			error_handling/handle_dashes.c	\
			champion/parse_champion_cor.c		\
			init_core.c	\
			utilities.c	\
			get_champion_infos.c	\
			arena_handling/parse_instruction.c	\
			arena_handling/update_arena.c	\
			arena_handling/put_champion.c		\
			arena_handling/arena_placing_errors.c	\
			champion_utilities.c	\
			instructions/add_sub.c	\
			instructions/aff_and.c	\
			instructions/fork_lfork.c	\
			instructions/st_sti.c	\
			instructions/live.c	\
			instructions/lld_lldi.c	\
			instructions/ld_ldi.c	\
			instructions/or_xor.c	\
			instructions/zjmp.c	\
			instructions/utilities_instructions.c	\

OBJ		= $(SRC:.c=.o)

NOM		=	corewar

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