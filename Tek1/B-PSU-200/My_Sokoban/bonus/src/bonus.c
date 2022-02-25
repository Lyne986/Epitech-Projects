/*
** EPITECH PROJECT, 2021
** bonus
** File description:
** bonus
*/

#include "sokoban.h"

void char_pos(sokoban *sokoban, char c)
{
    for (int y = 0; sokoban->map_arr[y] != NULL; y++) {
        for (int x = 0; sokoban->map_arr[y][x] != 0; x++) {
            if (sokoban->map_arr[y][x] == c) {
                sokoban->posx = x;
                sokoban->posy = y;
            }
        }
    }
}

char *read_myfile_bonus(char *filepath, sokoban *sokoban)
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

char *handle_pressed_keys_two(sokoban *sokoban, int ch, char *map)
{
    if (ch == 51 || sokoban->bonus_s[0].map_choosen == 3) {
        char_pos(sokoban, '3');
        sokoban->bonus_s[0].map_choosen = 3;
        if (ch == 10)
            map = "maps/map_three.txt";
    }
    if (ch == 52 || sokoban->bonus_s[0].map_choosen == 4) {
        char_pos(sokoban, '4');
        sokoban->bonus_s[0].map_choosen = 4;
        if (ch == 10)
            map = "maps/map_four.txt";
    }
    return (map);
}

char *handle_pressed_keys(sokoban *sokoban, int ch)
{
    char *map = NULL;

    if (ch == 49  || sokoban->bonus_s[0].map_choosen == 1) {
        char_pos(sokoban, '1');
        sokoban->bonus_s[0].map_choosen = 1;
        if (ch == 10)
            map = "maps/map_one.txt";
    }
    if (ch == 50 || sokoban->bonus_s[0].map_choosen == 2) {
        char_pos(sokoban, '2');
        sokoban->bonus_s[0].map_choosen = 2;
        if (ch == 10)
            map = "maps/map_two.txt";
    }
    map = handle_pressed_keys_two(sokoban, ch, map);
    return (map);
}

char *map_chooser(sokoban *sokoban)
{
    char *map = NULL;
    int ch = 0;
    sokoban->bonus_s[0].map_choosen = 0;
    draw_map(sokoban, "maps/map_chooser.txt", 312654);
    while (true) {
        clear();
        for (int i = 0; sokoban->map_arr[i]; i++) {
            print_colored_display(sokoban, i, 1);
        }
        move(sokoban->posy, sokoban->posx);
        refresh();
        ch = getch();
        map = handle_pressed_keys(sokoban, ch);
        if (map != NULL)
            break;
    }
    return (map);
}