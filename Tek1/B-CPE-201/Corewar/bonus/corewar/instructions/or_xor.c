/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** xor.c
*/

#include "../../include/corewar.h"

void exec_or(instruction_t *instruction, champion_t *champion, corewar_t *core)
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
    champion->registers[instruction->args[2]] = arg1 | arg2;
    if (champion->registers[instruction->args[2]] == 0)
        champion->carry = 1;
    else
        champion->carry = 0;
}

void exec_xor(instruction_t *instruction, champion_t *champion, corewar_t *core)
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
    champion->registers[instruction->args[2]] = arg1 ^ arg2;
    champion->carry = champion->registers[instruction->args[2]];
    if (champion->registers[instruction->args[2]] == 0)
        champion->carry = 1;
    else
        champion->carry = 0;
}