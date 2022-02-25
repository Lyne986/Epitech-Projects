/*
** EPITECH PROJECT, 2020
** Day04
** File description:
** my_putstr.c
*/

void my_putchar(char);

int my_putstr(char const *str)
{
    for (int i = 0; str[i]; i++)
        my_putchar(str[i]);
    return (0);
}
