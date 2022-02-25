/*
** EPITECH PROJECT, 2021
** B-CPE-201-MPL-2-1-corewar-bastien.boymond
** File description:
** final_scene
*/

#include "../../include/corewar.h"

int init_final_scene(all_t *a, champion_t *champion)
{
    int ret = 0;
    int size = my_strlen(a->core->last_live.name) * 40;
    sfColor color = sfColor_fromRGBA(88, 85, 86, 255);
    text_object_t champ_txt = {0, 0, {940 - size - 40, 540}, 40, color, 0};
    text_object_t winner = {0, 0, {((900 - 36) - 370), 240}, 80, color, 0};

    if (champion == NULL) {
        init_text_object(&champ_txt, "font.TTF",  a->core->last_live.name);
        a->champtxt[8] = champ_txt;
        set_color(a->core->last_live.id, a->champtxt[8].text);
        ret = my_strlen(a->core->last_live.name);
    } else {
        init_text_object(&champ_txt, "font.TTF",  champion->name);
        a->champtxt[8] = champ_txt;
        set_color(champion->prog_number, a->champtxt[8].text);
        ret = my_strlen(champion->name);
    }
    init_text_object(&winner, "font.TTF",  "And The WINNER IS:");
    a->champtxt[9] = winner;
    return (ret);
}

void final_events(all_t *a)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(a->win, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(a->win);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
            sfRenderWindow_close(a->win);
    }
}

void loop_final_scene(all_t *a, int len)
{
    sfClock *txt_size = create_clock();
    sfClock *timer = create_clock();
    int size = 40;

    while (sfRenderWindow_isOpen(a->win)) {
        final_events(a);
        sfRenderWindow_clear(a->win, sfBlack);
        sfRenderWindow_drawText(a->win, a->champtxt[8].text, NULL);
        sfRenderWindow_drawText(a->win, a->champtxt[9].text, NULL);
        sfRenderWindow_display(a->win);
        if (get_seconds(timer) > 5)
            sfRenderWindow_close(a->win);
        if (get_seconds(txt_size) > 0.1) {
            sfText_setCharacterSize(a->champtxt[8].text, size);
            sfText_setPosition(a->champtxt[8].text, (sfVector2f)
            {(940 - len) - size, 540 - size});
            size++;
            sfClock_restart(txt_size);
        }
    }
}

void final_scene(all_t *a, champion_t *champion)
{
    int size = 0;

    sfMusic *winner = create_music("winner.ogg");
    sfMusic_setVolume(winner, 20);
    sfMusic_play(winner);
    size = init_final_scene(a, champion);
    sfText_setOrigin(a->champtxt[8].text, (sfVector2f){20, 20});
    loop_final_scene(a, size);
    sfMusic_stop(winner);
    exit(0);
}