/*
** EPITECH PROJECT, 2020
** Corewar/Corewar
** File description:
** aff.c
*/

#include "../../include/corewar.h"

void exec_aff(instruction_t *instruction, champion_t *champion, corewar_t *core)
{
    (void) core;
    int params[2] = {0, 0};
    char value = 0;

    if (check_instruction_errors(instruction) == -1)
        return;
    value = get_value(core, champion, instruction, params);
    value = value % 256;
    my_printf("%c", value);
}

void exec_and(instruction_t *instruction, champion_t *champion, corewar_t *core)
{
    (void) core;
    int params[2] = {0, 0};
    int arg1 = 0;
    int arg2 = 0;

    if (check_instruction_errors(instruction) == -1)
        return;
    arg1 = get_value(core, champion, instruction, params);
    params[0] = 1;
    arg2 = get_value(core, champion, instruction, params);
    champion->registers[instruction->args[2]] = arg1 & arg2;
    if (champion->registers[instruction->args[2]] == 0)
        champion->carry = 1;
    else
        champion->carry = 0;
}