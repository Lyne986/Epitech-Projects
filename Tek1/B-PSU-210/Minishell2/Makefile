##
## EPITECH PROJECT, 2020
## libmy.a
## File description:
## Makefile
##

CC    =     gcc

SRC1    =    lib/my/str_toword_array.c	\
			lib/my/my_strncpy.c	\
			lib/my/my_strncmp.c	\
			lib/my/my_strncat.c	\
			lib/my/my_strlen.c	\
			lib/my/my_strcpy.c	\
			lib/my/my_strcmp.c	\
			lib/my/my_strcat.c	\
			lib/my/my_putstr.c	\
			lib/my/my_put_nbr.c	\
			lib/my/my_putchar.c	\
			lib/my/my_getnbr.c	\
			lib/my/my_memset.c	\
			lib/my/my_strdup.c	\
			lib/my/printf/my_put_nbrf.c  \
			lib/my/printf/my_putcharf.c  \
			lib/my/printf/my_putstrf.c   \
			lib/my/printf/my_printf.c    \
			lib/my/printf/convert_binary.c       \
			lib/my/printf/non_printable.c        \
			lib/my/printf/printf_func2.c \
			lib/my/printf/printf_func.c  \
			lib/my/printf/printf_func3.c \
			lib/my/printf/modifiers.c    \
			lib/my/printf/my_strlen.c    \
			lib/my/printf/my_strncpy.c   \
			lib/my/printf/convert_hash.c \
			lib/my/printf/my_atoi.c      \
			lib/my/printf/printf_spaces.c        \



OBJ1    =    $(SRC1:.c=.o)

LIB    =    lib/my/libmy.a

SRC2    =    src/main.c	\
			src/wait_for_inputs.c	\
			src/handle_input_strings.c	\
			src/path_handling/commands_handled_path.c	\
			src/linked_list/linked_list_utilities.c	\
			src/env/handle_env_errors.c	\
			src/env/handle_env_two.c	\
			src/env/handle_env.c	\
			src/env/unsetenv.c	\
			src/get_cmd_command.c	\
			src/exec_binary.c	\
			src/pwd_functions.c	\
			src/cd_prompts.c	\
			src/cd_utilities.c	\
			src/tree/parsing.c	\
			src/tree/launch_tree.c	\
			src/tree/fill_tree_string.c	\
			src/tree/get_seps_priority.c	\
			src/redirections/redirection_right.c	\
			src/redirections/pipe.c	\
			src/redirections/redirection_left.c	\
			src/redirections/double_redirection_right.c	\

OBJ2    =  $(SRC2:.c=.o)

NAME    =	mysh

LDFLAGS    =   	-L./lib/my -lmy

CFLAGS    =  	-W -Wall -Wextra -g3 -Iinclude

all:    $(NAME)

$(NAME):    $(LIB) $(OBJ2)
			$(CC)	$(OBJ2)	$(LDFLAGS)	-o $(NAME)

$(LIB): $(OBJ1)
		$(AR) rsc $(LIB) $(OBJ1)

clean:
		$(RM) $(OBJ1)
		$(RM) $(OBJ2)

fclean: clean
		$(RM) -f $(NAME)
		$(RM) *.o
		$(RM) *.g*
		$(RM) $(LIB)

re:    fclean all
