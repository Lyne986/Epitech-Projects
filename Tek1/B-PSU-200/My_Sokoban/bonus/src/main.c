/*
** EPITECH PROJECT, 2021
** B-CPE-210-MPL-2-1-solostumper04-diogo.faria-martins
** File description:
** main
*/

#include "sokoban.h"

void print_map(sokoban *sokoban)
{
    clear();
    for (int i = 0; sokoban->map_arr[i]; i++)
        print_colored_display(sokoban, i, 0);
    refresh();
    endwin();
    refresh();
}

int main(int ac, char *av[])
{
    int return_nb = 0;
    sokoban sokoban;
    char *map;

    initialyze_struct(&sokoban);
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && display_usage() == 0)
        return (0);
    map = map_chooser(&sokoban);
    if (handle_errors(ac, map, &sokoban, 144030) == 84)
        return (84);
    return_nb = sokoban_loop(&sokoban, 'z');
    if (return_nb == 0) {
        print_map(&sokoban);
        return (0);
    }
    if (return_nb == 1) {
        print_map(&sokoban);
        return (1);
    }
    return (0);
}