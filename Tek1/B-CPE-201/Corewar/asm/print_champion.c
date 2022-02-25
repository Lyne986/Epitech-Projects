/*
** EPITECH PROJECT, 2020
** Corewar/Asm
** File description:
** print_champion.c
*/

#include "../include/asm.h"

void print_register(asm_t *my_asm, char *registre)
{
    int nb_reg = my_getnbr(&registre[1]);

    write(my_asm->header.fd, &nb_reg, sizeof(char));
}

void print_direct(asm_t *my_asm, char *label, function_t *function)
{
    bit_fields_t bite_field;
    long int nb = 0;

    if (label[1] == LABEL_CHAR) {
        nb = search_label_distance(my_asm, &label[2], function);
    } else {
        nb = my_get_longnbr(&label[1]);
    }
    nb = biteshifting(nb);
    bite_field.value = nb;
    if (op_tab[function->code - 1].nbr_cycles >= 20) {
        nb = bite_field.byte.bit2;
        write(my_asm->header.fd, &nb, sizeof(short));
    } else
        write(my_asm->header.fd, &nb, sizeof(DIR_SIZE));
}

void print_indirect(asm_t *my_asm, char *number, function_t *function)
{
    bit_fields_t bite_field;
    long int nb = 0;

    if (number[0] == LABEL_CHAR) {
        nb = search_label_distance(my_asm, &number[1], function);
    } else {
        nb = my_get_longnbr(number);
    }
    nb = biteshifting(nb);
    bite_field.value = nb;
    write(my_asm->header.fd, &bite_field.byte.bit2, sizeof(short));
}

void print_command(asm_t *my_asm, function_t *function)
{
    char **info = my_str_to_word_array(function->command, " ,\t\n");

    write(my_asm->header.fd, &function->code, sizeof(char));
    if (function->code != 1 && function->code != 9
    && function->code != 12 && function->code != 15)
        write(my_asm->header.fd, &function->coding_byte, sizeof(char));
    for (int i = 1; info[i]; i++) {
        if (info[i][0] == 'r')
            print_register(my_asm, info[i]);
        if (info[i][0] == DIRECT_CHAR)
            print_direct(my_asm, info[i], function);
        if (info[i][0] != DIRECT_CHAR && info[i][0] != 'r')
            print_indirect(my_asm, info[i], function);
    }
}

void print_champion(asm_t *my_asm)
{
    function_t *temp = my_asm->functions;

    print_champion_info(my_asm);
    if (temp && temp->next)
        temp = temp->next->next;
    while (temp) {
        print_command(my_asm, temp);
        temp = temp->next;
    }
}