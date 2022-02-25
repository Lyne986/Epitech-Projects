/*
** EPITECH PROJECT, 2019
** Corewar/Corewar
** File description:
** my_realloc.c
*/

#include "../../include/csfml_garbage_collector.h"
#include "../../include/my.h"

void replace_ptr_in_garbage_collector_t(void *old_ptr, void *new_ptr)
{
    garbage_collector_t **head = get_garbage_collector();
    garbage_collector_t *temp = *head;

    if (*head == NULL) {
        return;
    }
    for (; temp; temp = temp->next) {
        if (temp->ptr == old_ptr)
            temp->ptr = new_ptr;
    }
}

void *my_realloc(void *ptr, size_t size)
{
    void *new_ptr = realloc(ptr, size);

    replace_ptr_in_garbage_collector_t(ptr, new_ptr);
    return (new_ptr);
}