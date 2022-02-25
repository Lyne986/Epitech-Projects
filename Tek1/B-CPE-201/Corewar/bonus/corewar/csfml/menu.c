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
        if (click_text(a->menetxt[1], (sfVector2f) {100, 35},
        a->win))
            a->page = 1;
        if (click_text(a->menetxt[2], (sfVector2f) {120, 35},
        a->win))
            sfRenderWindow_close(a->win);
        if (click_text(a->menetxt[3], (sfVector2f) {250, 35},
        a->win))
            a->page = 2;
    }
}

static void display(all_t *a)
{
    sfRenderWindow_clear(a->win, sfBlack);
    sfTexture_updateFromPixels(a->screen->texture,
    (sfUint8*) a->screen->pixel, 1920, 1080, 0, 0);
    sfRenderWindow_drawSprite(a->win, a->screen->sprite, NULL);
    sfRenderWindow_drawRectangleShape(a->win, a->shadow, NULL);
    sfRenderWindow_drawText(a->win, a->menetxt[0].text, NULL);
    sfRenderWindow_drawText(a->win, a->menetxt[1].text, NULL);
    sfRenderWindow_drawText(a->win, a->menetxt[2].text, NULL);
    sfRenderWindow_drawText(a->win, a->menetxt[3].text, NULL);
    sfRenderWindow_display(a->win);
}

void init_menu(all_t *a, sfColor color)
{
    text_object_t champ_txt = {0, 0, {50, 10}, 15, color, 0};

    a->screen = my_malloc(sizeof(screen_t));
    a->menetxt = my_malloc(sizeof(text_object_t) * (4));
    init_text_object(&champ_txt, "font.TTF", "Corewar");
    a->menetxt[0] = champ_txt;
    init_text_object(&champ_txt, "font.TTF", "Play");
    a->menetxt[1] = champ_txt;
    init_text_object(&champ_txt, "font.TTF", "Quit");
    a->menetxt[2] = champ_txt;
    init_text_object(&champ_txt, "font.TTF", "How to play");
    a->menetxt[3] = champ_txt;
    sfText_setCharacterSize(a->menetxt[0].text, 32);
    sfText_setPosition(a->menetxt[0].text, (sfVector2f) {880, 100});
    sfText_setCharacterSize(a->menetxt[1].text, 32);
    sfText_setPosition(a->menetxt[1].text, (sfVector2f) {925, 350});
    sfText_setCharacterSize(a->menetxt[2].text, 32);
    sfText_setPosition(a->menetxt[2].text, (sfVector2f) {925, 750});
    sfText_setCharacterSize(a->menetxt[3].text, 32);
    init_shadow_menu(a);
}

void update_menu(all_t *a)
{
    update(a);
    event(a);
    display(a);
}