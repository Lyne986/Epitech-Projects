/*
** EPITECH PROJECT, 2020
** my_str_isalpha.c
** File description:
** A program that check if string is alpha
*/

int my_str_isalpha(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0'  || (str[i] > '9' && str[i] < 'A') ||
        (str[i] > 'Z' && str[i] < 'a') || str[i] > 'z')
            return (0);
    }
    return (1);
}