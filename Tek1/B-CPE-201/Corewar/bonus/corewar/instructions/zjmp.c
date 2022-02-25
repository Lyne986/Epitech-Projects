/*
** EPITECH PROJECT, 2020
** Corewar/Corewar
** File description:
** zjmp.c
*/

#include "../../include/corewar.h"

void exec_zjmp(instruction_t *function, champion_t *champion, corewar_t *core)
{
    (void) core;
    int new_pc = 0;

    if (check_instruction_errors(function) == -1)
        return;
    if (champion->carry == 0)
        return;
    new_pc = function->pc + function->args[0] % IDX_MOD;
    if (new_pc < 0)
        new_pc = MEM_SIZE + new_pc % MEM_SIZE;
    else
        new_pc = new_pc % MEM_SIZE;
    champion->next_pc = new_pc;
}