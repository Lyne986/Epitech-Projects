/*
** EPITECH PROJECT, 2021
** B-CPE-201-MPL-2-1-corewar-bastien.boymond
** File description:
** utilities
*/

#include "../include/asm.h"

int biteshifting(int x)
{
    return (((x >> 24) & 0x000000ff) | ((x >> 8) & 0x0000ff00) |
    ((x << 8) & 0x00ff0000) | ((x << 24) & 0xff000000));
}

int my_strlen_array(char **array)
{
    int len = 0;

    if (array == NULL)
        return (len);
    for (; array[len]; len++);
    return (len);
}

int binary_to_dec(char *binary)
{
    int number = my_getnbr(binary);
    int remove;
    int base = 1;
    int decimal_val = 0;

    while (number > 0) {
        remove = number % 10;
        decimal_val = decimal_val + remove * base;
        number = number / 10;
        base = base * 2;
    }
    return (decimal_val);
}

char *array_to_str(char **array)
{
    int len = 0;
    int index = 0;
    char *str = NULL;

    for (int i = 0; array[i]; i++)
        len += my_strlen(array[i]);
    str = my_malloc(sizeof(char) * (len + 1));
    str[len] = 0;
    for (int x = 0; array[x]; x++)
        for (int y = 0; array[x][y]; y++, index++)
            str[index] = array[x][y];
    return (str);
}