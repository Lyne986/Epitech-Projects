/*
** EPITECH PROJECT, 2021
** B-CPE-201-MPL-2-1-corewar-bastien.boymond
** File description:
** second_init
*/

#include "../../include/corewar.h"

void init_corewar_background(menu_object_t *buttons)
{
    menu_object_t background = {0, 0, (sfVector2f){1, 1}, \
    (sfVector2f){-165, 30}, 0, 0, (sfIntRect){0, 0, 1920, 1080}};

    init_menu_object(&background, "corewar_logo.png");
    buttons[4] = background;
}

void init_shadow_menu(all_t *a)
{
    setup_background(a->screen, a);
    a->shadow = create_rectangle();
    sfRectangleShape_setSize(a->shadow, (sfVector2f){10000, 10000});
    sfRectangleShape_setFillColor(a->shadow, (sfColor){0, 0, 0, 100});
}