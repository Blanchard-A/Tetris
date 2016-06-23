##
## Makefile for Makefile in /home/blanch_p/rendu/PSU_2015_my_printf
## 
## Made by Alexandre Blanchard
## Login   <blanch_p@epitech.net>
## 
## Started on  Wed Nov 11 18:01:44 2015 Alexandre Blanchard
## Last update Fri Feb  5 20:13:10 2016 Alexandre Blanchard
##

SRC=	my_putchar.c\
	my_putstr.c\
	my_put_nbr.c\
	my_put_ptr.c\
	flag1.c\
	flag2.c\
	flag3.c\
	printf.c\
	my_getnbr.c

OBJ=	$(SRC:.c=.o)

NAME=	libmy.a

all:	$(NAME)

$(NAME):	
		cc -c $(SRC)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)
		mv $(NAME) ../

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f ../$(NAME)

re:	fclean all
