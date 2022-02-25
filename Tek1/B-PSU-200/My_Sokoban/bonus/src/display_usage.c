/*
** EPITECH PROJECT, 2021
** B-PSU-200-MPL-2-1-mysokoban-diogo.faria-martins
** File description:
** display_usage
*/

#include "sokoban.h"

int display_usage(void)
{
    write(1, "USAGE\n     ./my_sokoban map\nDESCRIPTION\n     ", 43   );
    write(1, "  map  file representing the warehouse map, cont \
aining '#' for walls,\n          'P' for the player, 'X' for \
boxes and 'O' for storage locations.", 145);
    return (0);
}