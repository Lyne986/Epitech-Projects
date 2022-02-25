/*
** EPITECH PROJECT, 2021
** B-PSU-210-MPL-2-1-minishell2-diogo.faria-martins
** File description:
** my_strdup
*/

#include <stdlib.h>
#include "my.h"

char *my_strdup(char *str)
{
    char *dup = malloc(sizeof(char) * (my_strlen(str) + 1));

    for (int i = 0; str[i] != 0; i++) {
        dup[i] = str[i];
    }
    dup[my_strlen(str)] = '\0';
    return (dup);
}