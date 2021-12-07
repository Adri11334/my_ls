/*
** EPITECH PROJECT, 2021
** ls
** File description:
** start multi file
*/

#include "ls.h"

void start_multi_simple(char **path, int path_length, int a_flag)
{
    for (int i = 0; i < path_length; i++) {
        my_printf("%s:\n", path[i]);
        simple_ls(path[i], a_flag);
        if (i != path_length - 1)
            my_putchar('\n');
    }
}

void start_multi_l(char **path, int path_length, int a_flag)
{
    for (int i = 0; i < path_length; i++) {
        if (path_length > 1)
            my_printf("%s:\n", path[i]);
        ls_l(path[i], a_flag);
        if (i != path_length - 1)
            my_putchar('\n');
    }
}
