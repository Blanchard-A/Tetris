/*
** flag1.c for flag in /home/blanch_p/test/printf/pointeurs
** 
** Made by Alexandre Blanchard
** Login   <blanch_p@epitech.net>
** 
** Started on  Wed Nov 11 17:43:12 2015 Alexandre Blanchard
** Last update Wed Nov 11 17:56:23 2015 Alexandre Blanchard
*/

#include "printf.h"

int	p_hexa(va_list ap)
{
  my_put_nbr(va_arg(ap, int), 16, 39);
}

int	g_hexa(va_list ap)
{
  my_put_nbr(va_arg(ap, int), 16, 7);
}

int	octal(va_list ap)
{
  my_put_nbr(va_arg(ap, int), 8, 0);
}

int	bin(va_list ap)
{
  my_put_nbr(va_arg(ap, int), 2, 0);
}

int	fct_s(va_list ap)
{
  int	i;
  char	*s;

  s = va_arg(ap, char *);
  i = 0;
  while (s[i] != '\0')
    {
      if (s[i] < 32 || s[i] >= 127)
        {
          my_putchar('\\');
          if (s[i] >= 8 && s[i] <= 127)
            my_putstr("0");
          if (s[i] < 7)
            my_putstr("00");
          my_put_nbr(s[i], 8, 0);
        }
      else
        {
          my_putchar(s[i]);
        }
      i = i + 1;
    }
}
