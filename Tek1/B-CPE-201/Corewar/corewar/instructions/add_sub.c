/*
** EPITECH PROJECT, 2021
** Corewar/Corewar
** File description:
** add_sub_or
*/

#include "../../include/corewar.h"

void exec_add(instruction_t *function, champion_t *champ, corewar_t *core)
{
    int params[2] = {0, 0};
    int calc = 0;

    if (check_instruction_errors(function) == -1)
        return;
    calc = get_value(core, champ, function, params);
    params[0] = 1;
    calc += get_value(core, champ, function, params);
    if (calc == 0)
        champ->carry = 1;
    else
        champ->carry = 0;
    champ->registers[function->args[2]] = calc;
}

void exec_sub(instruction_t *function, champion_t *champ, corewar_t *core)
{
    int params[2] = {0, 0};
    int calc = 0;

    if (check_instruction_errors(function) == -1)
        return;
    calc = get_value(core, champ, function, params);
    params[0] = 1;
    calc -= get_value(core, champ, function, params);
    if (calc == 0)
        champ->carry = 1;
    else
        champ->carry = 0;
    champ->registers[function->args[2]] = calc;
}