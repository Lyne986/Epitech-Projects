##
## EPITECH PROJECT, 2020
## libmy
## File description:
## makefile
##

### COLORS ###
NOC            = \033[0m
BOLD        = \033[1m
UNDERLINE    = \033[4m
BLACK        = \033[1;30m
RED            = \033[1;31m
GREEN        = \033[1;32m
YELLOW        = \033[1;33m
BLUE        = \033[1;34m
VIOLET        = \033[1;35m
CYAN        = \033[1;36m
WHITE        = \033[1;37m

CC			= gcc

CFLAGS		= -W -Wall -Wextra -I./include -g3

SRC			= 	./src/main.c	\
				./src/handle_map.c	\
				./src/handle_errors.c	\
				./src/handle_moves.c	\
				./src/handle_obstacle_moves.c \
				./src/game_loop.c \
				./src/game_status.c	\
				./src/display_usage.c	\

SRC2		=	./tests/test_sokoban.c	\
				./src/handle_map.c	\
				./src/handle_errors.c	\
				./src/handle_moves.c	\
				./src/handle_obstacle_moves.c \
				./src/game_loop.c \
				./src/game_status.c	\
				./src/display_usage.c	\

OBJ			=	$(SRC:.c=.o)

OBJ2		=	$(SRC2:.c=.o)

TARGET		=	my_sokoban

COMPIL		=	make -C ./lib/my

CLEAN		= make fclean -C ./lib/my

LIB			=	libmy.a

all:    $(TARGET)

$(TARGET):  $(OBJ)
			$(COMPIL)
			$(CC) $(OBJ) -L./lib/my -lmy -lncurses -o $(TARGET)

tests_run:
			$(COMPIL)
			$(CC) $(SRC2) -I./include -L./lib/my -lmy -lncurses --coverage -lcriterion -o unit_tests
			./unit_tests
			gcovr --exclude="tests"

clean:
		$(RM) $(TARGET)
		$(RM) $(OBJ)
		$(RM) $(OBJ2)
		$(RM) unit_tests
		$(RM) *.g*
		$(RM) *~
		$(RM) #*#

fclean:	clean
		make fclean -C ./lib/my

re:	fclean all
