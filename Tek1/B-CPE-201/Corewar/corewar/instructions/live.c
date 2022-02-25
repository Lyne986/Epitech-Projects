/*
** EPITECH PROJECT, 2020
** Corewar/Corewar
** File description:
** live.c
*/

#include "../../include/corewar.h"

void update_nbr_cycles(corewar_t *core)
{
    core->nbr_cycles -= CYCLE_DELTA;
    core->live = 0;
}

void exec_live(instruction_t *function, champion_t *champion, corewar_t *core)
{
    int params[2] = {0, 0};
    champion_t *current_champion = 0;
    int id = 0;

    if (check_instruction_errors(function) == -1)
        return;
    id = get_value(core, champion, function, params);
    current_champion = get_champion_from_id(core, id);
    if (current_champion) {
        current_champion->live_counter[0] += 1;
        core->live += 1;
        my_printf("Le joueur %d (%s) est en vie.\n", id,
        current_champion->name);
        core->last_live.id = id;
        core->last_live.name = current_champion->name;
    }
    if (core->live > NBR_LIVE)
        update_nbr_cycles(core);
}
