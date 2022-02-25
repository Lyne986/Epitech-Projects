/*
** EPITECH PROJECT, 2020
** Corewar/Asm
** File description:
** update_parameters.c
*/

#include "../include/asm.h"

void update_register(asm_t *my_asm, char *registre)
{
    int nb_reg = 0;
    int type = op_tab[my_asm->functions->code - 1].type[my_asm->nb_args];

    if (type % 2 == 0 || !is_number(&registre[1]) || registre[1] == 0)
        exit(84);
    nb_reg = my_getnbr(&registre[1]);
    if (nb_reg > REG_NUMBER || nb_reg < 0)
        exit(84);
    my_asm->functions->size += ASM_REG_SIZE;
    my_asm->coding_byte[1 + 2 * my_asm->nb_args] = '1';
    my_asm->nb_args += 1;
}

void update_direct(asm_t *my_asm, char *label, const op_t *op)
{
    int type = op_tab[my_asm->functions->code - 1].type[my_asm->nb_args];

    if ((type & T_DIR) == 0 || label[1] == 0)
        exit(84);
    if (!is_number(&label[1]) && search_for_label(my_asm, label + 2) == -1)
        exit(84);
    if (op->nbr_cycles >= 20)
        my_asm->functions->size += IND_SIZE;
    else
        my_asm->functions->size += DIR_SIZE;
    my_asm->coding_byte[2 * my_asm->nb_args] = '1';
    my_asm->nb_args += 1;
}

void update_indirect(asm_t *my_asm, char *number)
{
    int type = op_tab[my_asm->functions->code - 1].type[my_asm->nb_args];

    if ((type & T_IND) == 0)
        exit(84);
    if ((!is_number(number) || !is_number(&number[1])) &&
    search_for_label(my_asm, number + 1) == -1)
        exit(84);
    my_asm->functions->size += IND_SIZE;
    my_asm->coding_byte[1 + 2 * my_asm->nb_args] = '1';
    my_asm->coding_byte[2 * my_asm->nb_args] = '1';
    my_asm->nb_args += 1;
}