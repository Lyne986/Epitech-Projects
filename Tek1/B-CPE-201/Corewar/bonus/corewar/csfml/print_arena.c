/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** print_arena.c
*/

#include "../../include/corewar.h"

void set_color(int champ_id, sfText *text)
{
    sfColor color = sfColor_fromRGBA(156, 158, 157, 180);

    if (champ_id == 1)
        color = sfColor_fromRGBA(36, 89, 135, 255);
    if (champ_id == 2)
        color = sfColor_fromRGBA(112, 0, 58, 255);
    if (champ_id == 3)
        color = sfColor_fromRGBA(0, 147, 11, 255);
    if (champ_id == 4)
        color = sfColor_fromRGBA(216, 133, 13, 255);
    sfText_setColor(text, color);
}

void set_cursor_color(int champ_id, sfText *text)
{
    sfColor color =  sfColor_fromRGBA(156, 158, 157, 255);

    if (champ_id == 1)
        color = sfColor_fromRGBA(28, 139, 235, 255);
    if (champ_id == 2)
        color = sfColor_fromRGBA(191, 2, 100, 255);
    if (champ_id == 3)
        color = sfColor_fromRGBA(0, 255, 0, 255);
    if (champ_id == 4)
        color = sfColor_fromRGBA(242, 208, 73, 255);
    sfText_setColor(text, color);
}

void set_cursor(all_t *a, corewar_t *core, int index, sfText *text)
{
    for (int i = 0; i < core->nb_champ; i++) {
        if (core->champions[i] && core->champions[i]->pc == index)
            set_cursor_color(core->champions[i]->prog_number, text);
    }
    if (index == a->index)
        sfText_setColor(text, sfColor_fromRGBA(255, 0, 0 , 255));
}

void draw_champions_info(corewar_t *core, all_t *a)
{
    if (a->speedup == true)
        return;
    draw_buttons(a);
    for (int i = 0; i < core->max_champ; i++) {
        if (core->champions[i])
            fill_champ_texts(core, core->champions[i], a, i);
    }
}

void draw_arena(corewar_t *core, all_t *a)
{
    sfVector2f pos = {16, 64};

    sfRenderWindow_clear(a->win, sfBlack);
    draw_champions_info(core, a);
    for (int i = 0; i < MEM_SIZE; i++) {
        sfText_setPosition(a->text, pos);
        set_color(core->arena[i].champ_id, a->text);
        set_cursor(a, core, i, a->text);
        sfText_setString(a->text, core->arena[i].hex);
        pos.x += 16;
        if ((i + 1) % 96 == 0 && i != 0) {
            pos.x = 16;
            pos.y += 16;
        }
        sfRenderWindow_drawText(a->win, a->text, NULL);
    }
    if (a->show)
        draw_instruction_info(a);
    sfRenderWindow_display(a->win);
    sfClock_restart(a->clock);
}