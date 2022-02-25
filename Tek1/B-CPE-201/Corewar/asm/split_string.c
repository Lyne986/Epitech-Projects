/*
** EPITECH PROJECT, 2020
** Corewar/Asm
** File description:
** split_string.c
*/

#include "../include/asm.h"

char *after_arg(char *str)
{
    int i = 0;

    for (; str[i] && str[i] != '\"'; i++);
    i++;
    for (; str[i] && str[i] != '\"'; i++);
    if (str[i])
        i++;
    return (&str[i]);
}

char *from_arg(char *str)
{
    char *dup_str = NULL;
    int i = 0;

    for (; str[i] && str[i + 1] && str[i] != '\"'; i++);
    dup_str = my_strdup(&str[i + 1]);
    for (i = 0; dup_str[i] && dup_str[i] != '\"'; i++);
    dup_str[i] = 0;
    return (dup_str);
}

char *to_arg(char *str, char *delim)
{
    char *dup_str = NULL;
    int i = 0;

    for (; str[i] && is_delim(str[i], delim) == -1; i++);
    dup_str = my_strdup(str + i);
    for (; dup_str[i] && is_delim(dup_str[i], delim) != -1; i++);
    dup_str[i] = 0;
    return (dup_str);
}

char **split_string(char *command, char *delim)
{
    char **array = my_malloc(sizeof(char *) * 4);

    array[0] = to_arg(command, delim);
    array[1] = from_arg(command);
    array[2] = after_arg(command);
    array[3] = NULL;
    if (array[1][0] == 0 && array[2][0] != 0)
        exit(84);
    if (array[2][0] == '\"')
        exit(84);
    for (int i = 0; array[2][i]; i++)
        if (is_delim(array[2][i], delim) != -1)
            exit(84);
    return (array);
}