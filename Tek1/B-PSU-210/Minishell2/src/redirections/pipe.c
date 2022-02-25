/*
** EPITECH PROJECT, 2021
** B-PSU-210-MPL-2-1-minishell2-diogo.faria-martins
** File description:
** pipe
*/

#include "mysh.h"
#include "printf.h"

void do_pipe(all_t *a, tree_t *tree, int *pipearr, int index, int pipenb)
{
    if (fork() == 0) {
        if (index != 0) {
            dup2(pipearr[index - 2], 0);
        }
        if (index + 2 != pipenb * 2) {
            dup2(pipearr[index + 1], 1);
        }
        for (int i = 0; i < pipenb * 2; i += 1)
            close(pipearr[i]);
        if (index + 2 == pipenb * 2) {
            launch_tree(a, tree->right);
        } else {
            launch_tree(a, tree->left);
        }
        exit (0);
    }
}

int pipe_errors(all_t *a, tree_t *tree)
{
    if (tree == NULL)
        return (-1);
    if (tree->left == NULL || tree->right == NULL) {
        my_printf("Invalid null command.\n");
        return (-1);
    }
    return (1);
}

int count_pipe_nb(all_t *a, char *str)
{
    char *seps = "|";
    int is_sep = 0;

    for (int i = 0; str[i]; i++) {
        is_sep = str[i] == '|' ?  is_sep + 1: is_sep;
    }
    return (is_sep + 1);
}

int exec_pipe(all_t *a, tree_t *tree)
{
    static bool dpipe = false;

    if (pipe_errors(a, tree) == -1)
        return (1);
    if (dpipe == true)
        return (-1);
    dpipe = true;
    int pipenb = count_pipe_nb(a, tree->str);
    int *pipearr = malloc(sizeof(int) * ((pipenb * 2) + 1));
    for (int i = 0; i < pipenb * 2; i += 2) {
        pipe(&pipearr[i]);
    }
    for (int i = 0; i < pipenb * 2; i += 2) {
        do_pipe(a, tree, pipearr, i, pipenb);
    }
    for (int i = 0; i < pipenb * 2; i += 1)
        close(pipearr[i]);
    for (int i = 0; i <= pipenb; i++)
        wait(NULL);
}