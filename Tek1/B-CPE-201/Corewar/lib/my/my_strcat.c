/*
** EPITECH PROJECT, 2020
** Day07
** File description:
** my_strcat.c
*/

#include "../../include/my.h"
#include <stdlib.h>

char *my_strcat(char *dest, char *src)
{
    int i = 0;
    int len1 = 0;
    int len2 = 0;
    char *new_str = NULL;

    if (dest == NULL)
        return (src);
    len1 = my_strlen(dest);
    len2 = my_strlen(src);
    new_str = my_malloc(sizeof(char) * (len1 + len2 + 1));
    for (; dest[i]; i++) {
        new_str[i] = dest[i];
    }
    for (int j = 0; src[j]; j++) {
        new_str[i] = src[j];
        i = i + 1;
    }
    new_str[i] = 0;
    return (new_str);
}

void my_strcat_from(char *dest, char *src, int n)
{
    int i = n;

    if (dest == NULL)
        return;
    for (int j = 0; src[j]; j++) {
        dest[i] = src[j];
        i = i + 1;
    }
}