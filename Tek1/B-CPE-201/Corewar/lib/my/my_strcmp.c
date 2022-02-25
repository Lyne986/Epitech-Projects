/*
** EPITECH PROJECT, 2020
** Day06
** File description:
** my_strncmp.c
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    for (; s1[i] && s2[i] && s1[i] == s2[i]; i++);
    return (s1[i] - s2[i]);
}
