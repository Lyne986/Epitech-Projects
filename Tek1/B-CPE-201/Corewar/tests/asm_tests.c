/*
** EPITECH PROJECT, 2021
** B-CPE-201-MPL-2-1-corewar-bastien.boymond
** File description:
** asm_tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <stdio.h>
#include "../include/asm.h"

Test(asm_tests, utilities)
{
    char **champ = my_str_to_word_array("ahh , ahh", ",");
    char **nl = NULL;
    char *b_nb = "10";
    char *nb = "1";
    char *n_nb = "*";
    int byte = 2;

    after_arg("hello guys");
    after_arg("hello \"guys");
    after_arg("he\"llo guy\"s");
    from_arg("hello guys\"");
    from_arg("hello guys");
    from_arg("h\"ello guys");
    from_arg("he\"llo guy\"s");
    to_arg("hello guys", " ");
    to_arg("hello guys", "k");
    to_arg("hello guys", "k  rtg");
    split_string("yo la zouz", " ");
    split_string("yo la zouz", " krf");
    split_string("yo la zouz", "k");
    cr_assert_eq(binary_to_dec(b_nb), 2);
    cr_assert_eq(is_number(nb), 1);
    cr_assert_eq(is_number(n_nb), 0);
    cr_assert_eq(my_strlen_array(champ), 2);
    cr_assert_eq(biteshifting(byte), 33554432);
    cr_assert_eq(my_strlen_array(nl), 0);
}

Test(asm_tests, utilities_array)
{
    char **champ = my_str_to_word_array("ahh , ahh", ",");
    char *str = array_to_str(champ);

    cr_assert_str_eq(str, "ahh  ahh");
}

Test(asm_tests, init_parsing)
{
    asm_t my_asm;

    init_asm(&my_asm);
    add_to_linked_lists(&my_asm, "#hey guys", 1);
    read_champion("./tests/asm_champion/abel.s", &my_asm);
}

Test(asm_tests, linked_lists)
{
    asm_t my_asm;

    init_asm(&my_asm);
    push_back_function(&my_asm.functions, "%1", 1);
    push_back_function(&my_asm.functions, "%1", 1);
    push_back_function(&my_asm.functions, "%1", 1);
    cr_assert_eq(is_containing("le plus beau des rebeux", 'p'), 1);
    cr_assert_eq(is_containing("le", 'p'), 0);
    cr_assert_eq(label_chars("**"), 0);
    cr_assert_eq(search_for_label(&my_asm, "****"), -1);
}

Test(asm_tests, parse_info_tests)
{
    asm_t my_asm;

    init_asm(&my_asm);
    read_champion("./tests/asm_champion/abel.s", &my_asm);
    parse_champion(&my_asm);
}

Test(asm_tests, print_champion)
{
    asm_t my_asm;

    init_asm(&my_asm);
    read_champion("./tests/asm_champion/42.s", &my_asm);
    parse_champion(&my_asm);
    print_champion(&my_asm);
}

Test(asm_tests, print_champion_two)
{
    asm_t my_asm;

    init_asm(&my_asm);
    read_champion("./tests/asm_champion/zork.s", &my_asm);
    parse_champion(&my_asm);
    print_champion(&my_asm);
}

Test(asm_tests, print_champion_three)
{
    asm_t my_asm;

    init_asm(&my_asm);
    read_champion("./tests/asm_champion/abel.s", &my_asm);
    parse_champion(&my_asm);
    print_champion(&my_asm);
}

Test(asm_tests, print_champion_four)
{
    asm_t my_asm;

    init_asm(&my_asm);
    read_champion("./tests/asm_champion/tyron.s", &my_asm);
    parse_champion(&my_asm);
    print_champion(&my_asm);
}

Test(asm_tests, print_champion_five)
{
    asm_t my_asm;

    init_asm(&my_asm);
    read_champion("./tests/asm_champion/short_42.s", &my_asm);
    parse_champion(&my_asm);
    print_champion(&my_asm);
}