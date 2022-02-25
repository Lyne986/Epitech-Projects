/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** unsetenv
*/

#include "my.h"
#include "mysh.h"
#include "printf.h"

char *int_list_pop_front(env_t **list)
{
    env_t *node = *list;
    char *tmp = node->value;

    *list = (*list)->next;
    free (node);
    return (tmp);
}

void unset_env(all_t *a, char *value)
{
    env_t *new = a->envi;
    env_t *new_two = new->next;

    if (my_strncmp(new->value, value, my_strlen(value) - 1) == 0) {
        int_list_pop_front(&a->envi);
        return;
    }
    while (new_two != NULL) {
        if (my_strncmp(new_two->value, value,
        my_strlen(value) - 1) == 0) {
            if (new_two->next != NULL)
                new->next = new_two->next;
            else
                new->next = NULL;
            return;
        }
        new = new->next;
        new_two = new_two->next;
    }
}