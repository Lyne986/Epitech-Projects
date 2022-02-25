/*
** EPITECH PROJECT, 2021
** B-CPE-201-MPL-2-1-corewar-bastien.boymond
** File description:
** is_number
*/

int is_number(char *str)
{
    for (int i = 0; str[i]; i++)
        if (str[0] != '-' && (str[i] < '0' || str[i] > '9'))
            return (0);
    return (1);
}