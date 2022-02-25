/*
** EPITECH PROJECT, 2020
** B-CPE-101-MPL-1-1-evalexpr-hugo.gardes
** File description:
** str_t_s.c
*/

#include "../../include/my.h"

int get_my_int_len(int nb)
{
    int len = 0;

    if (nb == 0)
        len++;
    for (; nb > 0; nb /= 10, len++);
    return (len);
}

char *to_str(int nb)
{
    int len = get_my_int_len(nb);
    int n = len - 1;
    char *strf = my_malloc(sizeof(char) * (len + 1));

    strf[len] = 0;
    for (int i = nb; n >= 0; i /= 10, n--)
        strf[n] = i % 10 + 48;
    return (strf);
}