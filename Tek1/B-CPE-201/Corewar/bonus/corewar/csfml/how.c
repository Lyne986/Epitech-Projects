/*
** EPITECH PROJECT, 2020
** Corewar/Corewar
** File description:
** main.c
*/

#include "../../include/corewar.h"

static void update(all_t *a)
{
    int i = 0;
    int j = 0;
    if (a->screen->seconds < \
    sfClock_getElapsedTime(a->screen->Clock).microseconds / 1000000) {
        a->screen->seconds += 0.01;
        i = rand() % 1920;
        j = rand() % 1080;
        if (i > 0 && i < 1920 && j > 0 && j < 1080) {
            a->screen->x = i;
            a->screen->y = j;
            create_line(a->screen);
        }
    }
}

static void event(all_t *a)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(a->win, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(a->win);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
            sfRenderWindow_close(a->win);
        if (click_text(a->howtxt[1], (sfVector2f) {100, 32},
        a->win))
            a->page = 0;
    }
}

static void display(all_t *a)
{
    sfRenderWindow_clear(a->win, sfBlack);
    sfTexture_updateFromPixels(a->screen->texture, \
    (sfUint8*) a->screen->pixel, 1920, 1080, 0, 0);
    sfRenderWindow_drawSprite(a->win, a->screen->sprite, NULL);
    for (int i = 0; i < 8; i++)
        sfRenderWindow_drawText(a->win, a->howtxt[i].text, NULL);
    sfRenderWindow_display(a->win);
}

void init_how(all_t *a)
{
    text_object_t champ_txt = {0, 0, {50, 10}, 15, sfWhite, 0};
    a->howtxt = my_malloc(sizeof(text_object_t) * (8));
    init_text_object(&champ_txt, "font.TTF", "How to play");
    a->howtxt[0] = champ_txt;
    init_text_object(&champ_txt, "font.TTF", "Quit");
    a->howtxt[1] = champ_txt;
    init_text_object(&champ_txt, "font.TTF", "Enter -> Start/Stop");
    a->howtxt[2] = champ_txt;
    init_text_object(&champ_txt, "font.TTF",
    "Left Arrow -> Goes backwark cycle by cycle");
    a->howtxt[3] = champ_txt;
    sfText_setCharacterSize(a->howtxt[0].text, 32);
    sfText_setPosition(a->howtxt[0].text, (sfVector2f) {850, 50});
    sfText_setCharacterSize(a->howtxt[1].text, 32);
    sfText_setPosition(a->howtxt[1].text, (sfVector2f) {925, 1000});
    sfText_setCharacterSize(a->howtxt[2].text, 32);
    sfText_setPosition(a->howtxt[2].text, (sfVector2f) {100, 300});
    sfText_setCharacterSize(a->howtxt[3].text, 32);
    sfText_setPosition(a->howtxt[3].text, (sfVector2f) {100, 700});
    init_how_two(a);
}

void update_how(all_t *a)
{
    update(a);
    event(a);
    display(a);
}