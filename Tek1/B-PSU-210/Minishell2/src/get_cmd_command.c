/*
** EPITECH PROJECT, 2021
** minishell2
** File description:
** get_cmd_command
*/

#include "mysh.h"
#include "printf.h"

int cd_cmd(char *cmd)
{
    if (my_strcmp(cmd, "cd") == 0)
        return (0);
    return (-1);
}

int env_cmd(char *cmd)
{
    if (my_strcmp(cmd, "env") == 0 ||
    my_strcmp(cmd, "setenv") == 0 ||
    my_strcmp(cmd, "unsetenv") == 0)
        return (0);
    return (-1);
}

int find_cmd_command(all_t *a)
{
    if (env_cmd(a->sh_arr[0]) == 0)
        return (ENV);
    if (cd_cmd(a->sh_arr[0]) == 0)
        return (CD);
    if (access(a->sh_arr[0], F_OK) == 0)
        return (BINARY);
    if (my_strcmp(a->sh_arr[0], "exit") == 0)
        return (EXIT);
    return (-1);
}