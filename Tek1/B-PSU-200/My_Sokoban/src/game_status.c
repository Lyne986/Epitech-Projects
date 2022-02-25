/*
** EPITECH PROJECT, 2021
** Sokoban
** File description:
** game_status
*/

#include "sokoban.h"

int win_status(sokoban *sokoban, int y)
{
    int counter = 0;

    for (int x = 0; sokoban->map_arr[y][x] != 0; x++) {
        if (sokoban->map_arr[y][x] == 'X' && sokoban->map_clone[y][x] == 'O') {
            counter++;
        }
    }
    return (counter);
}

int game_over_status(sokoban *sokoban, int y)
{
    int counter = 0;

    for (int x = 0; sokoban->map_arr[y][x] != 0; x++) {
        if (sokoban->map_arr[y][x] == 'X' && (
            (sokoban->map_arr[y][x - 1] == '#' &&
            sokoban->map_arr[y - 1][x] == '#') ||
            (sokoban->map_arr[y][x + 1] == '#' &&
            sokoban->map_arr[y - 1][x] == '#') ||
            (sokoban->map_arr[y][x - 1] == '#' &&
            sokoban->map_arr[y + 1][x] == '#') ||
            (sokoban->map_arr[y][x + 1] == '#' &&
            sokoban->map_arr[y + 1][x] == '#'))) {
            counter++;
        }
    }
    return (counter);
}

int array_loop(sokoban *sokoban)
{
    int win_counter = 0;
    int game_counter = 0;

    for (int y = 0; sokoban->map_arr[y] != NULL; y++) {
        win_counter += win_status(sokoban, y);
        game_counter += game_over_status(sokoban, y);
    }
    if (win_counter == sokoban->obstacles_nb) {
        return (0);
    }
    if (game_counter == sokoban->obstacles_nb) {
        return (1);
    }
    return (2);
}

int draw_map(sokoban *sokoban, char *str, int c)
{
    if (read_myfile(str, sokoban) == 84 || c == 62)
        return (84);
    sokoban->map_arr = my_str_to_word_array(sokoban->map_buff, "\n");
    sokoban->map_clone = my_str_to_word_array(sokoban->map_buff, "\n");
    return (0);
}

void initialyze_struct(sokoban *sokoban)
{
    sokoban->posx = 0;
    sokoban->posy = 0;
    sokoban->obstacles_nb = 0;
    sokoban->holes_nb = 0;
    sokoban->ch = 0;
}