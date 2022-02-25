/*
** EPITECH PROJECT, 2021
** Sokoban
** File description:
** game_loop
*/

#include "sokoban.h"

void handle_bonus_display(sokoban *sokoban)
{
    if (sokoban->ch == 263) {
        char *map = map_chooser(sokoban);
        handle_errors(1, map, sokoban, 123);
        
    }
}

void player_direction(sokoban *sokoban)
{
    if (sokoban->ch == KEY_LEFT) {
        move_left(sokoban);
    }
    if (sokoban->ch == KEY_RIGHT) {
        move_right(sokoban);
    }
    if (sokoban->ch == KEY_UP) {
        move_up(sokoban);
    }
    if (sokoban->ch == KEY_DOWN) {
        move_down(sokoban);
    }
    if (sokoban->ch == 32) {
        handle_space_in(sokoban);
    }
    handle_bonus_display(sokoban);
}

void handle_terminal_error(sokoban *sokoban, int c)
{
    clear();
    while (1) {
        mvprintw(LINES / 2, COLS / 2 - 15, "TOO BIG MAP FOR TERMINAL");
        refresh();
        if (handle_window_size(sokoban, 0) != -1 || c == 63)
            break;
    }
}

int sokoban_loop(sokoban *sokoban, int c)
{
    clear();
    while (1) {
        clear();
        player_pos(sokoban);
        for (int i = 0; sokoban->map_arr[i]; i++)
            print_colored_display(sokoban, i, 0);
        refresh();
        if (array_loop(sokoban) == 1)
            return (1);
        if (array_loop(sokoban) == 0)
            return (0);
        if (handle_window_size(sokoban, 0) == -1 || c == 63) {
            handle_terminal_error(sokoban, c);
        }
        sokoban->ch = getch();
        player_direction(sokoban);
        if (c == 62 || c == 63)
            return (0);
    }
    return (0);
}