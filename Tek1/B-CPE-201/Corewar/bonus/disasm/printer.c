/*
** EPITECH PROJECT, 2021
** B-CPE-201-MPL-2-1-corewar-bastien.boymond
** File description:
** printer
*/

#include "./include/corewar.h"
#include "./include/op.h"

void print_header(champion_t *champion, int fd)
{
    if (champion->name)
        dprintf(fd , ".name\t\"%s\"\n", champion->name);
    if (champion->comment)
        dprintf(fd , ".comment\t\"%s\"\n", champion->comment);
    if (champion->name || champion->comment)
        write(fd, "\n", 1);
}

int get_number_from_n_bytes(char *instruction, args_type_t type, int *i, int f)
{
    char *hex = NULL;
    char *hexa = "0123456789ABCDEF";
    int n = 0;
    int base = 0;

    if (type == T_REG)
        n = 1;
    else if (type == T_IND)
        n = 2;
    else
        n = 4;
    for (int index = 0; index < n; index++) {
        hex = my_strcat(hex, convert_base(instruction[index], hexa));
    }
    (*i) += n;
    base = base_to_dec(hex, hexa);
    print_arg(type, base, f);
    return (base);
}

void add_args(instruction_t *function, char *instruction, int *i, int fd)
{
    char *bin = NULL;
    int arg_type = 0;
    op_t op;

    op = op_tab[function->code - 1];
    function->coding_byte = instruction[(*i)];
    bin = nbr_to_base(instruction[(*i)], "01");
    (*i) += 1;
    for (int n = 0; n < op.nbr_args; n++) {
        arg_type = get_instruction_args(bin, n);
        function->type[n] = arg_type;
        if (op.nbr_cycles >= 20 && arg_type == T_DIR)
            arg_type = T_IND;
        function->args[n] = get_number_from_n_bytes(\
        &instruction[(*i)], arg_type, i, fd);
    }
}

void print_instruction(int fd, int *i, instruction_t instruction, \
champion_t *champion)
{
    op_t op;

    op = op_tab[instruction.code - 1];
    dprintf(fd, "\t%s", op.mnemonique);
    if (instruction.code != 1 && instruction.code != 9 &&
    instruction.code != 12 && instruction.code != 15) {
        add_args(&instruction, champion->instructions, i, fd);
    } else {
        instruction.coding_byte = 0;
        if (op.nbr_cycles >= 20 && op.type[0] == T_DIR) {
            instruction.args[0] = \
            get_number_from_n_bytes(
            &champion->instructions[(*i)], T_IND, i, fd);
        } else {
            instruction.args[0] = get_number_from_n_bytes(\
            &champion->instructions[(*i)], op.type[0], i, fd);
        }
        instruction.type[0] = op.type[0];
    }
    write(fd, "\n", 1);
}

void print_champion(champion_t *champion)
{
    int fd = open(my_strcat(champion->name, ".s"), O_CREAT | O_WRONLY, 0666);
    instruction_t instruction;
    int i = 0;

    print_header(champion, fd);
    while (i < champion->size) {
        instruction.code = champion->instructions[i];
        i += 1;
        if (instruction.code < 1 || instruction.code > 16)
            continue;
        print_instruction(fd, &i, instruction, champion);
    }
    close(fd);
}