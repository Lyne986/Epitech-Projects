/*
** EPITECH PROJECT, 2021
** minishell2
** File description:
** mysh
*/

#ifndef MYSH_H_
#define MYSH_H_

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "stdlib.h"
#include <signal.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stddef.h>
#include <stdio.h>
#include <stdbool.h>
#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#include "my.h"

enum cmd {
    ENV,
    CD,
    BINARY,
    EXIT
};

enum cd {
    DASH,
    PATH,
    SIMPLE
};

enum sep {
    EXEC,
    PIPE,
    SEMCOL,
    RED_L,
    RED_R,
    D_RED_R,
    D_RED_L
};

typedef struct parsing_s {
    int sep;
    char *left;
    char *right;
} parsing_t;

typedef struct tree_s
{
    int sep;
    char *str;
    struct tree_s *left;
    struct tree_s *right;
} tree_t;

typedef struct env
{
    char *value;
    struct env *next;
} env_t;

typedef struct all_s {
    int cd;
    int pipe_nb;
    tree_t *tree;
    parsing_t *parsing;
    char **env;
    char **sh_arr;
    char *sh_buff;
    int array_size;
    int status;
    env_t *envi;
    bool coldpwd;
    bool used_cd;
    bool wentback;
    int ret;
    char *pwd;
    char *old_pwd;
} all_t;

char *my_memset(char *str, char c, int size);

void do_cd(all_t *a, int cmd);
int check_only_seps(char *str);
void launch_tree(all_t *a, tree_t *tree);
void wait_inputs(all_t *a);
void launch_command(all_t *a, int command);
void int_list_push_back(env_t **list, char *value);
void exec_path_command(all_t *all);
void int_list_destroy(env_t **list);
void unset_env(all_t *a, char *value);
int already_env(all_t *all);
int handle_env_errors(all_t *a);
void modify_env_strings(all_t *a, char *old, char *new);
int get_op(char *str, int i, int prio);
void exec_double_redir_right(all_t *a, tree_t *tree);
void exec_simple_redir_right(all_t *a, tree_t *tree);
void exec_simple_redir_left(all_t *a, tree_t *tree);
char *fill_tree_right(char *str, int index, int sep);
void exec(all_t *a, tree_t *tree);
int are_seps(char *str);
char *fill_tree_left(char *str, int index);
int is_env(char *str, all_t *all);
void parsing(all_t *a, tree_t *tree);
struct env *setenve(all_t *all);
void printlist(env_t *list);
void env_commands(all_t *a);
void already_pushed(all_t *a);
char *handle_arrays(all_t *a);
void exec_binary(all_t *a);
tree_t *init_tree_node(char *str, int sep);
int find_cmd_command(all_t *a);
char **get_home(env_t **list);
void set_pwd(all_t *a, char *pwd);
void used_cd(all_t *a, char *pwd);
void do_dash_cd(all_t *a);
void do_path_cd(all_t *a);
void do_simple_cd(all_t *a);
void get_pwd(all_t *a);
void get_oldpwd(all_t *a);
int exec_pipe(all_t *a, tree_t *tree);
void cd_command(all_t *a);
int get_sep(all_t *a, char *buffer, int prio);

#endif /* !MYSH_H_ */
