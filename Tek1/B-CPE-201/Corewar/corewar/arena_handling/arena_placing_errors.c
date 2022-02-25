/*
** EPITECH PROJECT, 2021
** B-CPE-201-MPL-2-1-corewar-bastien.boymond
** File description:
** arena_placing_errors
*/

#include "../../include/corewar.h"

void compare_each_champ(corewar_t *core, int *vm_pos, int i)
{
    for (int j = i + 1; j < core->nb_champ; j++) {
        if (vm_pos[i] <= vm_pos[j] + core->champions[j]->size
        && vm_pos[i] + core->champions[i]->size >= vm_pos[j])
            exit(84);
    }
}

void check_address_issues(corewar_t *core, int *vm_pos)
{
    for (int i = 0; i < core->nb_champ; i++) {
        compare_each_champ(core, vm_pos, i);
    }
}