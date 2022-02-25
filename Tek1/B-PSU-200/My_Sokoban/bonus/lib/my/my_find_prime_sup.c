/*
** EPITECH PROJECT, 2021
** B-PSU-101-MPL-1-1-minishell1-diogo.faria-martins
** File description:
** my_find_prime_sup
*/

int my_is_prime(int nb);

int my_find_prime_sup(int nb)
{
    int nb_result = my_is_prime(nb);

    if (nb_result == 0)
        return (my_find_prime_sup(nb + 1));
    return (nb);
}
