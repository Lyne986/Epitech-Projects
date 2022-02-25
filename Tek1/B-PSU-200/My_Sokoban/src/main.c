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
        printw("%s", sokoban->map_arr[i]);
    refresh();
    endwin();
    refresh();
}

int main(int ac, char *av[])
{
    int return_nb = 0;
    sokoban sokoban;

    initialyze_struct(&sokoban);
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && display_usage() == 0)
        return (0);
    if (handle_errors(ac, av[1], &sokoban, 144030) == 84)
        return (84);
    initscr();
    keypad(stdscr, TRUE);
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