/*
** EPITECH PROJECT, 2020
** B-PSU-100-MPL-1-1-myprintf-maya.hill
** File description:
** my_putnbr_base.c
*/

#include <stdlib.h>
#include "../../include/my.h"

void my_putnbr_base(unsigned int nbr, char *base)
{
    char *str;
    int size = 0;
    int len = my_strlen(base);

    if (nbr == 0)
        my_putchar('0');
    if (len == 0)
        return;
    for (unsigned int i = nbr; i > 0; i = i / len, size++);
    str = my_malloc(sizeof(char) * (size + 1));
    str[size] = 0;
    size--;
    for (; nbr > 0; nbr = nbr / len, size--)
        str[size] = base[nbr % len];
    my_putstr(str);
}

char *my_putnbr_base_dump(unsigned int nbr, char *base)
{
    char *str;
    int size = 0;
    int len = my_strlen(base);

    if (nbr == 0)
        return ("0");
    for (unsigned int i = nbr; i > 0; i = i / len, size++);
    str = my_malloc(sizeof(char) * (size + 1));
    str[size] = 0;
    size--;
    for (; nbr > 0; nbr = nbr / len, size--)
        str[size] = base[nbr % len];
    return (str);
}

char *nbr_to_base(unsigned int nbr, char *base)
{
    int size = 0;
    char *str = my_malloc(sizeof(char) * 15);
    int len = my_strlen(base);

    str = my_memset(str, '0', 8);
    for (unsigned int i = nbr; i > 0; i = i / len, size++);
    size = 7;
    for (; nbr > 0 && size >= 0; nbr = nbr / len, size--) {
        str[size] = base[nbr % len];
    }
    return (str);
}