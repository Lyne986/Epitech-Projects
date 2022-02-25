/*
** EPITECH PROJECT, 2021
** B-CPE-210-MPL-2-1-solostumper07-diogo.faria-martins
** File description:
** main
*/

#include "../include/mysh.h"

int main(int ac, char **av, char **env)
{
    all_t a;

    a.env = env;
    a.status = -45;
    a.pwd = NULL;
    a.old_pwd = NULL;
    a.ret = 0;
    a.pipe_nb = 0;
    a.envi = setenve(&a);
    wait_inputs(&a);
    return (0);
}