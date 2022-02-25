/*
** EPITECH PROJECT, 2020
** Day06
** File description:
** my_strcpy.c
*/

#include "../../include/my.h"

char *my_strdup(char const *src)
{
    int i = 0;
    int len = 0;
    char *dup = NULL;

    if (!src)
        return (dup);
    len = my_strlen(src);
    dup = my_malloc(sizeof(char) * (len + 1));
    dup[len] = 0;
    for (; src[i]; i++)
        dup[i] = src[i];
    return (dup);
}
