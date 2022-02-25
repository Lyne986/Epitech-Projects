##
## EPITECH PROJECT, 2020
## Day10
## File description:
## Makefile
##

CC	=	gcc

LDFLAGS	=	-I./include -L./lib/my -lmy

all:
	make -C ./lib/my
	make -C ./corewar/
	make -C ./disasm/

clean:
	make clean -C ./lib/my
	make clean -C ./corewar/
	make clean -C ./disasm/

fclean: clean
	make fclean -C ./corewar/
	make fclean -C ./lib/my
	make fclean -C ./disasm/

re:	fclean all