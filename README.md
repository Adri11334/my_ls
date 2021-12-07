> Epitech Project 2021 <br>
> B1 - Unix System Programming<br>
> B-PSU-100

# my_ls
#### LiSting command-like

### Coding Style
- style mark: 0
- style major: 1
- style minor: 6
- style info: 4
<br>

### Note : 15.8% (before TA bug: 47.4%)
- 01: 3/5 (3/5)
- 02: 0/7 (6/7)
- 03: 0/1
- 04: 0/3
- 05: 0/2
- 06: 0/1

### Coverage: 94.2%
<br>

### Content
**binary name**: my_ls<br>
**language**: C<br>
**build tool**: via Makefile, including re, all, clean, fclean [my_tests, tests_run, cover, tests_file] rules
<br>

### Authorized Functions
The only system calls allowed are the following ones:
- opendir, readir, closedir, stat, lstat, write
- getpwuid, getgrgid, time, ctime, readlink,
- malloc, free, perror, strerror, exit.

### Goal
You must recode the **ls [-lRdrt] [FILE]** command. <br>
Options can be given in either order: <br>
```T
∼/B-PSU-100> ./my_ls -l -t
...
∼/B-PSU-100> ./my_ls -lRt
...
∼/B-PSU-100> ./my_ls -lt -R -t
```

It must be possible to pass a list of files/folders as parameters:

```T
∼/B-PSU-100> ./my_ls -l /dev /usr/sbin
...
∼/B-PSU-100> ./my_ls -l -r file1 file2
...
```
As a bonus, you could also handle others options, such as -uFgf.
<br>

### Examples
```T
∼/B-PSU-100> ./my_ls -l -R
.:
total 12
drwxr-xr-x 2 student student 4096 Nov 13 15:38 dir
-rw-r––- 1 johan johan 0 Nov 13 15:39 ‘#test#’
-rw-r––- 1 johan johan 22 Nov 13 15:39 test
-rw-r––- 1 johan johan 15 Nov 13 15:39 test~
./dir:
total 0
-rw-r–r– 1 student student 0 Nov 13 15:38 test
```
```T
∼/B-PSU-100> ls -la
total 24
drwxr-xr-x 4 johan johan 4096 Nov 13 16:11 .
drwxr-xr-x 12 johan johan 4096 Nov 13 15:39 ..
drwxr-xr-x 2 student student 4096 Nov 13 15:38 dir
drwxr-xr-x 2 johan johan 4096 Nov 13 16:11 .hiddenfolder
-rw-r––- 1 johan johan 0 Nov 13 15:39 ‘#test#’
-rw-r––- 1 johan johan 22 Nov 13 15:39 test
-rw-r––- 1 johan johan 15 Nov 13 15:39 test~
```

<br>

>- **Student:** Adrien VERMERSCH
>-  **Email:** adrien.vermersch@epitech.eu
>- **Year:** 2021
>- **Promotion:** 2026
>- **Campus:** Bordeaux

Code rédigé selon la norme Epitech (promo 2026).<br><br>
Recopier ce repo revient au vol de code.<br>
Autrement dit, -42<br><br>
