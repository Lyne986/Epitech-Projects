/*
** EPITECH PROJECT, 2021
** B-CPE-201-MPL-2-1-corewar-bastien.boymond
** File description:
** init_parsing
*/

#include "../include/asm.h"

void add_to_linked_lists(asm_t *my_asm, char *line, int index)
{
    char *dup_line = my_strdup(line);
    char **data = NULL;
    int len = 0;

    if (dup_line[my_strlen(dup_line) - 1] == '\n')
        dup_line[my_strlen(dup_line) - 1] = 0;
    data = my_str_to_word_array(dup_line, " \t");
    if (dup_line[0] == COMMENT_CHAR || dup_line[0] == 0)
        return;
    len = my_strlen(data[0]);
    if (data[0][len - 1] == ':') {
        data[0][len - 1] = 0;
        if (data[1] != NULL) {
            push_back_function(&my_asm->functions, &dup_line[len], index);
        }
        push_back_label(&my_asm->labels, data[0], data[1], index);
    } else {
        push_back_function(&my_asm->functions, dup_line, index);
    }
}

int check_seps(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (is_delim(str[i], "\t \n") == 0)
            return (1);
    }
    return (-1);
}

void read_champion(char *filepath, asm_t *my_asm)
{
    FILE *fd = fopen(filepath, "r");
    char *line = NULL;
    size_t len = 0;
    int count = 0;

    if (fd == NULL)
        exit(84);
    while (getline(&line, &len, fd) != -1) {
        count++;
        if (line != NULL && check_seps(line) == 1 && line[0] != '#')
            add_to_linked_lists(my_asm, line, count);
    }
    fclose(fd);
    free(line);
    if (count == 0)
        exit(84);
}

void init_asm(asm_t *my_asm)
{
    my_memset(my_asm->header.prog_name, '\0', PROG_NAME_LENGTH);
    my_memset(my_asm->header.comment, '\0', COMMENT_LENGTH);
    my_asm->coding_byte = my_malloc(sizeof(char) * 10);
    my_asm->coding_byte[9] = '\0';
    my_asm->header.magic = COREWAR_EXEC_MAGIC;
    my_asm->functions = NULL;
    my_asm->labels = NULL;
    my_asm->comment_exists = 0;
    my_asm->name_exists = 0;
    my_asm->champ_size = 0;
}
