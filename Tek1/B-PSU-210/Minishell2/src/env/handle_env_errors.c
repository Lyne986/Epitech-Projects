/*
** EPITECH PROJECT, 2021
** B-PSU-101-MPL-1-1-minishell1-diogo.faria-martins
** File description:
** handle_env_errors
*/

#include "my.h"
#include "mysh.h"
#include "printf.h"

int is_alphanum(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] == '`' || str[i] == '/' || str[i] < '.'  || (str[i] > '9'
        && str[i] < 'A') || (str[i] > 'Z' && str[i] < '_') || str[i] > 'z')
            return (-1);
    }
    return (1);
}

int handle_env_errors(all_t *a)
{
    if (a->array_size > 3) {
        my_printf("%s: ", a->sh_arr[0]);
        write(2, "Too many arguments.\n", 20);
        return (-1);
    }
    if (a->array_size == 2 && is_alphanum(a->sh_arr[1]) == -1) {
        my_printf("%s: ", a->sh_arr[0]);
        write(2, "Variable name must contain alphanumeric characters.\n", 52);
        return (-1);
    }
    return (0);
}