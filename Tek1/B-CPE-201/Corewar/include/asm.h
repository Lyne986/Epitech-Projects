/*
** EPITECH PROJECT, 2020
** Corewar
** File description:
** asm.h
*/

#include "my.h"

typedef union bit_fields_s bit_fields_t;

union bit_fields_s
{
    int value;

    struct
    {
        uint16_t bit1;
        uint16_t bit2;
    } byte;
};

typedef struct label_s {
    char *label;
    char *command;
    int line;
    struct label_s *next;
} label_t;

typedef struct function_s {
    char *command;
    int coding_byte;
    int size;
    int code;
    int line;
    struct function_s *next;
} function_t;

typedef struct asm_s {
    int comment_exists;
    int name_exists;
    char *coding_byte;
    int nb_args;
    int champ_size;
    header_t header;
    label_t *labels;
    function_t *functions;
} asm_t;

// Linked lists
int label_chars(char *name);
void add_to_linked_lists(asm_t *my_asm, char *line, int index);
int is_containing(char *str, char c);
void push_back_label(label_t **labels, char *name, char *command, int line);
void push_back_function(function_t **labels, char *command, int line);

void parse_champion(asm_t *my_asm);
void get_asm_info(asm_t *my_asm);
void print_champion_info(asm_t *my_asm);

//error handling
void error_handling_info(asm_t *my_asm);

//print in file
void print_champion(asm_t *my_asm);
void print_indirect(asm_t *my_asm, char *number, function_t *function);
int search_label_distance(asm_t *my_asm, char *label, function_t *function);

//init asm
void init_asm(asm_t *my_asm);

//read file
void read_champion(char *filepath, asm_t *my_asm);

//error handling
int search_for_label(asm_t *my_asm, char *str);

// update file
void update_register(asm_t *my_asm, char *registre);
void update_direct(asm_t *my_asm, char *label, const op_t *op);
void update_indirect(asm_t *my_asm, char *number);

// Utilities
char **split_string(char *command, char *c);
void print_array(char *str, char **array);
int biteshifting(int x);
int binary_to_dec(char *binary);
int my_strlen_array(char **array);
void print_array(char *str, char **array);
int is_number(char *str);
char *array_to_str(char **array);
char *after_arg(char *str);
char *from_arg(char *str);
char *to_arg(char *str, char *delim);