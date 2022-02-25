/*
** EPITECH PROJECT, 2021
** B-PSU-101-MPL-1-1-minishell1-diogo.faria-martins
** File description:
** handle_env
*/

#include "my.h"
#include "mysh.h"
#include "printf.h"

void env_two(all_t *a)
{
    env_t *new = a->envi;
    env_t *new_two = a->envi;

    for (; new != NULL; new = new->next)
        if (is_env(new->value, a) == 1)
            break;
    for (; new_two != NULL; new_two = new_two->next) {
        if (my_strncmp(new_two->value, a->sh_arr[1],
        my_strlen(a->sh_arr[1]))) {
            new->value = my_strcat(my_strcat(a->sh_arr[1], "="),
            a->sh_arr[2]);
            return;
        }
    }
    new_two = a->envi;
    new->value = my_strcat(new->value, a->sh_arr[2]);;
}

void conditions_env(all_t *a, char *clone)
{
    if (a->array_size == 3) {
        if (already_env(a) == 0) {
            int_list_push_back(&a->envi,
            my_strcat(my_strcat(a->sh_arr[1], "="), a->sh_arr[2]));
            return;
        }
        env_two(a);
        return;
    }
    if (already_env(a) == 0) {
        int_list_push_back(&a->envi, my_strcat(a->sh_arr[1], "="));
        return;
    }
    already_pushed(a);
}

int found_unsetenv_command(all_t *a)
{
    if (a->array_size > 0 && (my_strncmp(a->sh_buff, "unsetenv\t", 8) == 0
    || my_strncmp(a->sh_buff, "unsetenv ", 8) == 0)) {
        if (a->array_size == 2) {
            unset_env(a, a->sh_arr[1]);
            return (1);
        }
        if (a->array_size > 2) {
            unset_env(a, a->sh_arr[1]);
            unset_env(a, a->sh_arr[2]);
            return (1);
        }
    }
    return (0);
}

void env_commands(all_t *a)
{
    char *clone;

    if (a->array_size == 1 && ((my_strcmp(a->sh_arr[0], "setenv") == 0)
    || (my_strcmp(a->sh_arr[0], "env") == 0))) {
        printlist(a->envi);
    }
    if (found_unsetenv_command(a) == 1)
        return;
    if (handle_env_errors(a) == -1)
        return;
    if (a->array_size > 1)
        clone = malloc(sizeof(char) * my_strlen(a->sh_arr[1]) + 2);
    if (a->array_size > 1 && (my_strcmp(a->sh_arr[0], "setenv") == 0)) {
        conditions_env(a, clone);
    }
}