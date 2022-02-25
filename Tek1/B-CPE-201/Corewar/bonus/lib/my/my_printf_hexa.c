/*
** EPITECH PROJECT, 2020
** B-PSU-100-MPL-1-1-myprintf-maya.hill
** File description:
** my_printf_hexa.c
*/

#include <stdarg.h>
#include "../../include/my.h"
#include "../../include/my_printf.h"
#include <stdlib.h>

void format_spaces(format_t *format)
{
    if (format->c != '-')
        for (; format->nb > 0; format->nb--)
            my_putchar(format->c);
}

void format_minus(format_t *format)
{
    if (format->c == '-')
        for (; format->nb > 0; format->nb--)
            my_putchar(' ');
}

void print_nb_flag(int size, format_t *format, char hex)
{
    if (format->special == '#')
        size = size + 2;
    if (format->special == '#' && format->c == '0') {
        if (hex == 'x')
            my_putstr("0x");
        else
            my_putstr("0X");
    }
    format->nb = format->nb - size;
    format_spaces(format);
    if (format->special == '#' && (format->c == ' ' || format->c == '-')) {
        if (hex == 'x')
            my_putstr("0x");
        else
            my_putstr("0X");
    }
}

void print_hex_upper(va_list ap, format_t format)
{
    unsigned int nbr = va_arg(ap, unsigned int);
    char *hex = "0123456789ABCDEF";
    int size = 0;

    for (unsigned int i = nbr; i > 0; i = i / 16, size++);
    print_nb_flag(size, &format, 'X');
    if (nbr == 0)
        my_putchar('0');
    print_from_long_hex(size, hex, nbr);
    format_minus(&format);
}

void print_hex_lower(va_list ap, format_t format)
{
    unsigned int nbr = va_arg(ap, unsigned int);
    char *hex = "0123456789abcdef";
    int size = 0;

    for (unsigned int i = nbr; i > 0; i = i / 16, size++);
    print_nb_flag(size, &format, 'x');
    if (nbr == 0)
        my_putchar('0');
    print_from_long_hex(size, hex, nbr);
    format_minus(&format);
}