/*
** EPITECH PROJECT, 2021
** B-PSU-210-MPL-2-1-minishell2-diogo.faria-martins
** File description:
** fill_tree_string
*/

#include "mysh.h"

int check_string(char c, char *nb)
{
    for (int i = 0; nb[i] != '\0'; i++) {
        if (nb[i] == c)
            return (1);
    }
    return (84);
}

int check_only_seps(char *str)
{
    int is_sep = 0;

    for (int i = 0; str[i]; i++) {
        if (check_string(str[i], "\n\t ;") == 84) {
            is_sep = 1;
        }
    }
    return (is_sep);
}

char *fill_tree_left(char *str, int index)
{
    int i = 0;
    char *left = malloc(sizeof(char) * (index + 1));

    left = my_memset(left, '\0', index);
    for (; i < index; i++) {
        left[i] = str[i];
    }
    left[index] = '\0';
    if (i == 0) {
        return (NULL);
    }
    if (check_only_seps(left) == 0)
        return (NULL);
    return (left);
}

char *fill_tree_right(char *str, int index, int sep)
{
    int i = 0;
    char *right = malloc(sizeof(char) * (my_strlen(str) + 1));
    if (my_strlen(str) - 1 == index + 1)
        return (NULL);
    right = my_memset(right, '\0', my_strlen(str) + 1);
    if (sep == D_RED_L || sep == D_RED_R)
        index += 2;
    else
        index += 1;
    for (; str[index]; i++) {
        right[i] = str[index];
        index++;
    }
    right[index] = '\0';
    if (i == 0)
        return (NULL);
    if (check_only_seps(right) == 0)
        return (NULL);
    return (right);
}