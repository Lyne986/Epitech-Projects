/*
** EPITECH PROJECT, 2020
** my_screensaver.c
** File description:
** create_window.c
*/

#include "../../include/corewar.h"

void my_putpixel(screen_t *screen, sfVector2i v1, sfColor color)
{
    screen->pixel[v1.y * 1920 + v1.x] = color;
}

void my_putline(screen_t *screen, sfVector2i v1, sfVector2i v2, sfColor col)
{
    int j = 0;
    float a = (float)(v2.y - v1.y) / (float)(v2.x - v1.x);
    float b = (float)v1.y - a * (float)v1.x;

    if (v1.x > v2.x) {
        for (int i = v1.x; i > v2.x; i -= 1) {
            j = a * i + b;
            my_putpixel(screen, (sfVector2i){i, j}, col);
        }
    } else {
        for (int i = v1.x; i < v2.x; i += 1) {
            j = a * i + b;
            my_putpixel(screen, (sfVector2i){i, j}, col);
        }
    }
}

sfColor get_random_color(void)
{
    int r = rand() % 255 + 0;
    int g = rand() % 255 + 0;
    int b = rand() % 255 + 0;
    sfColor color = {r, g, b, 255};

    return (color);
}

void init_how_two(all_t *a)
{
    text_object_t champ_txt = {0, 0, {50, 10}, 15, sfWhite, 0};

    init_text_object(&champ_txt, "font.TTF", "Right Arrow ->\
    Cycles step by step");
    a->howtxt[4] = champ_txt;
    init_text_object(&champ_txt, "font.TTF", "Space -> Skip cooldown");
    a->howtxt[5] = champ_txt;
    init_text_object(&champ_txt, "font.TTF", "S -> Enable save");
    a->howtxt[6] = champ_txt;
    init_text_object(&champ_txt, "font.TTF",
    "A -> Disable txts to speedup proccesses");
    a->howtxt[7] = champ_txt;
    sfText_setCharacterSize(a->howtxt[4].text, 32);
    sfText_setPosition(a->howtxt[4].text, (sfVector2f) {100, 800});
    sfText_setCharacterSize(a->howtxt[5].text, 32);
    sfText_setPosition(a->howtxt[5].text, (sfVector2f) {100, 400});
    sfText_setCharacterSize(a->howtxt[6].text, 32);
    sfText_setPosition(a->howtxt[6].text, (sfVector2f) {100, 600});
    sfText_setCharacterSize(a->howtxt[7].text, 32);
    sfText_setPosition(a->howtxt[7].text, (sfVector2f) {100, 500});
}

sfBool click_text(text_object_t text, sfVector2f dim, sfRenderWindow *win)
{
    sfVector2i mp = sfMouse_getPositionRenderWindow(win);
    sfVector2f tp = sfText_getPosition(text.text);

    if (mp.x >= tp.x && mp.x <= tp.x + dim.x && mp.y >= tp.y &&
    mp.y <= tp.y + dim.y) {
        sfText_setCharacterSize(text.text, 38);
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            return (sfTrue);
        }
    } else {
        sfText_setCharacterSize(text.text, 32);
    }
    return (sfFalse);
}