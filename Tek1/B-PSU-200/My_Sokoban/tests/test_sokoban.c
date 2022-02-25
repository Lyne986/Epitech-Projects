/*
** EPITECH PROJECT, 2020
** B-PSU-100-MPL-1-1-myprintf-diogo.faria-martins
** File description:
** test_printfnb
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include "sokoban.h"

char *read_myfile_two(char *filepath, sokoban *sokoban)
{
    int buffersize = my_lenght(filepath);
    int fd = 0;
    int lenght = 0;
    char *buffer = malloc(sizeof(char) * (buffersize + 1));

    fd = open(filepath, O_RDONLY);
    lenght = read(fd, buffer, buffersize);
    buffer[lenght] = '\0';
    close(fd);
    return (buffer);
}

Test(sokoban_game, handle_errors_tests)
{
    sokoban sokoban;
    cr_assert_eq(handle_errors(1, "tests/map.txt", &sokoban, 0), 84);
}

Test(sokoban_game, handle_errors_tests2)
{
    sokoban sokoban;
    cr_assert_eq(handle_errors(2, "tests/mapnot.txt", &sokoban, 0), 84);
}

Test(sokoban_game, handle_errors_tests3)
{
    sokoban sokoban;
    cr_assert_eq(handle_errors(2, "tests/map_basic.txt", &sokoban, 0), 0);
}

Test(sokoban_game, handle_errors_tests4)
{
    sokoban sokoban;
    cr_assert_eq(handle_errors(2, "tests/map0=X.txt", &sokoban, 0), 84);
}

Test(sokoban_game, game_over)
{
    sokoban sokoban;
    draw_map(&sokoban, "tests/map.txt", 0);
    cr_assert_eq(game_over_status(&sokoban, 1), 1);
}

Test(sokoban_game, win)
{
    char *buff;
    sokoban sokoban;
    draw_map(&sokoban, "tests/map.txt", 0);
    buff = read_myfile_two("tests/map2.txt", &sokoban);
    sokoban.map_clone = my_str_to_word_array(buff, "\n");
    win_status(&sokoban, 1);
}

Test(sokoban_game, array_loop_test)
{
    char *buff;
    sokoban sokoban;
    draw_map(&sokoban, "tests/map.txt", 0);
    buff = read_myfile_two("tests/map2.txt", &sokoban);
    sokoban.map_clone = my_str_to_word_array(buff, "\n");
    array_loop(&sokoban);
}

Test(sokoban_game, check_initiliaze)
{
    sokoban sokoban;
    initialyze_struct(&sokoban);
    cr_assert_eq(sokoban.posx, 0);
}

Test(sokoban_game, move_left_test)
{
    sokoban sokoban;
    draw_map(&sokoban, "tests/map.txt", 0);
    move_left(&sokoban);
    cr_assert_eq(sokoban.map_arr[sokoban.posy][sokoban.posx - 1], 'P');
}

Test(sokoban_game, move_right_test)
{
    sokoban sokoban;
    draw_map(&sokoban, "tests/map.txt", 0);
    move_right(&sokoban);
    cr_assert_eq(sokoban.map_arr[sokoban.posy][sokoban.posx + 1], 'P');
}

Test(sokoban_game, move_up_test)
{
    sokoban sokoban;
    draw_map(&sokoban, "tests/map.txt", 0);
    move_up(&sokoban);
    cr_assert_eq(sokoban.map_arr[sokoban.posy - 1][sokoban.posx], 'P');
}

Test(sokoban_game, move_down_test)
{
    sokoban sokoban;
    draw_map(&sokoban, "tests/map.txt", 0);
    move_down(&sokoban);
    cr_assert_eq(sokoban.map_arr[sokoban.posy + 1][sokoban.posx], 'P');
}

Test(sokoban_game, move_obs_right)
{
    sokoban sokoban;
    draw_map(&sokoban, "tests/mapobs.txt", 0);
    move_right(&sokoban);
    cr_assert_eq(sokoban.map_arr[sokoban.posy][sokoban.posx + 2], 'X');
}

Test(sokoban_game, move_obs_left)
{
    sokoban sokoban;
    draw_map(&sokoban, "tests/mapobs.txt", 0);
    move_left(&sokoban);
    cr_assert_eq(sokoban.map_arr[sokoban.posy][sokoban.posx - 2], 'X');
}

Test(sokoban_game, move_obs_down)
{
    sokoban sokoban;
    draw_map(&sokoban, "tests/mapobs.txt", 0);
    move_down(&sokoban);
    cr_assert_eq(sokoban.map_arr[sokoban.posy + 2][sokoban.posx], 'X');
}

Test(sokoban_game, move_obs_up)
{
    sokoban sokoban;
    draw_map(&sokoban, "tests/mapobs.txt", 0);
    move_up(&sokoban);
    cr_assert_eq(sokoban.map_arr[sokoban.posy - 2][sokoban.posx], 'X');
}

Test(sokoban_game, move_obsblocked_right)
{
    sokoban sokoban;
    draw_map(&sokoban, "tests/mapobs_blocked.txt", 0);
    move_right(&sokoban);
    cr_assert_eq(obstacle_move_right(&sokoban), -1);
}

Test(sokoban_game, move_obsblocked_left)
{
    sokoban sokoban;
    draw_map(&sokoban, "tests/mapobs_blocked.txt", 0);
    move_left(&sokoban);
    cr_assert_eq(obstacle_move_left(&sokoban), -1);
}

Test(sokoban_game, move_obsblocked_down)
{
    sokoban sokoban;
    draw_map(&sokoban, "tests/mapobs_blocked.txt", 0);
    move_down(&sokoban);
    cr_assert_eq(obstacle_move_down(&sokoban), -1);
}

Test(sokoban_game, move_obsblocked_up)
{
    sokoban sokoban;
    draw_map(&sokoban, "tests/mapobs_blocked.txt", 0);
    move_up(&sokoban);
    cr_assert_eq(obstacle_move_up(&sokoban), -1);
}

Test(sokoban_game, player_direction)
{
    sokoban sokoban;
    sokoban.ch = KEY_LEFT;
}

Test(sokoban_game, map_reset)
{
    sokoban sokoban;
    draw_map(&sokoban, "tests/mapobs.txt", 0);
    handle_space_in(&sokoban);
    cr_assert_eq(sokoban.map_arr, sokoban.map_arr);
}

Test(sokoban_game, check_read_of_file)
{
    sokoban sokoban;
    cr_assert_eq(my_lenght("mdd"), 84);
    cr_assert_eq(read_myfile("mdd", &sokoban), 84);
    cr_assert_eq(read_myfile("mdd", &sokoban), 84);
}

Test(sokoban_game, check_player_position_x)
{
    sokoban sokoban;
    draw_map(&sokoban, "tests/map.txt", 0);
    player_pos(&sokoban);
    cr_assert_eq(sokoban.posx, 4);
}

Test(sokoban_game, check_player_position_y)
{
    sokoban sokoban;
    draw_map(&sokoban, "tests/map.txt", 0);
    player_pos(&sokoban);
    cr_assert_eq(sokoban.posy, 2);
}

Test(sokoban_game, o_replacement)
{
    char *buff;
    sokoban sokoban;
    draw_map(&sokoban, "tests/map.txt", 0);
    buff = read_myfile_two("tests/map2.txt", &sokoban);
    sokoban.map_clone = my_str_to_word_array(buff, "\n");
    player_pos(&sokoban);
}

Test(sokoban_game, check_size_x)
{
    sokoban sokoban;
    draw_map(&sokoban, "tests/map.txt", 0);
    cr_assert_eq(max_rows(&sokoban), 10);
}

Test(sokoban_game, check_size_y)
{
    sokoban sokoban;
    draw_map(&sokoban, "tests/map.txt", 0);
    cr_assert_eq(max_col(&sokoban), 12);
}

Test(sokoban_game, sokoban_loop_win)
{
    char *buff;
    sokoban sokoban;
    handle_errors(2, "tests/finishedmap.txt", &sokoban, 0);
    buff = read_myfile_two("tests/map_clone.txt", &sokoban);
    sokoban.map_clone = my_str_to_word_array(buff, "\n");
    sokoban.obstacles_nb = 1;
    cr_assert_eq(sokoban_loop(&sokoban, 'c'), 0);sokoban_loop(&sokoban, 'c');
}

Test(sokoban_game, sokoban_loop_loose)
{
    char *buff;
    sokoban sokoban;
    handle_errors(2, "tests/finishedmap.txt", &sokoban, 0);
    buff = read_myfile_two("tests/map_clone.txt", &sokoban);
    sokoban.map_clone = my_str_to_word_array(buff, "\n");
    cr_assert_eq(sokoban_loop(&sokoban, 'c'), 1);
}

Test(sokoban_game, key_left)
{
    sokoban sokoban;
    handle_errors(2, "tests/finishedmap.txt", &sokoban, 0);
    sokoban.ch = KEY_LEFT;
    player_direction(&sokoban);
}

Test(sokoban_game, key_right)
{
    sokoban sokoban;
    handle_errors(2, "tests/finishedmap.txt", &sokoban, 0);
    sokoban.ch = KEY_RIGHT;
    player_direction(&sokoban);
}

Test(sokoban_game, key_up)
{
    sokoban sokoban;
    handle_errors(2, "tests/finishedmap.txt", &sokoban, 0);
    sokoban.ch = KEY_UP;
    player_direction(&sokoban);
}

Test(sokoban_game, key_down)
{
    sokoban sokoban;
    handle_errors(2, "tests/finishedmap.txt", &sokoban, 0);
    sokoban.ch = KEY_DOWN;
    player_direction(&sokoban);
}

Test(sokoban_game, spaces)
{
    sokoban sokoban;
    handle_errors(2, "tests/finishedmap.txt", &sokoban, 0);
    sokoban.ch = 32;
    player_direction(&sokoban);
}

Test(sokoban_game, display_usage)
{
    sokoban sokoban;
    cr_assert_eq(display_usage(), 0);
}

Test(sokoban_game, sokoban_loop_tests)
{
    sokoban sokoban;
    handle_errors(2, "tests/map_clone.txt", &sokoban, 0);
    sokoban.ch = 32;
    cr_assert_eq(sokoban_loop(&sokoban, 63), 0);
}

Test(sokoban_game, sokoban_window_size_tests)
{
    sokoban sokoban;
    handle_errors(2, "tests/map_clone.txt", &sokoban, 0);
    sokoban.ch = 32;
    cr_assert_eq(sokoban_loop(&sokoban, 63), 0);
}

Test(sokoban_game, read_file_function)
{
    sokoban sokoban;
    draw_map(&sokoban, "tests/map.txt", 62);
    handle_errors(2, "tests/map_clone.txt", &sokoban, 0);
    sokoban.ch = 32;
    cr_assert_eq(sokoban_loop(&sokoban, 63), 0);
}

Test(sokoban_game, draw_map_error)
{
    sokoban sokoban;
    handle_errors(2, "tests/map_clone.txt", &sokoban, 62);
    handle_errors(2, "tests/map_clone.txt", &sokoban, 1002);
    LINES = 0;
    COLS = 0;
    cr_assert_eq(handle_window_size(&sokoban, 62), 0);
}