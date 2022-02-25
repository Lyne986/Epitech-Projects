/*
** EPITECH PROJECT, 2021
** B-PSU-101-MPL-1-1-minishell1-diogo.faria-martins
** File description:
** pwd_functions
*/

#include "my.h"
#include "mysh.h"
#include "printf.h"

void get_pwd(all_t *a)
{
    char pwd[1024];

    getcwd(pwd, sizeof(pwd));
    a->pwd = malloc(sizeof(char) * (my_strlen(pwd) + 2));
    a->pwd[my_strlen(pwd) + 1] = '\0';
    my_strcpy(a->pwd, pwd);
}

void get_oldpwd(all_t *a)
{
    char old_pwd[1024];

    getcwd(old_pwd, sizeof(old_pwd));
    a->old_pwd = malloc(sizeof(char) * (my_strlen(old_pwd) + 2));
    a->old_pwd[my_strlen(old_pwd) + 1] = '\0';
    my_strcpy(a->old_pwd, old_pwd);
}