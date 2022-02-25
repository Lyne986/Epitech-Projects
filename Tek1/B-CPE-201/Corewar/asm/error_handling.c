/*
** EPITECH PROJECT, 2020
** Corewar
** File description:
** parse_asm_info.c
*/

#include "../include/asm.h"

void error_handling_info(asm_t *my_asm)
{
    char **line = my_str_to_word_array(my_asm->functions->command, "\n");
    char **error = NULL;

    for (int i = 0; i < 1; i++) {
        error = my_str_to_word_array(line[i], " \t");
        if (error[1] == NULL)
            exit(84);
        if (error[1][0] != '\"')
            exit(84);
    }
}