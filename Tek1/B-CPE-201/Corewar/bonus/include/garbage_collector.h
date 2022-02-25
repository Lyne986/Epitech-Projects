/*
** EPITECH PROJECT, 2019
** garbage_collector.h
** File description:
** for garbage_collector function
*/

#ifndef GARBAGE_COLLECTOR_H_
#define GARBAGE_COLLECTOR_H_

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct garbage_collector_s garbage_collector_t;

struct garbage_collector_s
{
    void *ptr;
    struct garbage_collector_s *next;
};

void *my_malloc(size_t size);
garbage_collector_t **get_garbage_collector(void);
void destroy_ptr_to_garbage_collector_t(void);
void *my_realloc(void *ptr, size_t size);

#endif
