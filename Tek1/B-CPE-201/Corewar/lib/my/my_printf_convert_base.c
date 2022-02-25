/*
** EPITECH PROJECT, 2020
** B-PSU-100-MPL-1-1-myprintf-maya.hill
** File description:
** my_printf_convert_base.c
*/

#include <stdarg.h>
#include "../../include/my.h"
#include "../../include/my_printf.h"
#include <stdlib.h>

int get_int_len(long int nbr);

void decimal_to_octal(int nb)
{
    int p = 2;
    int oct[3] = {0, 0, 0};

    for (; p >= 0; nb = nb / 8, p--)
        oct[p] = nb % 8;
    for (int i = 0; i < 3; i++)
        my_put_nbr(oct[i]);
}

void print_special_s(va_list ap, format_t format)
{
    char *str = va_arg(ap, char *);
    int len = my_strlen(str);

    format.nb = format.nb - len;
    format_spaces(&format);
    for (int i = 0; str[i]; i++) {
        if (str[i] < 32 || str[i] >= 127) {
            my_putchar('\\');
            decimal_to_octal(str[i]);
        } else
            my_putchar(str[i]);
    }
    format_minus(&format);
}

void print_octal(va_list ap, format_t format)
{
    unsigned int nbr = va_arg(ap, unsigned int);
    int size = 0;

    for (unsigned int i = nbr; i > 0; i = i / 8, size++);
    if (format.special != 0) {
        if (format.special == '#') {
            my_putchar('0');
            size++;
        }
    }
    format.nb = format.nb - size;
    format_spaces(&format);
    my_putnbr_base(nbr, "01234567");
    format_minus(&format);
}

void print_bin(va_list ap, format_t format)
{
    unsigned int nbr = va_arg(ap, unsigned int);
    int size = 0;

    for (unsigned int i = nbr; i > 0; i = i / 8, size++);
    format.nb = format.nb - size;
    format_spaces(&format);
    my_putnbr_base(nbr, "01");
    format_minus(&format);
}

void print_long(va_list ap, format_t format)
{
    long int nbr = va_arg(ap, long int);
    int len = get_int_len(nbr);

    if (nbr > 0 && format.special == ' ') {
        my_putchar(' ');
        len++;
    }
    if (nbr < 0 && format.c == '0') {
        my_putchar('-');
        nbr = -nbr;
    } else if (nbr > 0 && format.special == '+') {
        my_putchar(format.special);
        len++;
    }
    format.nb = format.nb - len;
    format_spaces(&format);
    my_put_long(nbr);
    format_minus(&format);
}