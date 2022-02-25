/*
** EPITECH PROJECT, 2020
** Corewar/Corewar
** File description:
** update_arena.c
*/

#include "../../include/corewar.h"

void execute_champion(corewar_t *core, int i)
{
    if (!core->champions[i])
        return;
    if (core->champions[i]->cooldown == 0)
        execute_instruction(core, core->champions[i]);
    else
        core->champions[i]->cooldown -= 1;
}

void kill_champion(corewar_t *c, int n, int id)
{
    for (int i = 0; i < c->nb_champ; i++) {
        if (i != n && c->champions[i] && c->champions[i]->prog_number == id)
            c->champions[i] = NULL;
    }
    c->champions[n] = NULL;
}

void update_live_counter(corewar_t *core, int i, int *nb_alive)
{
    if (core->champions[i] && core->cycle >= core->nbr_cycles) {
        if (core->champions[i]->live_counter[0] == 0)
            kill_champion(core, i, core->champions[i]->prog_number);
        else {
            core->champions[i]->live_counter[0] = 0;
            nb_alive[0] += 1;
            nb_alive[1] = core->champions[i]->prog_number;
        }
    } else if (core->cycle < core->nbr_cycles) {
        nb_alive[0] = -1;
    }
}

void update_arena(corewar_t *core, all_t *a)
{
    int nb_alive[2] = {0, 0};

    for (int i = 0; i < core->nb_champ; i++)
        execute_champion(core, i);
    for (int i = 0; i < core->max_champ; i++)
        update_live_counter(core, i, nb_alive);
    if (nb_alive[0] == 1) {
        my_printf("Le joueur %d (%s) a gagné.\n", nb_alive[1],
        get_champion_from_id(core, nb_alive[1])->name);
        exit(0);
    }
    if (nb_alive[0] == 0) {
        if (core->last_live.id != -1) {
            my_printf("Le joueur %d (%s) a gagné.\n", core->last_live.id,
            core->last_live.name);
        }
        exit(0);
    }
    core->cycle = core->cycle < core->nbr_cycles ? core->cycle + 1 : 0;
    core->total_cycles++;
}