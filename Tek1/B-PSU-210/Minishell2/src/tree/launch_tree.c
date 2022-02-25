/*
** EPITECH PROJECT, 2021
** B-PSU-210-MPL-2-1-minishell2-diogo.faria-martins
** File description:
** launch_tree
*/

#include "mysh.h"

void exec_tree_cmd(all_t *a, tree_t *tree)
{
    if (tree->sep == PIPE) {
        if (exec_pipe(a, tree) == -1) {
            launch_tree(a, tree->right);
        }
    }
    if (tree->sep == RED_R) {
        exec_simple_redir_right(a, tree);
    }
    if (tree->sep == RED_L) {
        exec_simple_redir_left(a, tree);
    }
    if (tree->sep == D_RED_R) {
        exec_double_redir_right(a, tree);
    }
    if (tree->sep == D_RED_L) {
        return;
    }
    return;
}

void exec(all_t *a, tree_t *tree)
{
    if (tree == NULL)
        return;
    if (tree->sep == EXEC) {
        a->sh_arr = parse_string(tree->str, " \n\t", 0);
        for (a->array_size = 0; a->sh_arr[a->array_size]; a->array_size++);
        launch_command(a, find_cmd_command(a));
    }
}

void launch_tree(all_t *a, tree_t *tree)
{
    if (tree == NULL)
        return;
    if (check_only_seps(tree->str) == 0)
        return;
    if (tree->sep == SEMCOL) {
        launch_tree(a, tree->left);
        launch_tree(a, tree->right);
        return;
    }
    exec_tree_cmd(a, tree);
    exec(a, tree);
}