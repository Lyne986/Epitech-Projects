/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** utilities_instructions.c
*/

#include "../../include/corewar.h"

int get_value(corewar_t *core, champion_t *champ, instruction_t *func, int *i)
{
    int new_pc = champ->pc;
    char *hex = "0123456789ABCDEF";

    if (func->type[i[0]] == T_REG)
        return (champ->registers[func->args[i[0]]]);
    if (func->type[i[0]] == T_DIR)
        return (func->args[i[0]]);
    if (i[1] == 1)
        new_pc += func->args[i[0]] % IDX_MOD;
    else
        new_pc += func->args[i[0]];
    core->hex[REG_SIZE * 2] = 0;
    for (int n = 0; n < REG_SIZE; n++)
        my_strcat_from(core->hex, core->arena[new_pc + n].hex, n * 2);
    return (base_to_dec(core->hex, hex));
}

int check_reg(instruction_t *instruction, op_t op, int i)
{
    if (instruction->type[i] != T_REG)
        return (0);
    if (op.type[i] % 2 == 0)
        return (-1);
    if (instruction->args[i] < 1 || instruction->args[i] > REG_NUMBER) {
        return (-1);
    }
    return (0);
}

int check_indirect(instruction_t *instruction, op_t op, int i)
{
    if (instruction->type[i] != T_IND)
        return (0);
    if (op.type[i] < 4)
        return (-1);
    return (0);
}

int check_direct(instruction_t *instruction, op_t op, int i)
{
    if (instruction->type[i] != T_DIR)
        return (0);
    if (op.type[i] == 1 || op.type[i] == 4 || op.type[i] == 5)
        return (-1);
    return (0);
}

int check_instruction_errors(instruction_t *instruction)
{
    int type = 0;
    op_t op;

    if (instruction->code < 1 || instruction->code > 16)
        return (-1);
    op = op_tab[instruction->code - 1];
    for (int i = 0; i < op.nbr_args; i++) {
        type = instruction->type[i];
        if (type != 1 && type != 2 && type != 4)
            return (-1);
        if (check_reg(instruction, op, i) == -1)
            return (-1);
        if (check_direct(instruction, op, i) == -1)
            return (-1);
        if (check_indirect(instruction, op, i) == -1)
            return (-1);
    }
    return (0);
}