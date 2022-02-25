/*
** EPITECH PROJECT, 2021
** B-PSU-101-MPL-1-1-minishell1-diogo.faria-martins
** File description:
** handle_env
*/

#include "my.h"
#include "mysh.h"
#include "printf.h"

struct env *setenve(all_t *all)
{
    env_t *env_list = NULL;

    for (int i = 0; all->env[i]; i++)
        int_list_push_back(&env_list, all->env[i]);
    return (env_list);
}

int is_env(char *str, all_t *all)
{
    if (my_strncmp(str, all->sh_arr[1], my_strlen
    (all->sh_arr[1]) - 1) == 0)
        return (1);
    return (0);
}

int already_env(all_t *all)
{
    env_t *new = all->envi;

    for (; new != NULL; new = new->next)
        if (is_env(new->value, all) == 1)
            return (1);
    return (0);
}

void already_pushed(all_t *a)
{
    env_t *new = a->envi;

    for (; new != NULL; new = new->next)
        if (is_env(new->value, a) == 1)
            new->value = my_strcat(a->sh_arr[1], "=");
}