/*
** EPITECH PROJECT, 2021
** B-PSU-210-MPL-2-1-minishell2-diogo.faria-martins
** File description:
** my_memset
*/

char *my_memset(char *str, char c, int size)
{
    for (int i = 0; i < size; i++) {
        str[i] = c;
    }
    return (str);
}