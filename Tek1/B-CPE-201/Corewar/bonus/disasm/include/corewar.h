/*
** EPITECH PROJECT, 2021
** B-CPE-201-MPL-2-1-corewar-bastien.boymond
** File description:
** corewar
*/

#ifndef COREWAR_H_
#define COREWAR_H_

#include "my.h"
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Window.h>
#include "csfml_garbage_collector.h"

typedef struct instruction_s
{
    int pc;
    int code;
    int type[4];
    int coding_byte;
    int args[3];
} instruction_t;

typedef struct champion_s
{
    int prog_number;
    int live_counter;
    int pc;
    int next_pc;
    char *instructions;
    int cooldown;
    int registers[REG_NUMBER + 1];
    int carry;
    char *name;
    char *comment;
    int size;
} champion_t;

typedef struct text_object_s {
    sfFont *font;
    sfText *text;
    sfVector2f pos;
    float size;
    sfColor color;
    int key;
} text_object_t;

typedef struct all_s
{
    sfClock *clock;
    sfFont *font;
    sfText *text;
    sfRenderWindow *win;
    text_object_t *champtxt;
    bool pause;
    bool next;
    bool skip;
} all_t;

typedef struct arena_s {
    char *hex;
    unsigned char c;
    int champ_id;
} arena_t;


// live ongoing livecount
// cycle ongoing cycle
// nbr cycles : cycles to die
typedef struct corewar_s
{
    int live;
    int max_champ;
    int nb_champ;
    char **heros;
    int *vm_pos;
    arena_t arena[MEM_SIZE];
    int cycle;
    int nbr_cycles;
    champion_t **champions;
    all_t all[1];
} corewar_t;

typedef struct array_s
{
    void (*ptr)(instruction_t *function, champion_t *champ, corewar_t *core);
} array_t;

// Utilities
void print_arg(int type, int arg, int fd);
char *convert_base(unsigned int nbr, char *base);
int base_to_dec(char *str, char *base);
int get_instruction_args(char *bin, int n);

// Get Champion infos
champion_t *create_champion(char *filename);
void push_back_champion(champion_t **champions, champion_t *champion);
void read_champion_instructions(int fd, champion_t *champion);
//void print_champion_instructions(instruction_t *functions);
void get_champion_size(champion_t *champion, char *header);
void get_champion_comment(champion_t *champion, char *header, int header_size);
void get_champion_name(champion_t *champion, char *header);
void get_champion_instructions(champion_t *champion, char *instructions);
// Print champion
void print_champion(champion_t *champion);

#endif /* !COREWAR_H_ */
