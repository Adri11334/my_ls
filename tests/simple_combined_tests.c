/*
** EPITECH PROJECT, 2021
** ls
** File description:
** tests combined simple
*/

#include "ls.h"
int args_gestion(int argc, char **argv);

#include <criterion/criterion.h>
#include <criterion/redirect.h>

Test(test_a_flag_one_folder, test_a_flag_one_folder)
{
    char **args = malloc(2);
    char arg_0[8] = "./my_ls\0";
    char arg_1[3] = "-a\0";
    char arg_2[6] = "src/\0";
    args[0] = arg_0;
    args[1] = arg_1;
    args[2] = arg_2;

    cr_assert_eq(args_gestion(3, args), 0);
    free(args);
}

Test(test_l_flag_one_folder, test_l_flag_one_folder)
{
    char **args = malloc(2);
    char arg_0[8] = "./my_ls\0";
    char arg_1[3] = "-l\0";
    char arg_2[6] = "/usr/\0";
    args[0] = arg_0;
    args[1] = arg_1;
    args[2] = arg_2;

    cr_assert_eq(args_gestion(3, args), 0);
    free(args);
}

Test(test_la_flag_one_folder, test_la_flag_one_folder)
{
    char **args = malloc(2);
    char arg_0[8] = "./my_ls\0";
    char arg_1[4] = "-la\0";
    char arg_2[9] = "Makefile\0";
    args[0] = arg_0;
    args[1] = arg_1;
    args[2] = arg_2;

    cr_assert_eq(args_gestion(3, args), 0);
    free(args);
}

Test(test_multiple_files, test_multiple_files)
{
    char **args = malloc(2);
    char arg_0[8] = "./my_ls\0";
    char arg_1[11] = ".gitignore\0";
    char arg_2[9] = "Makefile\0";
    args[0] = arg_0;
    args[1] = arg_1;
    args[2] = arg_2;

    cr_assert_eq(args_gestion(3, args), 0);
    free(args);
}
