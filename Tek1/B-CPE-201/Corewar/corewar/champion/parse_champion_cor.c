/*
** EPITECH PROJECT, 2020
** Corewar/Corewar
** File description:
** main.c
*/

#include "../../include/corewar.h"

void init_champion(champion_t *champion, char *header)
{
    int header_size = COMMENT_LENGTH + PROG_NAME_LENGTH +
    sizeof(COREWAR_EXEC_MAGIC) + 8;

    get_champion_name(champion, header);
    get_champion_size(champion, header);
    get_champion_comment(champion, header, header_size);
}

void create_champion(corewar_t *core, char *filename, int address, int prog_nb)
{
    champion_t *champion = my_malloc(sizeof(champion_t));
    int header_size = COMMENT_LENGTH + PROG_NAME_LENGTH +
    sizeof(COREWAR_EXEC_MAGIC) + 8;
    char header[header_size];
    int fd = open(filename, O_RDONLY, 0);

    if (fd == -1)
        exit(84);
    if (read(fd, header, header_size) == 0)
        exit(84);
    init_champion(champion, header);
    read_champion_instructions(fd, champion);
    close(fd);
    champion->next_instruction = NULL;
    champion->prog_number = prog_nb;
    champion->address = address;
    core->champions[core->nb_champ] = champion;
    core->champions[core->nb_champ]->live_counter = my_malloc(sizeof(int) * 1);
    core->nb_champ += 1;
}