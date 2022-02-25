/*
** EPITECH PROJECT, 2021
** B-CPE-201-MPL-2-1-corewar-bastien.boymond
** File description:
** my_itoa
*/

#include <stdlib.h>
#include "../../include/my.h"

char *my_itoa(int number)
{
    char *str = my_malloc(sizeof(char) * 15);

    if (number < 0)
        number = -number;
    str = str + sizeof(str);
    *--str = '\0';
    while (number >= 10) {
        *--str = '0' + number % 10;
        number /= 10;
    }
    *--str = '0' + number;
    if (number < 0)
        *--str = '-';
    return (str);
}