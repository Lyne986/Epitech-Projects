/*
** EPITECH PROJECT, 2021
** B-CPE-201-MPL-2-1-corewar-bastien.boymond
** File description:
** get_champion_infos
*/

#include "../include/corewar.h"

void get_champion_size(champion_t *champion, char *header)
{
    char *size = my_malloc(sizeof(char) * 4);
    char *hex_size = NULL;
    int nb = 0;
    __attribute__((unused)) int n = 0;

    for (size_t i = sizeof(COREWAR_EXEC_MAGIC) + PROG_NAME_LENGTH + 4, n = 0;
    i < sizeof(COREWAR_EXEC_MAGIC) + PROG_NAME_LENGTH + 8; i++) {
        size[n] = header[i];
        n++;
    }
    for (int i = 0; i < 4; i++) {
        nb = size[i];
        if (nb < 0)
            nb += 256;
        hex_size = my_strcat(hex_size, convert_base(nb, "0123456789ABCDEF"));
    }
    champion->size = base_to_dec(hex_size, "0123456789ABCDEF");
}

void get_champion_comment(champion_t *champion, char *header, int header_size)
{
    __attribute__((unused)) int n = 0;

    champion->comment = my_malloc(sizeof(char) * COMMENT_LENGTH);
    for (int i = PROG_NAME_LENGTH + sizeof(COREWAR_EXEC_MAGIC) + 8, n = 0;
    i < header_size; i++, n++) {
        champion->comment[n] = header[i];
    }
}

void get_champion_name(champion_t *champion, char *header)
{
    int n = 0;
    char *magic = "00ea83f3";
    int magicnb = 0;
    char *temp = NULL;

    champion->name = my_malloc(sizeof(char) * PROG_NAME_LENGTH);
    for (size_t i = sizeof(COREWAR_EXEC_MAGIC); i <
    PROG_NAME_LENGTH + sizeof(COREWAR_EXEC_MAGIC); i++) {
        champion->name[n] = header[i];
        n++;
    }
    for (int i = 0, n = 0; i < 4; i++) {
        magicnb = header[n];
        magicnb = magicnb < 0 ? magicnb + 256 : magicnb;
        temp = my_strcat(temp, convert_base(magicnb, "0123456789abcdef"));
        n++;
    }
    for (int i = 0; i < 4; i++)
        if (temp[i] != magic[i])
            exit(84);
}

void read_champion_instructions(int fd, champion_t *champion)
{
    int nb = 0;
    int header_size = COMMENT_LENGTH + PROG_NAME_LENGTH +
    sizeof(COREWAR_EXEC_MAGIC) + 12;
    int nb_read = 0;
    char *instructions = my_malloc(sizeof(char) * champion->size);

    lseek(fd, header_size, SEEK_SET);
    if ((nb_read = read(fd, instructions, champion->size)) > 0) {
        for (int i = 0; i < champion->size; i++) {
            nb = instructions[i];
            nb = nb < 0 ? nb + 256 : nb;
        }
    }
    champion->instructions = instructions;
}