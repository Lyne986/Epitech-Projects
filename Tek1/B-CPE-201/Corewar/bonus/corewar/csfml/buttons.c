/*
** EPITECH PROJECT, 2021
** B-CPE-201-MPL-2-1-corewar-bastien.boymond
** File description:
** buttons
*/

#include "../../include/corewar.h"

void init_menu_object(menu_object_t *object, char *filepath)
{
    sfVector2u width_height = {0, 0};

    object->texture = create_texture(filepath, NULL);
    object->s = create_sprite();
    sfSprite_setTexture(object->s, object->texture, sfTrue);
    object->width = width_height.x;
    object->height = width_height.y;
    object->rect.left = (object->rect.left == 0) ? 0 : object->rect.left;
    object->rect.top = (object->rect.top == 0) ? 0 : object->rect.top;
    sfSprite_setTextureRect(object->s, object->rect);
    sfSprite_setScale(object->s, object->scale);
    sfSprite_setPosition(object->s, object->pos);
}

int do_event(all_t *a, menu_object_t button)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(a->win);
    sfFloatRect btn = sfSprite_getGlobalBounds(button.s);

    if (sfFloatRect_contains(&btn, pos.x, pos.y) && \
    sfMouse_isButtonPressed(sfMouseLeft))
        return (1);
    return (0);
}

void buttons_events(all_t *a, menu_object_t *buttons)
{
    if (do_event(a, buttons[0])) {
        a->saving = !a->saving;
        if (a->saving == true) {
            a->min_save = a->core->total_cycles;
        }
    }
    if (do_event(a, buttons[1]) && a->saving == 1) {
        load_history(a);
    }
    if (do_event(a, buttons[2])) {
        a->pause = !a->pause;
    }
    if (do_event(a, buttons[3])) {
        a->next = !a->next;
    }
}

void draw_buttons(all_t *a)
{
    sfRenderWindow_drawSprite(a->win, a->buttons[4].s, NULL);
    sfSprite_setTextureRect(a->buttons[0].s, (sfIntRect){0, 50, 50, 50});
    if (a->saving == 1)
        sfSprite_setTextureRect(a->buttons[0].s, (sfIntRect){0, 0, 50, 50});
    sfRenderWindow_drawSprite(a->win, a->buttons[0].s, NULL);
    if (a->saving == 1)
        sfRenderWindow_drawSprite(a->win, a->buttons[1].s, NULL);
    sfSprite_setTextureRect(a->buttons[2].s, (sfIntRect){50, 50, 50, 50});
    if (a->pause == 1)
        sfSprite_setTextureRect(a->buttons[2].s, (sfIntRect){50, 0, 50, 50});
    sfRenderWindow_drawSprite(a->win, a->buttons[2].s, NULL);
    sfRenderWindow_drawSprite(a->win, a->buttons[3].s, NULL);
}

void init_buttons(menu_object_t *buttons)
{
    menu_object_t save = {50, 50, (sfVector2f){1, 1}, \
    (sfVector2f){15, 5}, 0, 0, (sfIntRect){0, 50, 50, 50}};
    menu_object_t back = {50, 50, (sfVector2f){1, 1}, \
    (sfVector2f){65, 5}, 0, 0, (sfIntRect){100, 0, 50, 50}};
    menu_object_t pause = {50, 50, (sfVector2f){1, 1}, \
    (sfVector2f){115, 5}, 0, 0, (sfIntRect){50, 50, 50, 50}};
    menu_object_t next = {50, 50, (sfVector2f){1, 1}, \
    (sfVector2f){165, 5}, 0, 0, (sfIntRect){100, 50, 50, 50}};

    init_menu_object(&save, "ui.png");
    buttons[0] = save;
    init_menu_object(&back, "ui.png");
    buttons[1] = back;
    init_menu_object(&pause, "ui.png");
    buttons[2] = pause;
    init_menu_object(&next, "ui.png");
    buttons[3] = next;
    init_corewar_background(buttons);
}