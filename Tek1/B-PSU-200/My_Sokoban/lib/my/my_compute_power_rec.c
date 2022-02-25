/*
** EPITECH PROJECT, 2021
** B-PSU-101-MPL-1-1-minishell1-diogo.faria-martins
** File description:
** my_compute_power_rec
*/

int my_compute_power_rec(int nb, int p)
{
    if (p == 0)
        return 1;
    if (p < 0)
        return 0;
    return (nb * my_compute_power_rec(nb, p - 1));
}