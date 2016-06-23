/*
** my_getnbr.c for getnbr in /home/brunel_d/rendu/shell/PSU_2015_minishell1/src
** 
** Made by axel brunel
** Login   <brunel_d@epitech.net>
** 
** Started on  Fri Jan 22 13:30:02 2016 axel brunel
** Last update Mon Mar 14 19:52:29 2016 axel brunel
*/

#include "tetris.h"

int	if_neg(int nb, char *str, int i)
{
  if (str[0] > 47 && str[0] < 58)
    return (nb);
  if (str[i - 1] == 45)
    nb = nb * (-1);
  else
    nb = nb;
  return (nb);
}

int	my_getnbr(char *str)
{
  int	nb;
  int	i;

  nb = 0;
  i = 0;
  if (str[i] < 48 || str[i] > 57)
    return (-1);
  while (str[i] > 47 && str[i] < 58 && str[i] != '\0')
    {
      nb = ((nb * 10) + (str[i] - 48));
      i++;
    }
  i = 0;
  while ((str[i] < 48 || str[i] > 57) && str[i] != '\0')
    i++;
  nb = if_neg(nb, str, i);
  return (nb);
}
