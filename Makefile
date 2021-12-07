##
## EPITECH PROJECT, 2021
## my_ls
## File description:
## Makefile
##

##CFLAGS - CPPFLAGS - LDFLAGS
SRC	=	src/display_file.c	\
		src/ls_call_multi_args.c	\
		src/file_type.c	\
		src/check_type.c	\
		src/folder.c	\
		src/ls_main.c	\
		src/ls_flags/base_ls.c	\
		src/ls_flags/ls_l_flag.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_ls

CFLAGS	=	-Wall -Wextra #-Werror -Wshadow -Wimplicit -pedantic

CPPFLAGS += -L./lib -lprintf
CPPFLAGS += -L./lib -lmy
CPPFLAGS += -I./include/
CPPFLAGS += -O2

all:	$(NAME)

lib:
	make -s -C ./lib/my_printf
	make -s -C ./lib/my

$(NAME):	lib	$(OBJ)
	gcc main.c $(OBJ) -o $(NAME) -ggdb3 $(CPPFLAGS)
	rm -f $(OBJ)

debug:	lib	$(OBJ)
	gcc main.c $(OBJ) -o $(NAME) -ggdb3 $(CPPFLAGS) -g
	rm -f $(OBJ)

tests_run:	lib
	gcc -o uni_t $(SRC) tests/*.c $(CPPFLAGS) --coverage -lcriterion
	-./uni_t
	rm uni_t

cover:
	mkdir -p criterions_r
	gcovr --exclude tests/ --html --html-details -o criterions_r/cover.html
	gcovr --branches --exclude tests/
	make -C ./ clean

clean:
	make -s -C ./lib/my_printf clean
	make -s -C ./lib/my clean
	rm -f $(OBJ)
	rm -f *.o
	rm -f *~
	rm -f vgcore*
	rm -f #*
	rm -f *.gcda
	rm -f *.gcno

fclean:	clean
	make -s -C ./lib/my_printf fclean
	make -s -C ./lib/my fclean
	rm -f $(NAME)
	rm -f criterions_r/*.html
	rm -f criterions_r/*.css
	rm -rf criterions_r/

re:	fclean all

my_tests: re tests_run cover

.PHONY: all clean fclean re tests_run cover my_tests lib
