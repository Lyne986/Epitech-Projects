/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** write_history_file
*/

#include "../../include/corewar.h"

champion_t *load_champion_copy(champion_t *champion)
{
    champion_t *child = my_malloc(sizeof(champion_t));

    if (champion == NULL)
        return (NULL);
    child->prog_number = champion->prog_number;
    child->carry = champion->carry;
    child->pc = champion->pc;
    child->next_pc = champion->next_pc;
    child->name = champion->name;
    child->comment = champion->comment;
    child->instructions = champion->instructions;
    child->next_instruction = champion->next_instruction;
    child->cooldown = champion->cooldown;
    child->live_counter = champion->live_counter;
    for (int i = 0; i <= REG_NUMBER; i++)
        child->registers[i] = champion->registers[i];
    child->size = champion->size;
    return (child);
}

corewar_t *load_core_copy(corewar_t *new_core, all_t *a)
{
    new_core = my_malloc(sizeof(corewar_t));
    new_core->hex = my_malloc(sizeof(char) * 9);
    new_core->last_live = a->core->last_live;
    new_core->live = a->core->live;
    new_core->max_champ = a->core->max_champ;
    new_core->nb_champ = a->core->nb_champ;
    new_core->total_cycles = a->core->total_cycles;
    new_core->dump_cycles = a->core->dump_cycles;
    new_core->cycle = a->core->cycle;
    new_core->nbr_cycles = a->core->nbr_cycles;
    for (int i = 0; i < MEM_SIZE; i++)
        new_core->arena[i] = a->core->arena[i];
    new_core->champions = my_malloc(sizeof(champion_t *) * a->core->nb_champ);
    for (int i = 0; i < a->core->nb_champ; i++)
        new_core->champions[i] = load_champion_copy(a->core->champions[i]);
    return (new_core);
}

void save_to_history(all_t *a)
{
    corewar_t *new_core = NULL;

    if (a->saving == true && (a->core->total_cycles - a->min_save) < 50000) {
        new_core = load_core_copy(new_core, a);
        a->history[a->core->total_cycles - a->min_save] = new_core;
    }
}