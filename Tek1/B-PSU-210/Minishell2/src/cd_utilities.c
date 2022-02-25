/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** cd_commands
*/

#include "my.h"
#include "mysh.h"
#include "printf.h"

void do_cd(all_t *a, int cmd)
{
    get_pwd(a);
    if (cmd == SIMPLE) {
        do_simple_cd(a);
    }
    if (cmd == PATH) {
        do_path_cd(a);
    }
    if (cmd == DASH) {
        do_dash_cd(a);
    }
}

int is_home(char *str)
{
    if (str[0] == 'H' && str[1] == 'O'  && str[2] == 'M'  && str[3] == 'E')
        return (1);
    return (-1);
}

char **get_home(env_t **list)
{
    env_t *new = *list;
    char **path;

    for (; is_home(new->value) != 1 && new->next != NULL; new = new->next);
    path = parse_string(new->value, "=", 0);
    return (path);
}

void set_pwd(all_t *a, char *pwd)
{
    char new_pwd[1024];
    env_t *pwd_list = a->envi;

    for (;pwd_list != NULL; pwd_list = pwd_list->next)
        if (my_strncmp(pwd_list->value, pwd, my_strlen(pwd) - 1) == 0)
            break;
    pwd_list->value = my_strcat(pwd, getcwd(new_pwd, sizeof(new_pwd)));
}

void modify_env_strings(all_t *a, char *old, char *new)
{
    env_t *t = a->envi;

    for ( ; t != NULL && my_strncmp(t->value, old,
    my_strlen(old) - 1) != 0; t = t->next);
    if (t == NULL) {
        return;
    }
    t->value = my_strcat(my_strcat(old, "="), new);
}