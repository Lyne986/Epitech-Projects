/*
** EPITECH PROJECT, 2021
** Sokoban
** File description:
** handle_moves
*/

#include "sokoban.h"

void move_right(sokoban *sokoban)
{
    player_pos(sokoban);
    if (sokoban->map_arr[sokoban->posy][sokoban->posx + 1] != '#') {
        if (sokoban->map_arr[sokoban->posy][sokoban->posx + 1] == 'X' ) {
            obstacle_move_right(sokoban);
        } else {
            sokoban->map_arr[sokoban->posy][sokoban->posx + 1] = 'P';
            sokoban->map_arr[sokoban->posy][sokoban->posx] = ' ';
        }
    }
    return;
}

void move_left(sokoban *sokoban)
{
    player_pos(sokoban);
    if (sokoban->map_arr[sokoban->posy][sokoban->posx - 1] != '#') {
        if (sokoban->map_arr[sokoban->posy][sokoban->posx - 1] == 'X' ) {
            obstacle_move_left(sokoban);
        } else {
            sokoban->map_arr[sokoban->posy][sokoban->posx - 1] = 'P';
            sokoban->map_arr[sokoban->posy][sokoban->posx] = ' ';
        }
    }
    return;
}

void move_down(sokoban *sokoban)
{
    player_pos(sokoban);
    if (sokoban->map_arr[sokoban->posy + 1][sokoban->posx] != '#') {
        if (sokoban->map_arr[sokoban->posy + 1][sokoban->posx] == 'X' ) {
            obstacle_move_down(sokoban);
        } else {
            sokoban->map_arr[sokoban->posy + 1][sokoban->posx] = 'P';
            sokoban->map_arr[sokoban->posy][sokoban->posx] = ' ';
        }
    }
    return;
}

void move_up(sokoban *sokoban)
{
    player_pos(sokoban);
    if (sokoban->map_arr[sokoban->posy - 1][sokoban->posx] != '#') {
        if (sokoban->map_arr[sokoban->posy - 1][sokoban->posx] == 'X' ) {
            obstacle_move_up(sokoban);
        } else {
            sokoban->map_arr[sokoban->posy - 1][sokoban->posx] = 'P';
            sokoban->map_arr[sokoban->posy][sokoban->posx] = ' ';
        }
    }
    return;
}

void handle_space_in(sokoban *sokoban)
{
    sokoban->map_arr = my_str_to_word_array(sokoban->map_buff, "\n");
    sokoban->map_clone = my_str_to_word_array(sokoban->map_buff, "\n");
    return;
}