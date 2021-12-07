/*
** EPITECH PROJECT, 2021
** my ls
** File description:
** myls header
*/

#ifndef LS_H_
#define LS_H_
    #include <stdlib.h>
    #include <stddef.h>
    #include <sys/stat.h>
    #include <dirent.h>
    #include "my.h"
    #include "my_printf.h"
    #include <time.h>
    #include <unistd.h>

    typedef struct files_s {
        char *filename;
        char *filepath;
        struct stat st;
        struct files_s *next;
        struct files_s *prev;
    } files_t;

    typedef struct folder_s {
        long total;
        char *folder_path;
        files_t *folder_content;
    } folder_t;

    char **string_parser(char *str, char key, int *array_length);
    char detect_file_type(struct stat st);
    int ls_checker(char **path, char **flags, int path_length,
                    int flags_length);
    int simple_ls(char *path, int a_flag);
    char *get_complete_path(const char *name, const char *path);
    int ls_l(char *path, int a_flag);
    int open_dir_or_file(char *path);

    folder_t *setup_folder(char *path);
    int complete_folder(folder_t *folder, char *path, int a_flag,
                        struct dirent *entry);

    void start_multi_simple(char **path, int path_length, int a_flag);
    void start_multi_l(char **path, int path_length, int a_flag);

    void display_permissions(struct stat st);
    void display_name(files_t *file);
    int display_file(files_t *file);
    int print_l_file(char *path);
    void write_white(char *str);
    void write_blue(char *str);
    void write_green(char *str);
#endif/* !LS_H_ */
