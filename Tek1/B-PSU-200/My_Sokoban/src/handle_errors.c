/*
** EPITECH PROJECT, 2021
** Sokoban
** File description:
** handle_errors
*/

#include "sokoban.h"

int check_map(sokoban *sokoban)
{
    int p = 0;
    int x = 0;
    int o = 0;
    for (int i = 0; sokoban->map_buff[i]; i++) {
        if (sokoban->map_buff[i] != ' ' && sokoban->map_buff[i] != '#'
        && sokoban->map_buff[i] != 'P' && sokoban->map_buff[i] != 'O'
        && sokoban->map_buff[i] != 'X'  && sokoban->map_buff[i] != '\n'
        && sokoban->map_buff[i] != '\0')
            return (84);
        sokoban->map_buff[i] == 'X' ? x++ : 0;
        sokoban->map_buff[i] == 'P' ? p++ : 0;
        sokoban->map_buff[i] == 'O' ? o++ : 0;
    }
    sokoban->holes_nb = o;
    sokoban->obstacles_nb = o;
    if (x != o || p != 1 || x == 0 || o == 0)
        return (84);
    return (0);
}

int max_rows(sokoban *sokoban)
{
    int i = 0;

    for (int y = 0; sokoban->map_arr[y] != NULL; y++) {
        for (int x = 0; sokoban->map_arr[y][x] != 0; x++) {
            if (y > i)
                i = y;
        }
    }
    return (i);
}

int max_col(sokoban *sokoban)
{
    int i = 0;

    for (int y = 0; sokoban->map_arr[y] != NULL; y++) {
        for (int x = 0; sokoban->map_arr[y][x] != 0; x++) {
            if (x > i)
                i = x;
        }
    }
    return (i);
}

int handle_window_size(sokoban *sokoban, int c)
{
    int row = max_rows(sokoban);
    int col = max_col(sokoban);

    if ((row >= LINES || col > COLS) && c != 62) {
        return (-1);
    }
    return (0);
}

int handle_errors(int ac, char *str, sokoban *sokoban, int c)
{
    if (ac != 2)
        return (84);
    if (draw_map(sokoban, str, c) == 84)
        return (84);
    if (check_map(sokoban) == 84)
        return (84);
    return (0);
}