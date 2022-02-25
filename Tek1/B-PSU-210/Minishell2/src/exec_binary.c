/*
** EPITECH PROJECT, 2021
** B-PSU-101-MPL-1-1-minishell1-diogo.faria-martins
** File description:
** exec_binary
*/

#include "my.h"
#include "mysh.h"
#include "printf.h"

void sig_catch(int sig)
{
    if (WIFSIGNALED(sig)) {
        if (WTERMSIG(sig) == 11)
            write(2, "Segmentation fault", 18);
        if (WTERMSIG(sig) == 8)
            write(2, "Floating exception", 18);
        if (WCOREDUMP(sig))
            write(2, " (core dumped)", 14);
        write(2, "\n", 1);
    }
}

void print_errors(all_t *a)
{
    if (errno == ENOEXEC) {
        my_printf("%s: %s.", a->sh_arr[0], strerror(ENOEXEC));
        my_printf("Wrong Architecture.\n");
    } else
        my_printf("%s: %s.\n", a->sh_arr[0], strerror(errno));
}

void exec_binary(all_t *a)
{
    int child_pid = 0;
    int wait_pid = 0;

    if (access(a->sh_arr[0], X_OK) != 0) {
        my_printf("%s: %s.\n", a->sh_arr[0], strerror(errno));
        return;
    }
    child_pid = fork();
    if (child_pid == 0) {
        if (execve(a->sh_arr[0], a->sh_arr, a->env) == -1)
            print_errors(a);
        exit(0);
    }
    else
        waitpid(child_pid, &wait_pid, 0);
    sig_catch(wait_pid);
}