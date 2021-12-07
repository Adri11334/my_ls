/*
** EPITECH PROJECT, 2021
** my ls
** File description:
** simple ls command
*/

#include "ls.h"

void print_only_names(folder_t *folder)
{
    while (folder->folder_content != NULL) {
        display_name(folder->folder_content);
        folder->folder_content = folder->folder_content->prev;
        my_putchar('\n');
    }
}

int print_only_name(char *path)
{
    files_t *file = NULL;

    file = malloc(sizeof(files_t));
    file->prev = NULL;
    file->filename = path;
    file->filepath = path;
    if (lstat(file->filepath, &(file->st)) < 0)
        return 84;
    file->next = NULL;
    display_name(file);
    my_putchar('\n');
    return 0;
}

int simple_complete_folder(folder_t *folder, char *path, int a_flag, DIR *dir)
{
    struct dirent *entry;

    entry = readdir(dir);
    while (entry != NULL) {
        if (a_flag == 1 || entry->d_name[0] != '.') {
            if (complete_folder(folder, path, a_flag, entry) == 84)
                return 84;
        }
        entry = readdir(dir);
    }
    closedir(dir);
    return 0;
}

int simple_ls(char *path, int a_flag)
{
    folder_t *folder = setup_folder(path);
    DIR *dir;

    if (open_dir_or_file(path) == 1)
        dir = opendir(path);
    else if (open_dir_or_file(path) == 2)
        return print_only_name(path);
    else {
        my_printf("my_ls: cannot access '%s': ", path);
        my_printf("No such file or directory\n");
        exit(84);
    }
    simple_complete_folder(folder, path, a_flag, dir);
    print_only_names(folder);
    return 0;
}
