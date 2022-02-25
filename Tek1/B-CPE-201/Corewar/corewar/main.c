/*
** EPITECH PROJECT, 2020
** Corewar/Corewar
** File description:
** main.c
*/

#include "../include/corewar.h"

char *my_putnbr_base_dump(unsigned int nbr, char *base);

void print_line_number(int i)
{
    char *hex = my_putnbr_base_dump(i, "0123456789ABCDEF");

    if (i != 0)
        my_printf("\n");
    my_printf("%s", hex);
    for (int j = 0; j < 5 - my_strlen(hex); j++) {
        my_printf(" ");
    }
    my_printf(": ");
}

void print_shell_arena(corewar_t *core)
{
    for (int i = 0; i < MEM_SIZE; i++) {
        if ((i) % 32 == 0 && i != 1) {
            print_line_number(i);
        }
        my_printf("%s ", core->arena[i].hex);
    }
    if (core->last_live.id != -1)
        my_printf("\nLe joueur %d (%s) a gagné.\n", core->last_live.id,
        core->last_live.name);
    exit(0);
}

void update_loop(all_t *a)
{
    while (1) {
        update_arena(a->core, a);
        if (a->core->dump_cycles != -1 &&
        a->core->dump_cycles < a->core->total_cycles)
            print_shell_arena(a->core);
    }
}

int main(int ac, char **av)
{
    all_t *a = my_malloc(sizeof(all_t));

    a->core = my_malloc(sizeof(corewar_t));
    init_core(a->core);
    error_handler(a->core, av, ac);
    put_champions_in_vm(a->core);
    update_loop(a);
    return (0);
}