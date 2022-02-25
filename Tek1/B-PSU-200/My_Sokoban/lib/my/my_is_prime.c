/*
** EPITECH PROJECT, 2021
** B-PSU-101-MPL-1-1-minishell1-diogo.faria-martins
** File description:
** my_is_prime
*/

int my_is_prime(int nb)
{
    int i = 1;
    int nb_start = nb;
    int count = 0;

    while (i <= nb_start) {
        nb = nb_start % i;
        if (nb == 0) {
            count++;
        }
        i++;
    }
    if (count == 2) {
        return (1);
    } else {
        return (0);
    }
}