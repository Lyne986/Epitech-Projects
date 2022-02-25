/*
** EPITECH PROJECT, 2020
** Corewar
** File description:
** parse_command.c
*/

#include "../include/asm.h"

void code_command(asm_t *my_asm, const op_t *op)
{
    char **info = my_str_to_word_array(my_asm->functions->command, " ,\t\n");

    my_asm->coding_byte = my_memset(my_asm->coding_byte, '0', 8);
    my_asm->nb_args = 0;
    my_asm->functions->code = op->code;
    my_asm->functions->size += 1;
    if (op->code != 1 && op->code != 9 && op->code != 12 && op->code != 15)
        my_asm->functions->size += 1;
    for (int i = 1; info[i]; i++) {
        if (info[i][0] == 'r')
            update_register(my_asm, info[i]);
        if (info[i][0] == DIRECT_CHAR)
            update_direct(my_asm, info[i], op);
        if (info[i][0] != DIRECT_CHAR && info[i][0] != 'r')
            update_indirect(my_asm, info[i]);
    }
    if (my_asm->nb_args != op->nbr_args)
        exit(84);
    my_asm->functions->coding_byte = binary_to_dec(my_asm->coding_byte);
    my_asm->champ_size += my_asm->functions->size;
}

void get_command(asm_t *my_asm)
{
    char **info = my_str_to_word_array(my_asm->functions->command, " ,\t\n");
    int count = 0;

    for (int i = 0; my_asm->functions->command[i]; i++)
        if (my_asm->functions->command[i] == '#')
            my_asm->functions->command[i] = 0;
    for (int i = 0; op_tab[i].mnemonique; i++) {
        if (my_strcmp(op_tab[i].mnemonique, info[0]) == 0) {
            code_command(my_asm, &op_tab[i]);
            count++;
        }
    }
    if (count != 1)
        exit(84);
}

void parse_champion(asm_t *my_asm)
{
    function_t *temp = my_asm->functions;

    while (my_asm->functions) {
        if (!my_asm->name_exists || !my_asm->comment_exists)
            get_asm_info(my_asm);
        else
            get_command(my_asm);
        my_asm->functions = my_asm->functions->next;
    }
    my_asm->functions = temp;
}