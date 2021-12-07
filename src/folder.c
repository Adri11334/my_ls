/*
** EPITECH PROJECT, 2021
** ls
** File description:
** setup the folder
*/

#include "ls.h"

int complete_folder(folder_t *folder, char *path, int a_flag,
                    struct dirent *entry)
{
    files_t *file = NULL;

    if (a_flag == 1 || entry->d_name[0] != '.') {
        file = malloc(sizeof(files_t));
        file->prev = folder->folder_content;
        file->filename = entry->d_name;
        file->filepath = get_complete_path(entry->d_name, path);
        if (lstat(file->filepath, &(file->st)) < 0)
            return 84;
        folder->total += file->st.st_blocks;
        file->next = NULL;
        if (folder->folder_content != NULL)
            folder->folder_content->next = file;
        folder->folder_content = file;
    }
    return 0;
}

folder_t *setup_folder(char *path)
{
    folder_t *folder = malloc(sizeof(folder_t));

    folder->folder_content = NULL;
    folder->folder_path = path;
    folder->total = 0;
    return folder;
}
