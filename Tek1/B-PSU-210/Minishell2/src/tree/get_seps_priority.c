/*
** EPITECH PROJECT, 2021
** B-PSU-210-MPL-2-1-minishell2-diogo.faria-martins
** File description:
** get_seps_priority
*/

#include "mysh.h"

int get_seps_by_priority(char *str, int prio)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] == ';')
            return (SEMCOL);
        if (prio > 0 && str[i] == '|')
            return (PIPE);
        if (prio > 1) {
            if (str[i] == '>' && str[i + 1] != '>')
                return (RED_R);
            if (str[i] == '<' && str[i + 1] != '<')
                return (RED_L);
            if (str[i] == '>' && str[i + 1] == '>')
                return (D_RED_R);
            if (str[i] == '<' && str[i + 1] == '<')
                return (D_RED_L);
        }
    }
    return (-1);
}

int get_op(char *str, int i, int prio)
{
    int ret = 0;

    if (str == NULL)
        return (-1);
    for (prio = 0; prio < 3; prio++) {
        ret = get_seps_by_priority(str, prio);
    }
    if (ret == -1)
        return (EXEC);
    return (ret);
}

int get_sep(all_t *a, char *buffer, int prio)
{
    for (int i = 0; buffer[i]; i++) {
        a->parsing->sep =
        buffer[i] == ';' && a->parsing->sep == -1 ? SEMCOL :
        buffer[i] == '|' && prio > 0 && a->parsing->sep == -1 ? PIPE:
        buffer[i] == '>'
        && prio > 1 && a->parsing->sep == -1 ? RED_R :
        buffer[i] == '<'
        && prio > 1 && a->parsing->sep == -1 ? RED_L :
        buffer[i] == '<' && buffer[i + 1] != 0 && buffer[i + 1] == '<' &&
        prio > 1 && a->parsing->sep == -1 ? D_RED_L :
        buffer[i] == '>' && buffer[i + 1] != 0 && buffer[i + 1] == '>' &&
        prio > 1 && a->parsing->sep == -1 ? D_RED_R :
        a->parsing->sep;
        if (a->parsing->sep != -1)
            return (i);
    }
    if (prio < 3)
        return (get_sep(a, buffer, prio + 1));
}