/*
** EPITECH PROJECT, 2020
** Corewar/Asm
** File description:
** main.c
*/

#include "../include/asm.h"

int main(int argc, char **argv)
{
    asm_t my_asm;
    char **array = NULL;
    char *filename = NULL;

    if (argc != 2)
        return (84);
    init_asm(&my_asm);
    read_champion(argv[1], &my_asm);
    parse_champion(&my_asm);
    array = my_str_to_word_array(argv[1], "./");
    filename = my_strcat(array[my_strlen_array(array) - 2], ".cor");
    my_asm.header.fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    print_champion(&my_asm);
    close(my_asm.header.fd);
    return (0);
}