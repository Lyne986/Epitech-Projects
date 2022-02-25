/*
** EPITECH PROJECT, 2021
** B-PSU-101-MPL-1-1-minishell1-diogo.faria-martins
** File description:
** cd_prompts
*/

#include "my.h"
#include "mysh.h"
#include "printf.h"

void do_simple_cd(all_t *a)
{
    char **home = get_home(&a->envi);

    get_pwd(a);
    modify_env_strings(a, "OLDPWD", a->pwd);
    modify_env_strings(a, "PWD", home[1]);
    get_oldpwd(a);
    if (chdir(home[1]) == -1) {
        return;
    }
}

void do_path_cd(all_t *a)
{
    get_pwd(a);
    modify_env_strings(a, "OLDPWD", a->pwd);
    get_oldpwd(a);
    if (chdir(a->sh_arr[1]) == -1) {
        my_printf("%s: %s.\n", a->sh_arr[1], strerror(errno));
        return;
    }
    get_pwd(a);
    modify_env_strings(a, "PWD", a->pwd);
}

void do_dash_cd(all_t *a)
{
    if (a->old_pwd == NULL) {
        my_printf(": No such file or directory.\n");
        return;
    }
    get_pwd(a);
    modify_env_strings(a, "OLDPWD", a->pwd);
    if (chdir(a->old_pwd) == -1) {
        my_printf("%s: %s.\n", a->sh_arr[1], strerror(errno));
        return;
    }
    a->old_pwd = a->pwd;
    get_pwd(a);
    modify_env_strings(a, "PWD", a->pwd);
}

int grab_cd_command(all_t *a)
{
    int counter = 0;

    for (int i = 0; a->sh_arr[1][i]; i++)
        if (a->sh_arr[1][i] == '-')
            counter++;
        else {
            counter = -1;
            break;
        }
    if (counter >= 2)
        return (-1);
    if (counter == 1)
        return (DASH);
    return (PATH);
}

void cd_command(all_t *a)
{
    char **home = get_home(&a->envi);

    for (a->array_size = 0; a->sh_arr[a->array_size]; a->array_size++);
    for (int i = 0; home[i]; i++);
    if (a->array_size >= 3) {
        write (2, "cd: Too many arguments.\n", 24);
        return;
    }
    if (a->array_size == 1) {
        a->cd = SIMPLE;
    }
    if (a->array_size == 2) {
        if ((a->cd = grab_cd_command(a)) == -1)
            return;
    }
    do_cd(a, a->cd);
}