/*
** EPITECH PROJECT, 2020
** workshop_strwordarray
** File description:
** str_toword_array
*/

#include "my.h"
#include <stdio.h>
#include <stdlib.h>

int check_seps(char c, char *delims)
{
    for (int i = 0; delims[i] != 0; i++) {
        if (c == delims[i] || c == '\0') {
            return (1);
        }
    }
    return (0);
}

int get_words_nb(char *str, char *delims)
{
    int words_nb = 0;

    for (int i = 0; str[i] != 0; i++) {
        words_nb += check_seps(str[i], delims) == 0 &&
        check_seps(str[i + 1], delims) == 1 ? 1 : 0;
    }
    return (words_nb);
}

int get_words_len(char *str, char *delims, int i)
{
    int len = 0;

    for ( ; check_seps(str[i], delims) == 0; i++)
        len++;
    return (len);
}

int verify_str(char *str, char *delims)
{
    int words_nb = 0;

    if (my_strlen(str) <= 1)
        return (-1);
    for (int i = 0; str[i] != 0; i++) {
        words_nb += check_seps(str[i], delims) == 0 &&
        check_seps(str[i + 1], delims) == 1 ? 1 : 0;
    }
    return (words_nb);
}

char **parse_string(char *str, char *delims, int index)
{
    int word_nb = get_words_nb(str, delims);
    char **arr = malloc(sizeof(char *) * (word_nb + 1));
    int wordlen = 0;

    for (int i = 0; str[i]; i++) {
        if (check_seps(str[i], delims) == 0) {
            wordlen = get_words_len(str, delims, i);
            arr[index] = malloc(sizeof(char) * (wordlen + 1));
            my_strncpy(arr[index], str + i, wordlen);
            arr[index][wordlen] = '\0';
            i += wordlen;
            index++;
        }
        if (str[i] == 0)
            break;
    }
    arr[word_nb] = NULL;
    return (arr);
}