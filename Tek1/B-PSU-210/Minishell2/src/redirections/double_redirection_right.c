/*
** EPITECH PROJECT, 2021
** B-PSU-210-MPL-2-1-minishell2-diogo.faria-martins
** File description:
** double_redirection_right
*/

#include "mysh.h"
#include "printf.h"

int double_redir_right_tree_errors(tree_t *tree)
{
    if (tree == NULL || tree->right == NULL) {
        my_printf("Missing name for redirect.\n");
        return (-1);
    }
    if (tree->left == NULL) {
        my_printf("Invalid null command.\n");
        return (-1);
    }
    return (1);
}

void exec_double_redir_right(all_t *a, tree_t *tree)
{
    if (double_redir_right_tree_errors(tree) == -1)
        return;
    char **arr = parse_string(tree->right->str, " \n\t", 0);
    int fd = 0;
    int pid = 0;

    if ((fd = open(arr[0], O_CREAT | O_WRONLY | O_APPEND, 0666)) == -1) {
        my_printf("%s: %s.\n", arr[0], strerror(errno));
        return;
    }
    pid = fork();
    if (pid == 0) {
        dup2(fd, 1);
        exec(a, tree->left);
        close(fd);
        exit (0);
    } else
        wait(&pid);
    dup2(dup(1), 1);
    close(fd);
}