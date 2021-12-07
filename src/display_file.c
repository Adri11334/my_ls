/*
** EPITECH PROJECT, 2021
** my ls
** File description:
** get file functions
*/

#include "ls.h"

char *get_complete_path(const char *name, const char *path)
{
    int file_path_length = my_strlen(name) + my_strlen(path);
    char *file_path = malloc(file_path_length);
    int name_index = 0;

    my_strcpy(file_path, path);
    for (int i = my_strlen(path); i < file_path_length; i ++) {
        if (i == my_strlen(path)) {
            file_path[i] = '/';
        }
        if (name_index < my_strlen(name)) {
            file_path[i] = name[name_index];
            name_index++;
        }
    }
    file_path[file_path_length] = '\0';
    return file_path;
}

void display_permissions(struct stat st)
{
    my_putstr((st.st_mode & S_IRUSR) ? "r" : "-");
    my_putstr((st.st_mode & S_IWUSR) ? "w" : "-");
    if (st.st_mode & S_ISGID)
        my_putchar((st.st_mode & S_IXGRP) ? 's' : 'S');
    else
        my_putchar((st.st_mode & S_IXGRP) ? 'x' : '-');
    my_putstr((st.st_mode & S_IRGRP) ? "r" : "-");
    my_putstr((st.st_mode & S_IWGRP) ? "w" : "-");
    if (st.st_mode & S_ISGID)
        my_putchar((st.st_mode & S_IXGRP) ? 's' : 'S');
    else
        my_putchar((st.st_mode & S_IXGRP) ? 'x' : '-');
    my_putstr((st.st_mode & S_IROTH) ? "r" : "-");
    my_putstr((st.st_mode & S_IWOTH) ? "w" : "-");
    if (st.st_mode & S_ISVTX)
        my_putchar((st.st_mode & S_IXOTH) ? 't' : 'T');
    else
        my_putchar((st.st_mode & S_IXOTH) ? 'x' : '-');
}

void display_link(char *name, char *path, struct stat st)
{
    int size = (st.st_size == 0) ? PATH_MAX : st.st_size;
    char buffer[size + 1];

    size = readlink(path, buffer, size);
    if (size >= 0) {
        buffer[size] = '\0';
        write_cyan(name);
        my_putstr(" -> ");
        write_blue(buffer);
    }
}

void display_name(files_t *file)
{
    if (S_ISLNK(file->st.st_mode)){
        display_link(file->filename, file->filepath, file->st);
    } else {
        switch (file->st.st_mode & S_IFMT) {
            case S_IFDIR:  write_blue(file->filename); break;
            case S_IFREG:  write_white(file->filename); break;
            default:       write_white(file->filename); break;
        }
    }
}

int print_l_file(char *path)
{
    files_t *file = NULL;

    file = malloc(sizeof(files_t));
    file->prev = NULL;
    file->filename = path;
    file->filepath = path;
    if (lstat(file->filepath, &(file->st)) < 0)
        return 84;
    file->next = NULL;
    display_file(file);
    my_putchar('\n');
    return 0;
}
