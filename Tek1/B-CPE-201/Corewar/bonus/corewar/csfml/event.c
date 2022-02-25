/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** event
*/

#include "../../include/corewar.h"

void skip_cooldown(all_t *a)
{
    for (int i = 0; i < a->core->nb_champ; i++)
        if (a->core->champions[i])
            a->core->champions[i]->cooldown = 0;
}

void get_history_events(all_t *a, sfEvent event)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyRight) {
        save_to_history(a);
        a->next = !a->next;
    }
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyLeft)
        load_history(a);
}

void other_corewar_events(all_t *a, sfEvent event)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEnter)
        a->pause = !a->pause;
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeySpace) {
        a->next = !a->next;
        skip_cooldown(a);
    }
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyA)
        a->speedup = !a->speedup;
}

void get_corewar_events(all_t *a)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(a->win, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(a->win);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
            sfRenderWindow_close(a->win);
        other_corewar_events(a, event);
        if (event.type == 10 && event.mouseButton.button == sfMouseLeft) {
            a->show = true;
            a->info->code = 0;
            a->mouse_pos = sfMouse_getPositionRenderWindow(a->win);
        }
        get_history_events(a, event);
        buttons_events(a, a->buttons);
    }
}