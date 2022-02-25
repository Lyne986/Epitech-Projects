/*
** EPITECH PROJECT, 2020
** B-CPE-201-MPL-2-1-corewar-bastien.boymond
** File description:
** parse_instruction.c
*/

#include "../../include/corewar.h"

int get_number_from_n_bytes(corewar_t *core, int type, int *i)
{
    int n = 0;

    if (type == T_REG)
        n = 1;
    else if (type == T_IND)
        n = 2;
    else
        n = 4;
    core->hex[n * 2] = 0;
    for (int index = 0; index < n; index++) {
        my_strcat_from(core->hex, core->arena[*i + index].hex, index * 2);
    }
    (*i) += n;
    return (base_to_dec(core->hex, "0123456789ABCDEF"));
}

int get_instruction_args(char *bin, int n)
{
    int arg_type = 0;
    char type[3];

    type[2] = 0;
    type[0] = bin[n * 2];
    type[1] = bin[n * 2 + 1];
    if (my_strcmp(type, "01") == 0)
        arg_type = T_REG;
    if (my_strcmp(type, "10") == 0)
        arg_type = T_DIR;
    if (my_strcmp(type, "11") == 0)
        arg_type = T_IND;
    return (arg_type);
}

void add_args(corewar_t *core, instruction_t *function, int *i)
{
    char *bin = NULL;
    int arg_type = T_REG;
    op_t op;

    op = op_tab[function->code - 1];
    function->coding_byte = core->arena[*i].c;
    bin = nbr_to_base(core->arena[*i].c, "01");
    (*i) += 1;
    for (int n = 0; n < op.nbr_args; n++) {
        arg_type = get_instruction_args(bin, n);
        function->type[n] = arg_type;
        if (op.nbr_cycles >= 20 && arg_type == T_DIR)
            arg_type = T_IND;
        function->args[n] =
        get_number_from_n_bytes(core, arg_type, i);
    }
}

void execute_args(corewar_t *core, champion_t *champ, instruction_t *function)
{
    op_t op;

    op = op_tab[function->code - 1];
    if (function->code != 1 && function->code != 9 &&
    function->code != 12 && function->code != 15) {
        add_args(core, function, &champ->next_pc);
    } else {
        function->coding_byte = 0;
        if (op.nbr_cycles >= 20 && op.type[0] == T_DIR) {
            function->args[0] =
            get_number_from_n_bytes(core, T_IND, &champ->next_pc);
        } else {
            function->args[0] =
            get_number_from_n_bytes(core, op.type[0], &champ->next_pc);
        }
        function->type[0] = op.type[0];
    }
}

void execute_instruction(corewar_t *core, champion_t *champion)
{
    instruction_t *next = champion->next_instruction;
    instruction_t *instruction = my_malloc(sizeof(instruction_t));
    op_t op;

    init_instructions(instruction);
    if (next != NULL)
        func[next->code - 1].ptr(next, champion, core);
    champion->pc = champion->next_pc % MEM_SIZE;
    champion->next_pc = champion->pc;
    instruction->code = core->arena[champion->pc].c;
    instruction->pc = champion->pc;
    champion->next_pc += 1;
    if (instruction->code < 1 || instruction->code > 16) {
        champion->next_instruction = NULL;
        return;
    }
    op = op_tab[instruction->code - 1];
    execute_args(core, champion, instruction);
    champion->cooldown = op.nbr_cycles;
    champion->next_instruction = instruction;
}