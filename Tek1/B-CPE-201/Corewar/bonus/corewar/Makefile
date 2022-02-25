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
			history/load_history_file.c	\
			history/write_history_file.c	\
			csfml/print_arena.c	\
			csfml/event.c	\
			csfml/final_scene.c	\
			csfml/init_csfml.c	\
			csfml/fill_champ_text.c	\
			csfml/buttons.c	\
			arena_handling/parse_instruction.c	\
			arena_handling/update_arena.c	\
			arena_handling/put_champion.c		\
			arena_handling/arena_placing_errors.c	\
			csfml/menu.c	\
			csfml/menu_two.c	\
			csfml/params.c	\
			csfml/how.c \
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
			csfml/get_instruction_info.c	\
			csfml/second_init.c	\

OBJ		= $(SRC:.c=.o)

NOM		=	corewar

LDFLAGS	=	-I./../include -L./../lib/my -lmy -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

CFLAGS	=	-W -Wall -Wextra

all:	$(NOM)

$(NOM):	$(OBJ)
	$(CC) $(OBJ) -o $(NOM) $(LDFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NOM)

re:	fclean all