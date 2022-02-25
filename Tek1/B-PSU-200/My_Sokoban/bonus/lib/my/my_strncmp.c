/*
** EPITECH PROJECT, 2020
** my_strncmp.c
** File description:
** A program that compare two strings with n
*/

int my_strlen(char const *str);

int min_string2(char const *s1, char const *s2);

int count_chars2(char s1, char s2, char const *ss1, char const *ss2);

int my_strncmp(char const *s1 , char const *s2 , int n)
{
    int index = 0;

    while (index < n && s1[index] == s2[index])
        index++;
    if (s1[index] > s2[index])
        return (s1[index] - s2[index]);
    if (s1[index] < s2[index])
        return (s2[index] - s1[index]);
    return (0);
}