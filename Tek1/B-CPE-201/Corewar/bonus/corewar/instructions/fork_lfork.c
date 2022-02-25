/*
** EPITECH PROJECT, 2020
** Corewar/Corewar
** File description:
** fork_lfork.c
*/

#include "../../include/corewar.h"

champion_t *create_child_champion(champion_t *champion, int next_pc)
{
    champion_t *child = my_malloc(sizeof(champion_t));

    child->prog_number = champion->prog_number;
    child->carry = champion->carry;
    child->pc = champion->pc;
    child->next_pc = next_pc;
    child->name = champion->name;
    child->comment = champion->comment;
    child->instructions = champion->instructions;
    child->cooldown = 0;
    child->live_counter = champion->live_counter;
    for (int i = 0; i <= REG_NUMBER; i++)
        child->registers[i] = champion->registers[i];
    child->size = champion->size;
    return (child);
}

void exec_fork(instruction_t *function, champion_t *champion, corewar_t *core)
{
    int params[2] = {0, 0};
    int child_pc = champion->pc;
    int nb = 0;

    if (check_instruction_errors(function) == -1)
        return;
    core->nb_champ += 1;
    nb = core->nb_champ;
    core->champions = my_realloc(core->champions, sizeof(champion_t *) * nb);
    child_pc += get_value(core, champion, function, params) % IDX_MOD;
    if (child_pc < 0)
        child_pc = MEM_SIZE + child_pc % MEM_SIZE;
    else
        child_pc = child_pc % MEM_SIZE;
    core->champions[nb - 1] = create_child_champion(champion, child_pc);
}

void exec_lfork(instruction_t *function, champion_t *champion, corewar_t *core)
{
    int params[2] = {0, 0};
    int child_pc = champion->pc;
    int nb = 0;

    if (check_instruction_errors(function) == -1)
        return;
    core->nb_champ += 1;
    nb = core->nb_champ;
    core->champions = my_realloc(core->champions, sizeof(champion_t *) * nb);
    child_pc += get_value(core, champion, function, params);
    if (child_pc < 0)
        child_pc = MEM_SIZE + child_pc % MEM_SIZE;
    else
        child_pc = child_pc % MEM_SIZE;
    core->champions[nb - 1] = create_child_champion(champion, child_pc);
}