/*
** EPITECH PROJECT, 2020
** B-CPE-110-MPL-1-1-pushswap-diogo.faria-martins
** File description:
** linked_lib_two
*/

#include "../../include/mysh.h"
#include "../../include/printf.h"

void int_list_push_front(env_t **list, char *value)
{
    env_t *node = malloc(sizeof(*node));

    node->value = value;
    node->next = *list;
    *list = node;
}

void int_list_push_back(env_t **list, char *value)
{
    env_t *node = *list;

    if (node == NULL)
        int_list_push_front(list, value);
    else
        int_list_push_back(&node->next, value);
}

void int_list_destroy(env_t **list)
{
    env_t *node = *list;

    while (node != NULL) {
        node = (*list)->next;
        free(*list);
        (*list) = node;
    }
    *list = NULL;
}

void printlist(env_t *list)
{
    while (list != NULL) {
        my_printf("%s\n", list->value);
        list = list->next;
    }
}