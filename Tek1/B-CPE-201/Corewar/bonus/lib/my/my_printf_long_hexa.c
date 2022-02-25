/*
** EPITECH PROJECT, 2020
** my_printf.c
** File description:
** my_printf_long_hexa.c
*/

#include <stdarg.h>
#include "../../include/my.h"
#include "../../include/my_printf.h"
#include <stdlib.h>

void print_from_long_hex(int size, char *hex, unsigned long int nbr)
{
    char *str = my_malloc(sizeof(char) * (size + 1));

    str[size] = 0;
    size--;
    for (; nbr > 0; size--, nbr = nbr / 16) {
        str[size] = hex[nbr % 16];
    }
    my_putstr(str);
    free(str);
}

void print_pos_ptr(unsigned long int nbr, format_t format, int size_flags)
{
    char *hex = "0123456789abcdef";
    int size = 0;

    for (unsigned long int i = nbr; i > 0; i = i / 16, size++);
    if (format.c == ' ')
        print_nb_flag(size + 2 + size_flags, &format, 'x');
    if (format.special == '+') {
        my_putchar(format.special);
        size_flags++;
    }
    my_putstr("0x");
    if (format.c == '0')
        print_nb_flag(size + 2 + size_flags, &format, 'x');
    print_from_long_hex(size, hex, nbr);
    format.nb = format.nb - (size + size_flags + 2);
    format_minus(&format);
}

void print_ptr(va_list ap, format_t format)
{
    unsigned long int nbr = va_arg(ap, unsigned long int);
    int size_flags = 0;

    if (format.special == ' ') {
        my_putchar(' ');
        size_flags++;
    }
    if (nbr == 0) {
        my_putstr("(nil)");
        return;
    }
    print_pos_ptr(nbr, format, size_flags);
}