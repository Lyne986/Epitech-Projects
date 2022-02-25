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

typedef struct instruction_s
{
    int pc;
    int code;
    int type[4];
    int coding_byte;
    int args[4];
} instruction_t;

typedef struct champion_s
{
    int prog_number;
    int address;
    int *live_counter;
    int pc;
    int next_pc;
    instruction_t *next_instruction;
    char *instructions;
    int cooldown;
    int registers[REG_NUMBER + 1];
    int carry;
    char *name;
    char *comment;
    int size;
} champion_t;

typedef struct arena_s {
    char hex[3];
    unsigned char c;
    int champ_id;
} arena_t;

typedef struct winner_s {
    int id;
    char *name;
} winner_t;

typedef struct corewar_s corewar_t;

typedef struct corewar_s
{
    char *hex;
    winner_t last_live;
    int live;
    int max_champ;
    int nb_champ;
    int total_cycles;
    int dump_cycles;
    int *vm_pos;
    int *address_pos;
    int *prog_number;
    arena_t arena[MEM_SIZE];
    int cycle;
    int nbr_cycles;
    champion_t **champions;
} corewar_t;

typedef struct all_s
{
    corewar_t *core;
} all_t;

typedef struct array_s
{
    void (*ptr)(instruction_t *function, champion_t *champ, corewar_t *core);
} array_t;

void execute_instruction(corewar_t *core, champion_t *champion);

void exec_live(instruction_t *function, champion_t *champion, corewar_t *core);

void exec_ld(instruction_t *function, champion_t *champion, corewar_t *core);
void exec_st(instruction_t *function, champion_t *champion, corewar_t *core);

void exec_add(instruction_t *function, champion_t *champion, corewar_t *core);
void exec_sub(instruction_t *function, champion_t *champion, corewar_t *core);
void exec_or(instruction_t *function, champion_t *champion, corewar_t *core);

void exec_and(instruction_t *function, champion_t *champion, corewar_t *core);
void exec_aff(instruction_t *function, champion_t *champion, corewar_t *core);

void exec_xor(instruction_t *function, champion_t *champion, corewar_t *core);

void exec_zjmp(instruction_t *function, champion_t *champion, corewar_t *core);

void exec_ldi(instruction_t *function, champion_t *champion, corewar_t *core);
void exec_sti(instruction_t *function, champion_t *champion, corewar_t *core);

void exec_fork(instruction_t *function, champion_t *champion, corewar_t *core);
void exec_lfork(instruction_t *function, champion_t *champ, corewar_t *core);

void exec_lld(instruction_t *function, champion_t *champion, corewar_t *core);
void exec_lldi(instruction_t *function, champion_t *champion, corewar_t *core);

int check_instruction_errors(instruction_t *instruction);
int get_value(corewar_t *core, champion_t *champ, instruction_t *func, int *i);
int get_number_from_n_bytes(corewar_t *core, int type, int *i);
int get_instruction_args(char *bin, int n);
void add_args(corewar_t *core, instruction_t *function, int *i);

static const array_t func[] = {
        {exec_live},
        {exec_ld},
        {exec_st},
        {exec_add},
        {exec_sub},
        {exec_and},
        {exec_or},
        {exec_xor},
        {exec_zjmp},
        {exec_ldi},
        {exec_sti},
        {exec_fork},
        {exec_lld},
        {exec_lldi},
        {exec_lfork},
        {exec_aff}
};

//error handling
void prog_number_errors(corewar_t *core, char **av, int *i, int *n);
void champ_after_load_adress(char **av, int *i, int *a);
void champion_file(corewar_t *core, char *filepath, int *a, int *n);
int get_unused_prognb(corewar_t *core);
void compare_each_champ(corewar_t *core, int *vm_pos, int i);
void check_address_issues(corewar_t *core, int *vm_pos);

void verify_champ_files(corewar_t *core, char **av, int ac);
void create_champion(corewar_t *core, char *filename, int address, int prog_nb);
void update_arena(corewar_t *core, all_t *a);
champion_t *get_champion_from_id(corewar_t *core, int i);
void fill_arena_hex(char *hex, arena_t *arena);
void error_handler(corewar_t *core, char **av, int ac);
void put_champions_in_vm(corewar_t *core);

//Init function
void init_core(corewar_t *core);
void init_instructions(instruction_t *instruction);
char *read_file(char *filepath);

// Utilities
char *convert_base(unsigned int nbr, char *base);
int base_to_dec(char *str, char *base);

// Get Champion infos
void push_back_champion(champion_t **champions, champion_t *champion);
void read_champion_instructions(int fd, champion_t *champion);
//void print_champion_instructions(instruction_t *functions);
void get_champion_size(champion_t *champion, char *header);
void get_champion_comment(champion_t *champion, char *header, int header_size);
void get_champion_name(champion_t *champion, char *header);
void get_champion_instructions(champion_t *champion, char *instructions);
#endif /* !COREWAR_H_ */
