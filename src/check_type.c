/*
** EPITECH PROJECT, 2021
** ls
** File description:
** check dir or file
*/

#include "ls.h"
#include <errno.h>

int open_dir_or_file(char *path)
{
    DIR *dir;

    dir = opendir(path);
    if (dir != NULL) {
        closedir(dir);
        return 1;
    } else if (errno == ENOTDIR) {
        return 2;
    }
    return 84;
}
