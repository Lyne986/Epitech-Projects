/*
** EPITECH PROJECT, 2021
** B-PSU-101-MPL-1-1-minishell1-diogo.faria-martins
** File description:
** commands_handled_path
*/

#include "mysh.h"
#include "printf.h"

int is_path(char *str)
{
    if (str[0] == 'P' && str[1] == 'A'  && str[2] == 'T'  && str[3] == 'H')
        return (1);
    return (-1);
}

char **get_path(env_t **list)
{
    char **path;
    env_t *new = *list;

    for (; is_path(new->value) != 1; new = new->next);
    path = parse_string(new->value, ":=", 0);
    return (path);
}

char *handle_path(char **path, char *command)
{
    int axess = 0;
    char *exec = malloc(sizeof(char) * my_strlen(command) * 5);
    char *save = malloc(sizeof(char) * my_strlen(command) + 1);

    save = command;
    command = my_strcat("/", save);
    for (int i = 0; path[i] != NULL; i++) {
        exec = my_strcat(path[i], command);
        axess = access(exec, 0);
        if (axess == 0) {
            return (exec);
        }
    }
    my_printf("%s: ", save);
    my_printf("Command not found.\n");
    return (NULL);
}

void exec_path_command(all_t *a)
{
    env_t *list = setenve(a);
    char **path = get_path(&list);
    int stat_waitpid = 0;
    int child_pid = 5;

    if (handle_path(path, a->sh_arr[0]) != NULL)
        child_pid = fork();
    if (child_pid == 0 && handle_path(path, a->sh_arr[0]) != NULL) {
        if (execve(handle_path(path, a->sh_arr[0]), a->sh_arr
        , NULL) == -1) {
            a->ret = -1;
            my_printf("%s: %s.\n", a->sh_arr[0], strerror(errno));
            int_list_destroy(&list);
            exit(0);
        }
    }
    else {
        int_list_destroy(&list);
        waitpid(child_pid, &stat_waitpid, 0);
    }
}