/*
** EPITECH PROJECT, 2021
** ls
** File description:
** simple tests
*/

#include "ls.h"
int args_gestion(int argc, char **argv);

#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(test_no_args, test_no_args)
{
    char **args = malloc(2);
    char arg_0[8] = "./my_ls\0";
    args[0] = arg_0;

    cr_assert_eq(args_gestion(1, args), 0);

    free(args);
}

Test(test_one_file, test_file)
{
    char **args = malloc(2);
    char arg_0[8] = "./my_ls\0";
    char arg_1[9] = "Makefile\0";
    args[0] = arg_0;
    args[1] = arg_1;

    cr_assert_eq(args_gestion(2, args), 0);
    free(args);
}

Test(test_one_folder, test_folder)
{
    char **args = malloc(2);
    char arg_0[8] = "./my_ls\0";
    char arg_1[6] = "src/\0";
    args[0] = arg_0;
    args[1] = arg_1;

    cr_assert_eq(args_gestion(2, args), 0);
    free(args);
}

Test(test_none_folder, test_none_folder, .exit_code = 84)
{
    char **args = malloc(2);
    char arg_0[8] = "./my_ls\0";
    char arg_1[5] = "ur/\0";
    args[0] = arg_0;
    args[1] = arg_1;

    cr_assert_eq(args_gestion(2, args), 0);
    free(args);
}
