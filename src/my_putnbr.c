/*
** my_putnbr.c for my_putnbr_lib in /home/celor_t/lib
** 
** Made by tristan celor
** Login   <celor_t@epitech.net>
** 
** Started on  Mon Oct 26 10:37:11 2015 tristan celor
** Last update Fri Mar 18 14:53:53 2016 axel brunel
*/

#include "tetris.h"

int	count_nbr_inter(int nb)
{
  int   count;

  count = 0;
  while (nb > 0)
    {
      nb = nb / 10;
      count = count + 1;
    }
  return (count);
}

void	econom(int n, char *str, int fd)
{
  if (n == 1)
    my_putchar('-');
  my_revstr(str);
  my_putstr_fd(fd, str);
}

int	my_putnbr_fd(int nb, int j, int fd)
{
  int   i;
  int   count;
  char  *str;
  int	n;

  n = 0;
  if (nb == 0)
    my_putchar_fd(fd, '0');
  if ((nb < 0) && (nb = -nb))
    n = 1;
  count = count_nbr_inter(nb);
  if ((str = malloc(sizeof(char) * (count + 1))) == NULL)
    return (-1);
  while (nb > 0)
    {
      i = nb % 10;
      str[j] = (i + 48);
      nb = nb / 10;
      j = j + 1;
    }
  str[j] = '\0';
  econom(n, str, fd);
  free(str);
  return (0);
}
