/*
** EPITECH PROJECT, 2020
** Corewar/Corewar
** File description:
** main.c
*/

#include "../../include/corewar.h"

int setup_background(screen_t *screen, all_t *a)
{
    sfText_setPosition(a->menetxt[3].text, (sfVector2f) {850, 550});
    screen->texture = sfTexture_create(1920, 1080);
    if (!screen->texture)
        return (84);
    screen->sprite = create_sprite();
    sfSprite_setTexture(screen->sprite, screen->texture, sfTrue);
    screen->pixel = my_malloc(sizeof(sfColor) * 1920 * 1080);
    if (!screen->pixel)
        return (84);
    screen->Clock = create_clock();
    screen->seconds = 0;
    screen->x = 0;
    screen->y = 0;
    screen->xx = 960;
    screen->yy = 540;
    return (0);
}

void create_line(screen_t *screen)
{
    sfVector2i v1;
    sfVector2i v2;

    v1.x = screen->x;
    v1.y = screen->y;
    v2.x = screen->xx;
    v2.y = screen->yy;
    my_putline(screen, v1, v2, get_random_color());
}