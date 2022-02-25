/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** get_instruction_info.c
*/

#include "../../include/corewar.h"

void find_args(corewar_t *core, instruction_t *function, int *i)
{
    op_t op;

    op = op_tab[function->code - 1];
    if (function->code != 1 && function->code != 9 &&
    function->code != 12 && function->code != 15) {
        add_args(function, core, i);
    } else {
        function->coding_byte = 0;
        if (op.nbr_cycles >= 20 && op.type[0] == T_DIR) {
            function->args[0] =
            get_number_from_n_bytes(core, T_IND, i);
        } else {
            function->args[0] =
            get_number_from_n_bytes(core, op.type[0], i);
        }
        function->type[0] = op.type[0];
    }
}

void draw_text(sfRenderWindow *win, sfText *text, sfVector2f pos, char *str)
{
    sfColor color = sfColor_fromRGBA(88, 85, 86, 255);

    if (str == NULL)
        return;
    sfText_setPosition(text, pos);
    sfText_setString(text, str);
    sfText_setColor(text, color);
    sfRenderWindow_drawText(win, text, NULL);
}

void print_instruction(all_t *a, instruction_t *function)
{
    char *str = NULL;
    op_t op;
    sfVector2f pos = {1300, 24};

    draw_text(a->win, a->champtxt[0].text, pos, "Instruction:");
    pos.x += 12 * 12;
    op = op_tab[function->code - 1];
    draw_text(a->win, a->champtxt[0].text, pos, op.mnemonique);
    pos.x += my_strlen(op.mnemonique) * 15;
    for (int i = 0; i < op.nbr_args; i++) {
        if (function->type[i] == T_REG)
            draw_text(a->win, a->champtxt[0].text, pos, "r");
        if (function->type[i] == T_DIR)
            draw_text(a->win, a->champtxt[0].text, pos, "\%");
        pos.x += 16;
        str = to_str(function->args[i]);
        draw_text(a->win, a->champtxt[0].text, pos, str);
        pos.x += (my_strlen(str) + 1) * 12;
    }
}

void get_instruction(all_t *a, int i)
{
    a->info->code = a->core->arena[i].c;
    a->info->pc = i;
    i++;
    if (a->info->code < 1 || a->info->code > 16) {
        a->info->code = 0;
        return;
    }
    find_args(a->core, a->info, &i);
}

void draw_instruction_info(all_t *a)
{
    sfVector2f pos = {1300, 24};
    sfVector2i mouse_pos = a->mouse_pos;

    if (a->mouse_pos.y < 64 || a->mouse_pos.x < 16 || a->mouse_pos.x > 1552) {
        a->show = false;
        a->info->code = 0;
        a->index = -1;
        return;
    }
    mouse_pos.x -= 16;
    mouse_pos.y -= 64;
    a->index = mouse_pos.x / 16 + (mouse_pos.y / 16) * 96;
    if (a->info->code == 0)
        get_instruction(a, a->index);
    if (a->info->code != 0)
        print_instruction(a, a->info);
    else
        draw_text(a->win, a->champtxt[0].text, pos, "Unknown instruction");
}