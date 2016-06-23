/*
** my_putstr.c for my_putstr in /home/blanch_p/Librairie/librairie_J08
** 
** Made by Alexandre Blanchard
** Login   <blanch_p@epitech.net>
** 
** Started on  Thu Oct  8 14:04:01 2015 Alexandre Blanchard
** Last update Mon Nov 16 14:57:20 2015 Alexandre Blanchard
*/

#include <stdio.h>

int	my_putstr(char *str)
{
  int a;

  a = 0;
  if (str == NULL)
    {
      my_putstr("(null)");
      return (1);
    }
  while (str[a] != '\0')
    {
      my_putchar(str[a]);
      a = a + 1;
    }
}
