/*
** EPITECH PROJECT, 2020
** workshop_strwordarray
** File description:
** str_toword_array
*/

#include "my.h"
#include <stdio.h>
#include <stdlib.h>

int is_next_separator(char *str, char *separator, int index)
{
    for (int n = 0; separator[n] != 0; n++)
        if (str[index + 1] == separator[n] ||
        (str[index] == separator[n] && str[index + 2] == '\0'))
            return (1);
    return (0);
}

int loop(char *str, char *separator, int index, int nb_words)
{
    for (int n = 0; separator[n] != 0; n++)
        if (str[index] == separator[n] &&
        is_next_separator(str, separator, index) == 0)
            nb_words++;
    return (nb_words);
}

int nb_words(char *str, char *separator)
{
    int nb_words = 1;

    for (int index = 0; str[index] != 0; index++)
        nb_words = loop(str, separator, index, nb_words);
    return (nb_words);
}

int word(char *str, int index, int s, char *separator)
{
    for (int sindex = 0; separator[sindex]; sindex++) {
        if (str[index] == separator[sindex] || str[index + 1] == '\0') {
            return (s);
        }
    }
    return (0);
}

char **my_str_to_word_array(char *str, char *separator)
{
    char **wordarray = malloc(sizeof(char *) * (nb_words(str, separator) + 1));
    int y = 0;
    int s = 0;
    int index = 0;
    int counter = 0;

    for (int array = 0; str[index] != '\0'; index++) {
        s++;
        y = word(str, index, s, separator);
        if (y != 0) {
            wordarray[array] = malloc(sizeof(char) * (y + 1));
            my_strncpy(wordarray[array], str + counter, s);
            wordarray[array][s] = '\0';
            counter += s;
            array++;
            s = 0;
        }
    }
    wordarray[nb_words(str, separator)] = '\0';
    return (wordarray);
}