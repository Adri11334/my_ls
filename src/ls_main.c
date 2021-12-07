/*
** EPITECH PROJECT, 2021
** ls
** File description:
** main file
*/

#include "ls.h"

void flags_listing(char *flags, char *flag_list, int *flag_index)
{
    for (int i = 0; i < my_strlen(flags); i++)
    {
        if (is_letter(flag_list, flags[i]) == 0 && flags[i] != '-') {
            flag_list[*flag_index] = flags[i];
            (*flag_index)++;
        }
    }
}

int start_ls_flags(char **path, char *flags, int path_length)
{
    int a_flag = is_letter(flags, 'a') ? 1 : 0;
    int l_flag = is_letter(flags, 'l') ? 1 : 0;

    if (l_flag >= 1){
        if (path_length >= 1)
            start_multi_l(path, path_length, a_flag);
        else
            return ls_l("./", a_flag);
    } else {
        if (path_length >= 1)
            start_multi_simple(path, path_length, a_flag);
        else
            return simple_ls("./", a_flag);
    }
    free(flags);
    return 0;
}

int ls_checker(char **path, char **flags, int path_length, int flags_length)
{
    char *flag = malloc(3);
    int flag_index = 0;

    if (flags[0] == NULL) {
        if (path[0] == NULL)
            return simple_ls("./", 0);
        if (path_length > 1)
            start_multi_simple(path, path_length, 0);
        else
            return simple_ls(path[0], 0);
    } else {
        for (int tmp_fi = 0; tmp_fi < flags_length; tmp_fi++)
            flags_listing(flags[tmp_fi], flag, &flag_index);
    }
    return start_ls_flags(path, flag, path_length);
}

int args_gestion(int argc, char **argv)
{
    char **path = malloc(sizeof(char*) * argc);
    char **flags = malloc(sizeof(char*) * argc);
    int path_index = 0;
    int flags_index = 0;

    for (int i = 1; i < argc; i++) {
        if (argv[i][0] == '-') {
            flags[flags_index] = argv[i];
            flags_index++;
        } else {
            path[path_index] = argv[i];
            path_index++;
        }
    }
    flags[flags_index] = NULL;
    path[path_index] = NULL;
    return ls_checker(path, flags, path_index, flags_index);
}