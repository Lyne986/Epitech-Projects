/*
** EPITECH PROJECT, 2020
** Corewar/Corewar
** File description:
** lld_lldi.c
*/

#include "../../include/corewar.h"

void exec_lld(instruction_t *instruction, champion_t *champion, corewar_t *core)
{
    int params[2] = {0, 0};
    int value = 0;

    if (check_instruction_errors(instruction) == -1)
        return;
    value = get_value(core, champion, instruction, params);
    champion->registers[instruction->args[1]] = value;
    if (champion->registers[instruction->args[1]] == 0)
        champion->carry = 1;
    else
        champion->carry = 0;
}

void next_lldi(corewar_t *core, champion_t *champ, instruction_t *func, int nb)
{
    char *base = "0123456789ABCDEF";
    int temp_pc = 0;

    core->hex[REG_SIZE * 2] = 0;
    for (int i = 0; i < REG_SIZE; i++) {
        temp_pc = (nb + i) % MEM_SIZE;
        if (temp_pc < 0)
            temp_pc += MEM_SIZE;
        my_strcat_from(core->hex, core->arena[temp_pc].hex, i * 2);
    }
    champ->registers[func->args[2]] = base_to_dec(core->hex, base);
    if (champ->registers[func->args[2]] == 0)
        champ->carry = 1;
    else
        champ->carry = 0;
}

void exec_lldi(instruction_t *function, champion_t *champ, corewar_t *core)
{
    int params[2] = {0, 0};
    char *hex = "0123456789ABCDEF";
    int value = champ->pc;
    int temp_pc = champ->pc;

    if (check_instruction_errors(function) == -1)
        return;
    value = get_value(core, champ, function, params);
    temp_pc = value;
    core->hex[IND_SIZE * 2] = 0;
    for (int i = 0; i < IND_SIZE; i++) {
        temp_pc = (value + i) % MEM_SIZE;
        if (temp_pc < 0)
            temp_pc += MEM_SIZE;
        my_strcat_from(core->hex, core->arena[temp_pc].hex, i * 2);
    }
    params[0] = 1;
    value += base_to_dec(core->hex, hex);
    value += get_value(core, champ, function, params);
    next_lldi(core, champ, function, value);
}