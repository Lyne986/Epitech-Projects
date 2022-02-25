/*
** EPITECH PROJECT, 2019
** RPG
** File description:
** garbage_collector.c
*/

#include "../../include/my.h"

void __attribute__((destructor))call_after_main(void)
{
    destroy_ptr_to_garbage_collector_t();
}

void add_ptr_to_garbage_collector_t(void *ptr)
{
    garbage_collector_t *node = malloc(sizeof(garbage_collector_t));
    garbage_collector_t **head = get_garbage_collector();
    garbage_collector_t *temp = *head;

    node->next = NULL;
    node->ptr = ptr;
    if (*head == NULL) {
        *head = node;
        return;
    }
    for (; temp->next; temp = temp->next);
    temp->next = node;
}

void destroy_ptr_to_garbage_collector_t(void)
{
    garbage_collector_t **head = get_garbage_collector();
    garbage_collector_t *temp;
    garbage_collector_t *list = *head;

    if (list == NULL)
        return;
    for (; list; list = temp) {
        temp = list->next;
        free(list->ptr);
        free(list);
    }
}

void *my_malloc(size_t size)
{
    void *ptr = malloc(size);

    my_memset(ptr, '\0', size);
    add_ptr_to_garbage_collector_t(ptr);
    return (ptr);
}

garbage_collector_t **get_garbage_collector(void)
{
    static garbage_collector_t *garbage_collector = NULL;

    return (&garbage_collector);
}
