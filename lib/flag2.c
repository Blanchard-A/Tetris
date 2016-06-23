/*
** flag2.c for flag in /home/blanch_p/test/printf/pointeurs
** 
** Made by Alexandre Blanchard
** Login   <blanch_p@epitech.net>
** 
** Started on  Wed Nov 11 17:45:24 2015 Alexandre Blanchard
** Last update Wed Nov 11 17:56:31 2015 Alexandre Blanchard
*/

#include "printf.h"

int	entier(va_list ap)
{
  my_put_nbr(va_arg(ap, int), 10, 0);
}

int	unsign(va_list ap)
{
  my_put_nbr(va_arg(ap, int), 10, 0);
}

int	caract(va_list ap)
{
  my_putchar(va_arg(ap, int));
}

int	chain(va_list ap)
{
  my_putstr(va_arg(ap, char *));
}

int	ptr(va_list ap)
{
  my_putstr("0x");
  my_put_ptr(va_arg(ap, long), 16, 39);
}
