/*
** EPITECH PROJECT, 2021
** B-CPE-201-MPL-2-1-corewar-bastien.boymond
** File description:
** fill_champ_text
*/

#include "../../include/corewar.h"

char *get_register_string(all_t *a, champion_t *champion)
{
    char *reg = NULL;
    int index = 0;

    for (size_t i = 1; i <= REG_NUMBER; i++) {
        reg = to_str(champion->registers[i]);
        my_strcat_from(a->str, reg, index);
        index += my_strlen(reg);
        if (i == 8) {
            a->str[index] = '\n';
            a->str[index + 1] = '\n';
            index++;
        } else
            a->str[index] = ' ';
        index++;
    }
    a->str[index] = 0;
    return (a->str);
}

void edit_cycles_texts(corewar_t *core, all_t *a)
{
    sfText_setPosition(a->champtxt[3].text, (sfVector2f){620, 20});
    sfText_setString(a->champtxt[3].text,
    my_strcat("CYCLE:  ", my_itoa(core->cycle)));
    sfText_setPosition(a->champtxt[5].text, (sfVector2f){900, 20});
    sfText_setPosition(a->champtxt[6].text, (sfVector2f){1050, 20});
    sfText_setString(a->champtxt[5].text,
    my_strcat("/  ", my_itoa(core->nbr_cycles)));
    sfText_setString(a->champtxt[6].text,
    my_strcat("/  LIVE:   ", my_itoa(core->live)));
    sfText_setCharacterSize(a->champtxt[3].text, 30);
    sfText_setCharacterSize(a->champtxt[5].text, 30);
    sfText_setCharacterSize(a->champtxt[6].text, 30);
}

void edit_champion_texts(champion_t *champion, all_t *a)
{
    static bool once = false;
    char *name = NULL;
    char *prog = NULL;

    if (once == false) {
        name =  my_strcat("Name: ", champion->name);
        prog = my_strcat("\n\nProg nb: ", my_itoa(champion->prog_number));
        name = my_strcat(name, prog);
    }
    sfText_setString(a->champtxt[0].text, name);
    sfText_setString(a->champtxt[1].text,
    my_strcat("Carry: ", my_itoa(champion->carry)));
    sfText_setString(a->champtxt[2].text,
    my_strcat("Cooldown: ", my_itoa(champion->cooldown)));
    sfText_setString(a->champtxt[7].text,
    my_strcat("Live: ", my_itoa(champion->live_counter[0])));
    sfText_setString(a->champtxt[4].text,
    my_strcat("Registers: ", get_register_string(a, champion)));
}

void fill_champ_texts(corewar_t *core, champion_t *champion, all_t *a, int n)
{
    sfVector2f pos = {0, 0};
    int i_pos = 0;

    for (int i = 0; i < 8; i++) {
        if (i == 3 || i == 5 || i == 6)
            continue;
        if (i == 1 || i == 7)
            i_pos++;
        i_pos++;
        set_color(champion->prog_number, a->champtxt[i].text);
        pos = (sfVector2f){1570, (i_pos) * 30};
        sfText_setPosition(a->champtxt[i].text,
        (sfVector2f){pos.x, pos.y + (30 + n * 250)});
    }
    edit_cycles_texts(core, a);
    edit_champion_texts(champion, a);
    for (int s = 0; s < 8; s++) {
        sfRenderWindow_drawText(a->win, a->champtxt[s].text,
        NULL);
    }
}