/*
** EPITECH PROJECT, 2021
** my ls
** File description:
** detect the file type
*/

#include "ls.h"

char detect_file_type(struct stat st)
{
    switch (st.st_mode & S_IFMT) {
        case S_IFBLK:  return 'b'; break;
        case S_IFCHR:  return 'c'; break;
        case S_IFDIR:  return 'd'; break;
        case S_IFIFO:  return 'p'; break;
        case S_IFLNK:  return 'l'; break;
        case S_IFREG:  return '-'; break;
        case S_IFSOCK: return 's'; break;
        default:       return '?'; break;
    }
}
