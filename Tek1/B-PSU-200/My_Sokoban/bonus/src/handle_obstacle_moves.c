/*
** EPITECH PROJECT, 2021
** Sokoban
** File description:
** handle_push_moves
*/

#include "sokoban.h"

int obstacle_move_right(sokoban *sokoban)
{
    if (sokoban->map_arr[sokoban->posy][sokoban->posx + 2] == '#' ||
    sokoban->map_arr[sokoban->posy][sokoban->posx + 2] == 'X' )
        return (-1);
    sokoban->map_arr[sokoban->posy][sokoban->posx] = ' ';
    sokoban->map_arr[sokoban->posy][sokoban->posx + 1] = 'P';
    sokoban->map_arr[sokoban->posy][sokoban->posx + 2] = 'X';
    return (0);
}

int obstacle_move_left(sokoban *sokoban)
{
    if (sokoban->map_arr[sokoban->posy][sokoban->posx - 2] == '#' ||
    sokoban->map_arr[sokoban->posy][sokoban->posx - 2] == 'X' )
        return (-1);
    sokoban->map_arr[sokoban->posy][sokoban->posx] = ' ';
    sokoban->map_arr[sokoban->posy][sokoban->posx - 1] = 'P';
    sokoban->map_arr[sokoban->posy][sokoban->posx - 2] = 'X';
    return (0);
}

int obstacle_move_up(sokoban *sokoban)
{
    if (sokoban->map_arr[sokoban->posy - 2][sokoban->posx] == '#' ||
    sokoban->map_arr[sokoban->posy - 2][sokoban->posx] == 'X' )
        return (-1);
    sokoban->map_arr[sokoban->posy][sokoban->posx] = ' ';
    sokoban->map_arr[sokoban->posy - 1][sokoban->posx] = 'P';
    sokoban->map_arr[sokoban->posy - 2][sokoban->posx] = 'X';
    return (0);
}

int obstacle_move_down(sokoban *sokoban)
{
    if (sokoban->map_arr[sokoban->posy + 2][sokoban->posx] == '#' ||
    sokoban->map_arr[sokoban->posy + 2][sokoban->posx] == 'X' )
        return (-1);
    sokoban->map_arr[sokoban->posy][sokoban->posx] = ' ';
    sokoban->map_arr[sokoban->posy + 1][sokoban->posx] = 'P';
    sokoban->map_arr[sokoban->posy + 2][sokoban->posx] = 'X';
    return (0);
}