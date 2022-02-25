/*
** EPITECH PROJECT, 2020
** B-CPE-201-MPL-2-1-corewar-bastien.boymond
** File description:
** champion_utilities.c
*/

#include "../include/corewar.h"

champion_t *get_champion_from_id(corewar_t *core, int n)
{
    for (int i = 0; i < core->max_champ; i++) {
        if (core->champions[i] != NULL && core->champions[i]->prog_number == n)
            return (core->champions[i]);
    }
    return (NULL);
}