/*
** EPITECH PROJECT, 2021
** B-CPE-201-MPL-2-1-corewar-bastien.boymond
** File description:
** linked_list
*/

#include "../include/asm.h"

void push_back_function(function_t **functions, char *command, int line)
{
    function_t *new_function = my_malloc(sizeof(function_t));
    function_t *temp = *functions;

    new_function->command = command;
    new_function->line = line;
    new_function->next = NULL;
    if (temp == NULL) {
        *functions = new_function;
        return;
    }
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = new_function;
}

int is_containing(char *str, char c)
{
    for (int i = 0; str[i]; i++)
        if (str[i] == c)
            return (1);
    return (0);
}

int label_chars(char *name)
{
    char *valids = LABEL_CHARS;

    for (int i = 0; name[i]; i++)
        if (is_containing(valids, name[i]) == 0)
            return (0);
    return (1);
}

void push_back_label(label_t **labels, char *name, char *command, int line)
{
    label_t *new_label = my_malloc(sizeof(label_t));
    label_t *temp = *labels;

    new_label->label = name;
    new_label->command = command;
    new_label->line = line;
    new_label->next = NULL;
    if (label_chars(name) == 0 || (temp && my_strcmp(temp->label, name) == 0))
        exit(84);
    if (temp == NULL) {
        *labels = new_label;
        return;
    }
    while (temp->next != NULL) {
        if (my_strcmp(temp->label, name) == 0 || \
        (temp->next != NULL && my_strcmp(temp->next->label, name) == 0))
            exit(84);
        temp = temp->next;
    }
    temp->next = new_label;
}