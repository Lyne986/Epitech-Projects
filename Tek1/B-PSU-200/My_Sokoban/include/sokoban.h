/*
** EPITECH PROJECT, 2021
** Sokoban
** File description:
** sokoban
*/

#ifndef SOKOBAN_H_
#define SOKOBAN_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include "my.h"

typedef struct sokoban {
    char **map_arr;
    char **map_clone;
    char **map_def_clone;
    char *map_buff;
    int ch;
    int obstacles_nb;
    int holes_nb;
    int posx;
    int posy;
} sokoban;

int max_rows(sokoban *sokoban);
void initialyze_struct(sokoban *sokoban);
int my_lenght(char *filepath);
int read_myfile(char *filepath, sokoban *sokoban);
int map_width(sokoban *sokoban);
void player_pos(sokoban *sokoban);
int draw_map(sokoban *sokoban, char *str, int c);
int handle_errors(int ac, char *str, sokoban *sokoban, int c);
void move_up(sokoban *sokoban);
void move_down(sokoban *sokoban);
void move_left(sokoban *sokoban);
int game_over_status(sokoban *sokoban, int y);
int win_status(sokoban *sokoban, int y);
int display_usage(void);
int array_loop(sokoban *sokoban);
void move_right(sokoban *sokoban);
int check_map(sokoban *sokoban);
void handle_space_in(sokoban *sokoban);
int handle_window_size(sokoban *sokoban, int c);
int obstacle_move_right(sokoban *sokoban);
int obstacle_move_left(sokoban *sokoban);
int obstacle_move_down(sokoban *sokoban);
int obstacle_move_up(sokoban *sokoban);
int sokoban_loop(sokoban *sokoban, int c);
int max_col(sokoban *sokoban);
void player_direction(sokoban *sokoban);

#endif /* !SOKOBAN_H_ */
