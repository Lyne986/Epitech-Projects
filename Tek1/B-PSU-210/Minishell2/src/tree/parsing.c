/*
** EPITECH PROJECT, 2021
** B-PSU-210-MPL-2-1-minishell2-diogo.faria-martins
** File description:
** parsing
*/

#include "mysh.h"

void parse_buff(all_t *a, char *buff)
{
    int index = get_sep(a, buff, 0);

    a->parsing->left = malloc(sizeof(char) * index);
    my_memset(a->parsing->left, '\0', index);
    a->parsing->left = fill_tree_left(buff, index);
    a->parsing->right = fill_tree_right(buff, index, get_op(buff, 0, 0));
}

tree_t *init_tree_node(char *str, int sep)
{
    tree_t *tree = malloc(sizeof(tree_t));

    if (str == NULL)
        return (NULL);
    tree->left = NULL;
    tree->right = NULL;
    tree->str = my_strdup(str);
    tree->sep = sep;
    return (tree);
}

void parsing(all_t *a, tree_t *tree)
{
    if (tree == NULL || !are_seps(tree->str)) {
        return;
    }
    a->parsing = malloc(sizeof(parsing_t));
    a->parsing->sep = -1;
    a->parsing->left = NULL;
    a->parsing->right = NULL;
    tree->left = NULL;
    tree->right = NULL;
    parse_buff(a, tree->str);
    if (a->parsing->left == NULL && a->parsing->right == NULL)
        return;
    tree->left = init_tree_node
    (a->parsing->left, get_op(a->parsing->left, 0, 0));
    tree->right = init_tree_node
    (a->parsing->right, get_op(a->parsing->right, 0, 0));
    parsing(a, tree->left);
    parsing(a, tree->right);
}