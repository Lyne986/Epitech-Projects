/*
** EPITECH PROJECT, 2020
** my_getnumber.c
** File description:
** Get int from string
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

int my_charisnum(char c);

int grab_result(int negative, char *str)
{
    int lenght = my_strlen(str) - 1;
    int result = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        result += (str[i] - 48) * my_compute_power_rec(10, lenght);
        lenght--;
    }
    if (negative == 1)
        return (result * -1);
    return (result);
}

int my_getnbr(char const *str)
{
    int negative = 0;
    int isanum = 0;
    int letter = 0;
    int counter = 0;
    char rstr[12];

    for (int i = 0; str[i] != '\0'; i++) {
        if (my_charisnum(str[i]) && letter != 1) {
            rstr[counter] = str[i];
            counter++;
            isanum = 1;
        }
        if (str[i] == '-')
            negative = 1;
        if (isanum == 1)
            letter = 1;
    }
    rstr[counter] = '\0';
    return grab_result(negative, rstr);
}