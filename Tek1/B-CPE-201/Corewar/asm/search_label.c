/*
** EPITECH PROJECT, 2020
** Corewar/Asm
** File description:
** search_label.c
*/

#include "../include/asm.h"

int search_for_label(asm_t *my_asm, char *str)
{
    label_t *temp = my_asm->labels;

    while (temp != NULL) {
        if (my_strcmp(str, temp->label) == 0)
            return (1);
        temp = temp->next;
    }
    return (-1);
}

int search_after_label(label_t *l_temp, function_t *function)
{
    function_t *f_temp = function;
    int max = l_temp->line;
    int distance = 0;

    while (f_temp && f_temp->line < max) {
        distance += f_temp->size;
        f_temp = f_temp->next;
    }
    return (distance);
}

int search_before_label(asm_t *my_asm, label_t *l_temp, function_t *function)
{
    function_t *f_temp = my_asm->functions;
    int min = l_temp->line;
    int max = function->line;
    int distance = 0;

    while (f_temp && f_temp->line < max) {
        if (f_temp->line >= min)
            distance -= f_temp->size;
        f_temp = f_temp->next;
    }
    return (distance);
}

int search_label_distance(asm_t *my_asm, char *label, function_t *function)
{
    label_t *l_temp = my_asm->labels;
    int distance = 0;

    while (l_temp->next) {
        if (my_strcmp(label, l_temp->label) == 0)
            break;
        l_temp = l_temp->next;
    }
    if (l_temp->line > function->line) {
        distance = search_after_label(l_temp, function);
    } else {
        distance = search_before_label(my_asm, l_temp, function);
    }
    return (distance);
}