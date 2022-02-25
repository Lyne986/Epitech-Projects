/*
** EPITECH PROJECT, 2020
** Untitled (Workspace)
** File description:
** init_csfml.c
*/

#include "../../include/corewar.h"

sfRenderWindow *create_window(sfUint32 style)
{
    sfRenderWindow *window;
    const sfVideoMode *mode = sfVideoMode_getFullscreenModes(0);
    char *name = "COREWAR";

    window = sfRenderWindow_create(*mode, name, style, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    return (window);
}

sfText *init_text(sfColor color, sfFont *font, int size)
{
    sfText *text = create_text();

    sfText_setFillColor(text, color);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, size);
    return (text);
}

void init_text_object(text_object_t *t, char *f, char *string)
{
    t->font = create_font(f);
    t->text = create_text();
    sfText_setFont(t->text, t->font);
    sfText_setColor(t->text, t->color);
    sfText_setPosition(t->text, t->pos);
    sfText_setCharacterSize(t->text, t->size);
    sfText_setString(t->text, string);
}

void init_champion_text(all_t *a)
{
    sfColor color = sfColor_fromRGBA(88, 85, 86, 255);
    text_object_t champ_txt = {0, 0, {50, 10}, 12, color, 0};

    a->champtxt = my_malloc(sizeof(text_object_t) * (10));
    init_text_object(&champ_txt, "font.TTF", "Champion Name: ");
    a->champtxt[0] = champ_txt;
    init_text_object(&champ_txt, "font.TTF", "Comment: ");
    a->champtxt[1] = champ_txt;
    init_text_object(&champ_txt, "font.TTF", "Live: ");
    a->champtxt[2] = champ_txt;
    init_text_object(&champ_txt, "font.TTF", "On going cycle: ");
    a->champtxt[3] = champ_txt;
    init_text_object(&champ_txt, "font.TTF", "Registers: ");
    a->champtxt[4] = champ_txt;
    init_text_object(&champ_txt, "font.TTF", ":");
    a->champtxt[5] = champ_txt;
    init_text_object(&champ_txt, "font.TTF", ":");
    a->champtxt[6] = champ_txt;
    init_text_object(&champ_txt, "font.TTF", "live:");
    a->champtxt[7] = champ_txt;
}

void init_csfml(all_t *a)
{
    a->index = -1;
    a->str = my_malloc(sizeof(char) * 100);
    a->win = create_window(sfFullscreen);
    a->font = create_font("font.TTF");
    a->text = init_text(sfWhite, a->font, 8);
    a->clock = create_clock();
    a->pause = true;
    a->saving = false;
    a->next = false;
    a->show = false;
    a->speedup = false;
    a->min_save = 0;
    a->page = 0;
    init_menu(a, (sfColor){115, 117, 115, 255});
    init_how(a);
    a->buttons = my_malloc(sizeof(menu_object_t) * 5);
    init_buttons(a->buttons);
    init_champion_text(a);
    a->info = my_malloc(sizeof(instruction_t));
}