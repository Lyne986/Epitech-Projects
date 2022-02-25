/*
** EPITECH PROJECT, 2021
** B-CPE-201-MPL-2-1-corewar-bastien.boymond
** File description:
** utilities
*/

#include "./include/corewar.h"
#include "./include/op.h"

int get_instruction_args(char *bin, int n)
{
    int arg_type = 0;
    char type[3];

    type[2] = '\0';
    type[0] = bin[n * 2];
    type[1] = bin[n * 2 + 1];
    if (my_strcmp(type, "01") == 0)
        arg_type = T_REG;
    if (my_strcmp(type, "10") == 0)
        arg_type = T_DIR;
    if (my_strcmp(type, "11") == 0)
        arg_type = T_IND;
    return (arg_type);
}

char *convert_base(unsigned int nbr, char *base)
{
    char *str = my_malloc(sizeof(char) * 3);
    int size = 0;
    int len = my_strlen(base);

    str = my_memset(str, '0', 2);
    for (unsigned int i = nbr; i > 0; i = i / len, size++);
    if (size > 1)
        size--;
    for (; nbr > 0; nbr = nbr / len, size--)
        str[size] = base[nbr % len];
    return (str);
}

int get_index(char c, char *str)
{
    for (int i = 0; str[i]; i++)
        if (c == str[i])
            return (i);
    return (84);
}

char *negate_binary(unsigned int nbr, char *base)
{
    char *str;
    int size = 0;
    int len = my_strlen(base);

    if (nbr == 0)
        return ("0");
    for (unsigned int i = nbr; i > 0; i = i / len, size++);
    str = my_malloc(sizeof(char) * (size + 1));
    str[size] = 0;
    size--;
    for (; nbr > 0; nbr = nbr / len, size--)
        str[size] = base[nbr % len];
    for (int i = my_strlen(str) - 1; i >= 0; i--) {
        if (str[i] == '0') {
            str[i] = '1';
            break;
        } else
            str[i] = '0';
    }
    return (str);
}

int base_to_dec(char *str, char *base)
{
    int len = my_strlen(str) - 1;
    char *bin = NULL;
    int base_len = my_strlen(base);
    int nb = 0;

    for (int i = 0; str[i]; i++) {
        nb += get_index(str[i], base) * my_compute_power_rec(base_len, len);
        len--;
    }
    if (str[0] == 'F') {
        bin = negate_binary(nb, "10");
        nb = base_to_dec(bin, "01") * -1;
    }
    return (nb);
}