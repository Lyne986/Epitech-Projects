/*
** EPITECH PROJECT, 2021
** bonus
** File description:
** handle_colors
*/

#include "sokoban.h"

void create_color_pars(void)
{
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_RED);
    init_pair(3, COLOR_BLACK, COLOR_BLACK);
    init_pair(4, COLOR_BLUE, COLOR_BLACK);
    init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(6, COLOR_YELLOW, COLOR_BLACK);
    init_pair(7, COLOR_RED, COLOR_BLACK);
}

void print_colored_display_three(sokoban *sokoban, int i, int x, int status)
{
    if ((i == 4  && x > 41 && x < 61) || (i == 3 &&
    x > 33 && x < 75) && status == 1) {
        attron(COLOR_PAIR(1));
        printw("%c", sokoban->map_arr[i][x]);
        attroff(COLOR_PAIR(1));
    }
    if (sokoban->map_arr[i][x] == '#' && status == 1) {
        attron(COLOR_PAIR(2));
        printw("%c", sokoban->map_arr[i][x]);
        attroff(COLOR_PAIR(2));
    }
    if (sokoban->map_arr[i][x] == '#' && status == 0) {
        attron(COLOR_PAIR(7));
        printw("%c", sokoban->map_arr[i][x]);
        attroff(COLOR_PAIR(7));
    }
}

void print_colored_display_two(sokoban *sokoban, int i, int x, int status)
{
    if (sokoban->map_arr[i][x] == 'X' && status == 0) {
        attron(COLOR_PAIR(5));
        printw("%c", sokoban->map_arr[i][x]);
        attroff(COLOR_PAIR(5));
    }
    if (sokoban->map_arr[i][x] == 'O' && status == 0) {
        attron(COLOR_PAIR(6));
        printw("%c", sokoban->map_arr[i][x]);
        attroff(COLOR_PAIR(6));
    }
    if (sokoban->map_arr[i][x] == ' ' || sokoban->map_arr[i][x] == '\n') {
        attron(COLOR_PAIR(3));
        printw("%c", sokoban->map_arr[i][x]);
        attroff(COLOR_PAIR(3));
    }
    if (sokoban->map_arr[i][x] == '1'
    || sokoban->map_arr[i][x] == '2'
    || sokoban->map_arr[i][x] == '3'
    || sokoban->map_arr[i][x] == '4')
        printw("%c", sokoban->map_arr[i][x]);
}

void print_colored_display(sokoban *sokoban, int i, int status)
{
    for (int x = 0; sokoban->map_arr[i][x]; x++) {
        if (sokoban->map_arr[i][x] == 'P' && status == 0) {
            attron(COLOR_PAIR(4));
            printw("%c", sokoban->map_arr[i][x]);
            attroff(COLOR_PAIR(4));
        }
        print_colored_display_two(sokoban, i, x, status);
        print_colored_display_three(sokoban, i, x, status);
    }
}