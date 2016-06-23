/*
** verif_deplacement.c for verif_depl in /home/brunel_d/rendu/sem_2/sys
** 
** Made by axel brunel
** Login   <brunel_d@epitech.net>
** 
** Started on  Wed Mar 16 14:36:46 2016 axel brunel
** Last update Wed Mar 16 14:40:43 2016 axel brunel
*/

#include "tetris.h"

int	check_left_deplacement(int **tab, t_parameter *param, int i)
{
  int	j;

  j = param->map_x;
  while (j > -1)
    {
      if (tab[i][j + 1] > 10 && tab[i][j] < 10 && tab[i][j] != 0)
        {
          return (0);
        }
      j--;
    }
  return (1);
}

int	check_right_deplacement(int **tab, t_parameter *param, int i)
{
  int	j;

  j = 0;
  while (j < param->map_x + 2)
    {
      if (tab[i][j - 1] > 10 && tab[i][j] < 10 && tab[i][j] != 0)
        {
          return (0);
        }
      j++;
    }
  return (1);
}

int	check_left_fall(int **tab, t_parameter *param)
{
  int	i;

  i = param->map_y + 1;
  while (i > 0)
    {
      if (check_left_deplacement(tab, param, i) == 0)
        {
          return (0);
        }
      i--;
    }
  return (1);
}

int	check_right_fall(int **tab, t_parameter *param)
{
  int	i;

  i = 1;
  while (i < param->map_y + 1)
    {
      if (check_right_deplacement(tab, param, i) == 0)
        {
          return (0);
        }
      i++;
    }
  return (1);
}
