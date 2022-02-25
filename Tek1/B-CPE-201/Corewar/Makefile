##
## EPITECH PROJECT, 2020
## Day10
## File description:
## Makefile
##

CC	=	gcc

SRCS		= ./asm/parse_asm_info.c	\
			./asm/parse_command.c		\
			./asm/split_string.c		\
			./asm/utilities.c			\
			./asm/linked_list.c			\
			./asm/print_champion.c		\
			./asm/update_parameters.c	\
			./asm/search_label.c	\
			./asm/init_parsing.c	\
			./asm/error_handling.c	\
			./tests/asm_tests.c		\

LDFLAGS	=	-I./include -L./lib/my -lmy

all:
	make -C ./lib/my
	make -C ./asm/
	make -C ./corewar/

tests_run: fclean
		make -C ./lib/my
		$(CC) $(SRCS) --coverage -lcriterion -o unit_tests $(LDFLAGS)
		./unit_tests
		gcovr --exclude="tests"
		gcovr --exclude="tests" --branches

clean:
	make clean -C ./lib/my
	make clean -C ./asm/
	make clean -C ./corewar/
	$(RM) *.gc*

fclean: clean
	make fclean -C ./asm/
	make fclean -C ./corewar/
	make fclean -C ./lib/my
	$(RM) unit_tests

re:	fclean all