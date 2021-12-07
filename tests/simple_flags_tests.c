/*
** EPITECH PROJECT, 2021
** ls
** File description:
** simple flags tests
*/

#include "ls.h"
int args_gestion(int argc, char **argv);

#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(test_l_flag, test_l_flag)
{
    char **args = malloc(2);
    char arg_0[8] = "./my_ls\0";
    char arg_1[3] = "-l\0";
    args[0] = arg_0;
    args[1] = arg_1;

    cr_assert_eq(args_gestion(2, args), 0);
    free(args);
}

Test(test_a_flag, test_a_flag)
{
    char **args = malloc(2);
    char arg_0[8] = "./my_ls\0";
    char arg_1[3] = "-a\0";
    args[0] = arg_0;
    args[1] = arg_1;

    cr_assert_eq(args_gestion(2, args), 0);
    free(args);
}
