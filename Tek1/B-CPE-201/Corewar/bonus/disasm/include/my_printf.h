/*
** EPITECH PROJECT, 2020
** B-PSU-100-MPL-1-1-myprintf-maya.hill
** File description:
** my_printf.h
*/

#include <stdarg.h>

typedef struct format_s
{
    int nb;
    char special;
    char c;
} format_t;

typedef struct array_s
{
    char c;
    void (*ptr)(va_list, format_t);
} array_t;

void print_char(va_list ap, format_t format);
void print_str(va_list ap, format_t format);
void print_nbr(va_list ap, format_t format);
void print_long(va_list ap, format_t format);
void print_unsigned_nbr(va_list ap, format_t format);
void print_ptr(va_list ap, format_t format);
void print_hex_upper(va_list ap, format_t format);
void print_hex_lower(va_list ap, format_t format);
void print_from_hex(int size, char *hex, int nbr, int retenu);
void print_from_long_hex(int size, char *hex, unsigned long int nbr);
void print_special_s(va_list ap, format_t format);
void my_putnbr_base(unsigned int nbr, char *base);
void print_bin(va_list ap, format_t format);
void print_octal(va_list ap, format_t format);
void print_ascii(va_list ap, format_t format);
void print_nb_flag(int size, format_t *format, char hex);
void format_spaces(format_t *format);
void format_minus(format_t *format);

static array_t __attribute__((unused)) func[] = {
        {'d', print_nbr},
        {'c', print_char},
        {'i', print_nbr},
        {'s', print_str},
        {'X', print_hex_upper},
        {'x', print_hex_lower},
        {'u', print_unsigned_nbr},
        {'o', print_octal},
        {'p', print_ptr},
        {'S', print_special_s},
        {'b', print_bin},
        {'l', print_long}
};