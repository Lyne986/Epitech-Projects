/*
** EPITECH PROJECT, 2020
** Corewar/Corewar
** File description:
** ld_st.c
*/

#include "../../include/corewar.h"

void write_indirect(corewar_t *core, champion_t *champ, char *hexa, int new_pc)
{
    char *hex = "0123456789ABCDEF";
    int temp_pc = 0;

    hexa = &hexa[4];
    for (int i = 0; i < IND_SIZE; i++) {
        temp_pc = (new_pc + i) % MEM_SIZE;
        for (int j = 0; j < 2; j++)
            core->arena[temp_pc].hex[j] = hexa[i * 2 + j];
        core->arena[temp_pc].champ_id = champ->prog_number;
        core->arena[temp_pc].c = base_to_dec(core->arena[temp_pc].hex, hex);
    }
}

void write_register(corewar_t *core, champion_t *champ, char *hexa, int new_pc)
{
    char *hex = "0123456789ABCDEF";
    int temp_pc = 0;

    for (int i = 0; i < REG_SIZE; i++) {
        temp_pc = (new_pc + i) % MEM_SIZE;
        for (int j = 0; j < 2; j++)
            core->arena[temp_pc].hex[j] = hexa[i * 2 + j];
        core->arena[temp_pc].champ_id = champ->prog_number;
        core->arena[temp_pc].c = base_to_dec(core->arena[temp_pc].hex, hex);
    }
}

void exec_st(instruction_t *instruction, champion_t *champion, corewar_t *core)
{
    int params[2] = {0, 0};
    char *hexa = NULL;
    int temp = 0;
    int value = 0;

    if (check_instruction_errors(instruction) == -1)
        return;
    temp = get_value(core, champion, instruction, params);
    if (instruction->type[1] != T_REG) {
        hexa = nbr_to_base(temp, "0123456789ABCDEF");
        value = champion->pc + instruction->args[1] % IDX_MOD;
        if (value < 0)
            value = MEM_SIZE + value % MEM_SIZE;
        else
            value = value % MEM_SIZE;
        write_register(core, champion, hexa, value);
    } else {
        champion->registers[instruction->args[1]] = temp;
    }
}

void exec_sti(instruction_t *function, champion_t *champion, corewar_t *core)
{
    int params[2] = {0, 0};
    int param[2] = {2, 0};
    int temp = 0;
    char *hexa = NULL;
    int new_pc = function->pc;

    if (check_instruction_errors(function) == -1)
        return;
    temp = get_value(core, champion, function, params);
    params[0] = 1;
    new_pc += (get_value(core, champion, function, params) +
    get_value(core, champion, function, param)) % IDX_MOD;
    if (new_pc < 0)
        new_pc = MEM_SIZE + new_pc % MEM_SIZE;
    else
        new_pc = new_pc % MEM_SIZE;
    hexa = nbr_to_base(temp, "0123456789ABCDEF");
    write_register(core, champion, hexa, new_pc);
}