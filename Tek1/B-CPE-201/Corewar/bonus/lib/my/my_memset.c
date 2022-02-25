/*
** EPITECH PROJECT, 2021
** B-CPE-201-MPL-2-1-corewar-bastien.boymond
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

unsigned char *my_unsigned_memset(unsigned char *str, char c, int size)
{
    for (int i = 0; i < size; i++) {
        str[i] = c;
    }
    return (str);
}