/*
** EPITECH PROJECT, 2021
** B-PSU-210-MPL-2-1-minishell2-diogo.faria-martins
** File description:
** redirection_left
*/

#include "mysh.h"
#include "printf.h"

int redir_left_tree_errors(tree_t *tree)
{
    if (tree == NULL || (tree->right == NULL || tree->right->str[0] == '\n')) {
        my_printf("Missing name for redirect.\n");
        return (-1);
    }
    if (tree->left == NULL) {
        my_printf("Invalid null command.\n");
        return (-1);
    }
    return (1);
}

void exec_simple_redir_left(all_t *a, tree_t *tree)
{
    if (redir_left_tree_errors(tree) == -1)
        return;
    return;
}