/*
** EPITECH PROJECT, 2020
** Corewar/Corewar
** File description:
** main.c
*/

#include "../../include/corewar.h"

void fill_arena_hex(char *hex, arena_t *arena)
{
    arena->hex[0] = hex[0];
    arena->hex[1] = hex[1];
}

void put_champions_in_arena(corewar_t *core, int *vm_pos)
{
    char *hexa = NULL;
    char *hex = "0123456789ABCDEF";
    int index = 1;

    for (int i = 0; i < core->nb_champ; i++) {
        for (int n = 0; n < core->champions[i]->size; n++) {
            index = vm_pos[i] + n;
            core->arena[index].c = core->champions[i]->instructions[n];
            core->arena[index].champ_id = core->champions[i]->prog_number;
            hexa = convert_base(core->arena[index].c, hex);
            fill_arena_hex(hexa, &core->arena[index]);
        }
        core->champions[i]->pc = vm_pos[i];
        core->champions[i]->next_pc = vm_pos[i];
        core->champions[i]->next_instruction = NULL;
        core->champions[i]->registers[1] = core->champions[i]->prog_number;
    }
    core->last_live.id = -1;
    core->last_live.name = "none";
}

int swap_champions(champion_t **champions, int i)
{
    champion_t *temp = NULL;

    if (champions[i]->prog_number > champions[i + 1]->prog_number) {
        temp = champions[i];
        champions[i] = champions[i + 1];
        champions[i + 1] = temp;
        return (-1);
    }
    return (0);
}

void sort_champions(corewar_t *core)
{
    for (int n = 0; n < core->nb_champ - 1; n++) {
        for (int i = 0; i < core->nb_champ - 1; i++) {
            swap_champions(core->champions, i);
        }
    }
}

void put_champions_in_vm(corewar_t *core)
{
    int *vm_pos = my_malloc(sizeof(int) * core->nb_champ);
    int index = 0;
    int c = 0;

    sort_champions(core);
    for (int i = 0; i < core->nb_champ; i++) {
        vm_pos[i] = core->champions[i]->address;
    }
    for (int i = 0; i < core->nb_champ; i++) {
        if (core->champions[i] == NULL)
            continue;
        c = MEM_SIZE / core->nb_champ * (i);
        if (vm_pos[index] == 0)
            vm_pos[index] = c;
        index++;
    }
    check_address_issues(core, vm_pos);
    core->vm_pos = vm_pos;
    put_champions_in_arena(core, vm_pos);
    core->max_champ = core->nb_champ;
}