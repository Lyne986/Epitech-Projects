/*
** EPITECH PROJECT, 2020
** Corewar/Corewar
** File description:
** main.c
*/

#include "../../include/corewar.h"

bool verify_dash_arg(char **av, int i)
{
    if (my_strncmp(av[i], "-", 1) == 0) {
        if (my_strcmp(av[i], "-a") != 0 && my_strcmp(av[i], "-n") != 0
        && my_strcmp(av[i], "-dump") != 0)
            exit(84);
    }
    return (false);
}

void verify_dump(corewar_t *core, char **av, int i, int *dump)
{
    int nb = 0;

    if (my_strcmp(av[i], "-dump") == 0) {
        if ((av[i + 1] == NULL || is_number(av[i + 1]) == 0))
            exit(84);
        nb = my_getnbr(av[i + 1]);
        if (nb < 0)
            exit(84);
        core->dump_cycles = nb;
        (*dump) += 1;
    }
    if (*dump > 1)
        exit(84);
}

void parse_args(corewar_t *core, char **av)
{
    int n = 0;
    int a = 0;
    int dump = 0;
    bool parse = false;

    for (int i = 1; av[i]; i++) {
        parse = verify_dash_arg(av, i);
        verify_dump(core, av, i, &dump);
        if (my_strcmp(av[i], "-n") == 0) {
            parse = true;
            prog_number_errors(core, av, &i, &n);
        }
        if (!parse && my_strcmp(av[i], "-a") == 0)
            champ_after_load_adress(av, &i, &a);
        if (read_file(av[i]) != NULL) {
            champion_file(core, av[i], &a, &n);
        }
    }
    if (n != 0 || a != 0)
        exit(84);
}

void error_handler(corewar_t *core, char **av, int ac)
{
    if (ac <= 1) {
        exit(84);
    }
    parse_args(core, av);
    if (core->nb_champ < 2 || core->nb_champ > 4)
        exit(84);
    for (int i = 0; i < core->nb_champ; i++) {
        if (core->champions[i]->prog_number == 0) {
            core->champions[i]->prog_number = get_unused_prognb(core);
        }
    }
}