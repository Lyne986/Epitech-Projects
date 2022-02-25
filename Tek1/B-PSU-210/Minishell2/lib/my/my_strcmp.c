/*
** EPITECH PROJECT, 2020
** my_strcmp.c
** File description:
** A program that compare two strings
*/

int my_strlen(char const *str);

int min_string(char const *s1, char const *s2);

int count_chars(char s1, char s2, char const *ss1, char const *ss2);

int my_strcmp(char *s1, char *s2)
{
    int index = 0;
    int lenght = 0;

    if (my_strlen(s1) > my_strlen(s2))
        lenght = my_strlen(s1);
    lenght = my_strlen(s2);
    while (index < lenght && s1[index] == s2[index])
        index++;
    if ((s1[index] == 0 && s2[index] == 0))
        return (0);
    if (s1[index] > s2[index])
        return (s1[index] - s2[index]);
    if (s1[index] < s2[index])
        return (s2[index] - s1[index]);
    return (0);
}
