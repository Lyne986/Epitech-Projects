/*
** EPITECH PROJECT, 2021
** B-CPE-201-MPL-2-1-corewar-bastien.boymond
** File description:
** main
*/

#include "./include/corewar.h"

int main(int ac, char **av)
{
    champion_t *champion;

    if (ac != 2)
        return (84);
    champion = create_champion(av[1]);
    print_champion(champion);
    return (0);
}