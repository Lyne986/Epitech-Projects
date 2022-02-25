/*
** EPITECH PROJECT, 2021
** B-CPE-201-MPL-2-1-corewar-bastien.boymond
** File description:
** handle_dashes
*/

#include "../../include/corewar.h"

int verify_champion_prognb(corewar_t *core, int prognb)
{
    for (int i = 0; i < core->nb_champ; i++) {
        if (core->champions[i]->prog_number == prognb)
            return (-1);
    }
    return (0);
}

int get_unused_prognb(corewar_t *core)
{
    int i = 0;

    for (i = 0; i < core->nb_champ; i++) {
        if (verify_champion_prognb(core, i) != -1)
            return (i);
    }
    return (i);
}

void prog_number_errors(corewar_t *core, char **av, int *i, int *n)
{
    int prog_nb = 0;

    if (*n != 0 || av[*i + 1] == NULL || is_number(av[*i + 1]) == 0)
        exit(89);
    prog_nb = my_getnbr(av[*i + 1]);
    if (prog_nb < 1 || prog_nb > 4)
        exit(80);
    for (int s = 0; core->champions[s]; s++) {
        if (core->champions[s]->prog_number == prog_nb)
            exit(85);
    }
    (*n) = prog_nb;
    (*i) += 1;
}

void champ_after_load_adress(char **av, int *i, int *a)
{
    if (*a != 0 || av[*i + 1] == NULL || is_number(av[*i + 1]) == 0)
        exit(88);
    if (av[*i + 2] == NULL)
        exit(87);
    *a = my_getnbr(av[*i + 1]);
    (*i) += 1;
}

void champion_file(corewar_t *core, char *filepath, int *a, int *n)
{
    create_champion(core, filepath, *a, *n);
    (*a) = 0;
    (*n) = 0;
}