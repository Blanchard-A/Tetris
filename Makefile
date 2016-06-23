##
## Makefile for makefile in /home/brunel_d/rendu/sem_2/prog_elem
## 
## Made by axel brunel
## Login   <brunel_d@epitech.net>
## 
## Started on  Mon Feb  8 10:08:54 2016 axel brunel
## Last update Mon Mar 21 11:11:40 2016 Alexandre Blanchard
##

SRC	=	src/main.c \
		src/tab.c \
		src/tab_pt_funct.c \
		src/create_struct.c \
		src/struct_tetrimino.c \
		src/check_struct_tetri.c \
		src/debug.c \
		src/get_option.c \
		src/my_getnbr.c \
		src/title_color.c \
		src/title_color_bis.c \
		src/put_interface.c \
		src/verif_deplacement.c \
		src/func_deplacement.c \
		src/canonique.c \
		src/config_param.c \
		src/next.c \
		src/get_size.c \
		src/divers_checks.c \
		src/gameplay.c \
		src/move.c \
		src/move_bis.c \
		src/my_revstr.c \
		src/my_putnbr.c \
		src/show_tetris_map.c \
		src/maj_score.c \
		src/malloc_options.c \
		src/truekey.c \
		src/tiret_options.c \
		src/fonction_struct.c \
		src/print_debug.c \
		src/debug_in_order.c \
		src/struct_malloc.c \
		src/struct_check.c \
		src/fct.c

OBJ	=	$(SRC:.c=.o)

NAME	=	tetris

CFLAGS	=	-Wall -W -Wextra -Werror -ansi -pedantic -Iinclude/

CC	=	gcc

RM	=	rm -f

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) -lncurses -lmy -L.

all:		$(NAME)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
