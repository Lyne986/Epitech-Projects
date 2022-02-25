/*
** EPITECH PROJECT, 2021
** B-CPE-201-MPL-2-1-corewar-bastien.boymond
** File description:
** init_core
*/

#include "../include/corewar.h"

char *read_file(char *filepath)
{
    struct stat size;
    int fd = open(filepath, O_RDONLY);
    char *buff = NULL;

    if (fd < 0 || stat(filepath, &size) == -1)
        return (NULL);
    buff = my_malloc(sizeof(char) * (size.st_size + 1));
    if (buff == NULL)
        return (NULL);
    if ((fd = read(fd, buff, size.st_size)) < 0) {
        return (NULL);
    }
    buff[size.st_size] = 0;
    return (buff);
}

void init_instructions(instruction_t *instruction)
{
    instruction->code = 0;
    instruction->coding_byte = 0;
    instruction->pc = 0;
    for (int i = 0; i < 4; i++) {
        instruction->type[i] = '\0';
        instruction->args[i] = '\0';
    }
}

void init_core(corewar_t *core)
{
    core->hex = my_malloc(sizeof(char) * 9);
    core->nb_champ = 0;
    core->dump_cycles = -1;
    core->nbr_cycles = CYCLE_TO_DIE;
    core->champions = my_malloc(sizeof(champion_t *) * 4);
    for (int i = 0; i < 4; i++)
        core->champions[i] = NULL;
    core->prog_number = my_malloc(sizeof(int) * 11);
    core->cycle = 0;
    core->total_cycles = 0;
    core->live = 0;
    for (int i = 0; i < 4; i++)
        core->champions[i] = NULL;
    for (int i = 0; i < MEM_SIZE; i++) {
        core->arena[i].champ_id = 0;
        core->arena[i].c = 0;
        fill_arena_hex("00", &core->arena[i]);
        core->arena[i].hex[2] = 0;
    }
}