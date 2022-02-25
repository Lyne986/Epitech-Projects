/*
** EPITECH PROJECT, 2021
** minishell2
** File description:
** handle_input_strings
*/

#include "mysh.h"

char *handle_arrays(all_t *a)
{
    if (check_only_seps(a->sh_buff) == 1) {
        a->sh_arr = parse_string(a->sh_buff, " \n\t", 0);
        if (a->sh_arr == NULL)
            return (NULL);
    }
    else
        return (NULL);
    for (a->array_size = 0; a->sh_arr[a->array_size]; a->array_size++);
    return ("good");
}