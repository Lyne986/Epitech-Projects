/*
** EPITECH PROJECT, 2020
** B-PSU-100-MPL-1-1-myprintf-maya.hill
** File description:
** my_printf.c
*/

#include <stdarg.h>
#include "../../include/my.h"
#include "../../include/my_printf.h"
#include <stdlib.h>

void check_special_flags(char *s, int *i, format_t *format)
{
    while (s[*i] == '#' || s[*i] == ' ' || s[*i] == '+' || s[*i] == '-') {
        if (s[*i] == '-')
            format->c = s[*i];
        if (s[*i] != '-' && format->special != '#' && format->special != '+')
            format->special = s[*i];
        (*i) = (*i) + 1;
    }
}

void get_format(char *str, int *i, format_t *format)
{
    check_special_flags(str, i, format);
    if (str[*i] == '0' && str[*i + 1] >= '#' && str[*i + 1] <= '9') {
        if (format->c != '-')
            format->c = '0';
        (*i) = (*i) + 1;
    }
    check_special_flags(str, i, format);
    if (str[*i] >= '0' && str[*i] <= '9')
        format->nb = my_getnbr(&str[*i]);
}

void print_var(char *str, int *i, va_list ap)
{
    format_t format;
    format.nb = 0;
    format.c = ' ';
    format.special = 0;

    (*i) = (*i) + 1;
    get_format(str, i, &format);
    for (; str[*i] >= '0' && str[*i] <= '9'; *i += 1);
    for (int n = 0; n < 12; n++) {
        if (func[n].c == str[*i]) {
            func[n].ptr(ap, format);
            return;
        }
    }
    my_putchar(str[*i]);
}

int my_printf(char *str, ...)
{
    va_list ap;

    va_start(ap, str);
    for (int i = 0; str[i]; i++) {
        if (str[i] == '%') {
            print_var(str, &i, ap);
        } else
            my_putchar(str[i]);
    }
    return (0);
}