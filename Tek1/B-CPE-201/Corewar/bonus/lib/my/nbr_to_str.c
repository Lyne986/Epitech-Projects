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
    int new_nb = nb;
    int len = 0;
    int n = 0;
    char *strf = NULL;

    if (nb == 0)
        return ("0");
    if (nb < 0) {
        len = 1;
        new_nb = -nb;
    }
    len += get_my_int_len(new_nb);
    n = len - 1;
    strf = my_malloc(sizeof(char) * (len + 1));
    strf[len] = 0;
    for (int i = new_nb; i > 0; i /= 10, n--)
        strf[n] = i % 10 + 48;
    if (nb < 0)
        strf[0] = '-';
    return (strf);
}