/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** load_history_file
*/

#include "../../include/corewar.h"

void load_history(all_t *a)
{
    if (a->core->total_cycles - a->min_save > 1 && a->saving == true) {
        a->pause = true;
        if (a->history[a->core->total_cycles - a->min_save - 1] != NULL) {
            a->core = a->history[a->core->total_cycles - a->min_save - 1];
        }
    }
}