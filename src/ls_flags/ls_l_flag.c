/*
** EPITECH PROJECT, 2021
** my ls
** File description:
** l flag
*/

#include "ls.h"
#include <grp.h>
#include <pwd.h>

int display_file(files_t *file)
{
    struct passwd *pw;
    struct group  *gr;
    char *time;

    pw = getpwuid(file->st.st_uid);
    gr = getgrgid(file->st.st_gid);
    time = my_strdup(ctime(&file->st.st_mtime));
    for (int i = 0; i < 4; i++)
        time++;
    time[12] = '\0';
    my_putchar(detect_file_type(file->st));
    display_permissions(file->st);
    my_printf(" %d ", file->st.st_nlink);
    my_putstr((pw != 0) ? pw->pw_name : "Unknow");
    my_putchar(' ');
    my_putstr((gr != 0) ? gr->gr_name : "Unknow");
    mprintf(" %d %s ", file->st.st_size, time);
    display_name(file);
    return 1;
}

int print_directory(folder_t *folder){
    my_printf("total %d\n", folder->total);
    while (folder->folder_content != NULL) {
        display_file(folder->folder_content);
        folder->folder_content = folder->folder_content->prev;
        my_putchar('\n');
    }
    return 0;
}

int ls_complete_folder(folder_t *folder, char *path, int a_flag, DIR *dir)
{
    struct dirent *entry;

    entry = readdir(dir);
    while (entry != NULL) {
        if (complete_folder(folder, path, a_flag, entry) == 84)
            return 84;
        entry = readdir(dir);
    }
    closedir(dir);
    folder->total /= 2;
    return 0;
}

int ls_l(char *path, int a_flag)
{
    folder_t *folder = setup_folder(path);
    DIR *dir;

    if (open_dir_or_file(path) == 1)
        dir = opendir(path);
    else if (open_dir_or_file(path) == 2)
        return print_l_file(path);
    else {
        my_printf("my_ls: cannot access '%s': ", path);
        my_printf("No such file or directory\n");
        exit(84);
    }
    ls_complete_folder(folder, path, a_flag, dir);
    print_directory(folder);
    return 0;
}
