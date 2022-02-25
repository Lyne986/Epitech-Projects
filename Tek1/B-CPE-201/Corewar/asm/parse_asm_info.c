/*
** EPITECH PROJECT, 2020
** Corewar
** File description:
** parse_asm_info.c
*/

#include "../include/asm.h"

void print_champion_info(asm_t *my_asm)
{
    int bigendian = 0;
    int empty = 0;

    bigendian = biteshifting(my_asm->header.magic);
    write(my_asm->header.fd, &bigendian, sizeof(bigendian));
    write(my_asm->header.fd, my_asm->header.prog_name, PROG_NAME_LENGTH);
    my_asm->champ_size = biteshifting(my_asm->champ_size);
    if (my_asm->comment_exists)
        write(my_asm->header.fd, &empty, sizeof(empty));
    write(my_asm->header.fd, &my_asm->champ_size, sizeof(my_asm->champ_size));
    write(my_asm->header.fd, my_asm->header.comment, COMMENT_LENGTH);
    write(my_asm->header.fd, &empty, sizeof(empty));
}

void handle_asm_name(asm_t *my_asm, char **info)
{
    char **name = my_str_to_word_array(info[1], "\t\n");
    int size = my_strlen_array(name);

    if (my_strcmp(info[0], NAME_CMD_STRING) == 0) {
        if (my_asm->name_exists || size > 1 || \
        my_strlen(info[1]) > PROG_NAME_LENGTH)
            exit(84);
        my_asm->name_exists = 1;
        my_strcpy(my_asm->header.prog_name, info[1]);
    } else {
        exit(84);
    }
}

void handle_asm_comment(asm_t *my_asm, char **info)
{
    my_asm->comment_exists = 2;
    if (my_strcmp(info[0], COMMENT_CMD_STRING) == 0) {
        if (my_asm->name_exists == 0 || my_strlen(info[1]) > COMMENT_LENGTH)
            exit(84);
        my_asm->comment_exists = 1;
        my_strcpy(my_asm->header.comment, info[1]);
    } else
        exit(84);
}

void get_asm_info(asm_t *my_asm)
{
    char **info = split_string(my_asm->functions->command, " \t\n");

    error_handling_info(my_asm);
    if (!my_asm->name_exists) {
        handle_asm_name(my_asm, info);
    } else
        handle_asm_comment(my_asm, info);
}