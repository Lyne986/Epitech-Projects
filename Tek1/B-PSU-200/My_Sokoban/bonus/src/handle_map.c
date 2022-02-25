/*
** EPITECH PROJECT, 2021
** Sokoban
** File description:
** handle_map
*/

#include "sokoban.h"

int my_lenght(char *filepath)
{
    struct stat buff;
    int ret = stat(filepath, &buff);

    if (ret == -1)
        return (84);
    return (buff.st_size);
}

int read_myfile(char *filepath, sokoban *sokoban)
{
    int buffersize = my_lenght(filepath);
    int fd = 0;
    int lenght = 0;
    char *buffer = malloc(sizeof(char) * (buffersize + 1));

    fd = open(filepath, O_RDONLY);
    if (fd == -1)
        return (84);
    lenght = read(fd, buffer, buffersize);
    buffer[lenght] = '\0';
    close(fd);
    sokoban->map_buff = buffer;
    return (0);
}

void player_pos(sokoban *sokoban)
{
    for (int y = 0; sokoban->map_arr[y] != NULL; y++) {
        for (int x = 0; sokoban->map_arr[y][x] != 0; x++) {
            if (sokoban->map_clone[y][x] == 'O' &&
            sokoban->map_arr[y][x] == ' ') {
                sokoban->map_arr[y][x] = 'O';
            }
            if (sokoban->map_arr[y][x] == 'P') {
                sokoban->posx = x;
                sokoban->posy = y;
            }
        }
    }
}