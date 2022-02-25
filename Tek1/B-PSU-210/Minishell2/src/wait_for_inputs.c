/*
** EPITECH PROJECT, 2021
** minishell2
** File description:
** wait_for_inputs
*/

#include "mysh.h"
#include "printf.h"

void launch_command(all_t *a, int command)
{
    switch (command) {
    case BINARY:
        exec_binary(a);
        break;
    case CD:
        cd_command(a);
        break;
    case ENV:
        env_commands(a);
        break;
    case EXIT:
        my_printf("exit\n");
        exit (0);
    default:
        exec_path_command(a);
    }
}

int are_seps(char *str)
{
    char *seps = "<>|;";
    int is_sep = 0;

    for (int i = 0; str[i]; i++) {
        for (int j = 0; seps[j]; j++) {
            is_sep = str[i] == seps[j] ? 1 : is_sep;
        }
    }
    return (is_sep);
}

void launch_minishell(all_t *a)
{
    if (are_seps(a->sh_buff) == false)
        launch_command(a, find_cmd_command(a));
    else {
        a->parsing->sep = -1;
        a->tree = init_tree_node(a->sh_buff, get_op(a->sh_buff, 0, 0));
        parsing(a, a->tree);
        launch_tree(a, a->tree);
    }
}

void wait_inputs(all_t *a)
{
    size_t len = 0;
    a->parsing = malloc(sizeof(parsing_t));

    while (true) {
        if (isatty(STDIN_FILENO) == 1)
            my_printf("$> ");
        a->sh_buff = malloc(sizeof(char) * 245);
        my_memset(a->sh_buff, '\0', 245);
        a->sh_buff[244] = '\0';
        if (getline(&a->sh_buff, &len, stdin) == -1)
            return;
        if (handle_arrays(a) != NULL) {
            launch_minishell(a);
        }
    }
}