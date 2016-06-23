/*
** get_size.c for g_size in /home/brunel_d/rendu/sem_2/syst_unix/P
** 
** Made by axel brunel
** Login   <brunel_d@epitech.net>
** 
** Started on  Wed Mar 16 15:27:49 2016 axel brunel
** Last update Wed Mar 16 15:29:44 2016 axel brunel
*/

#include "tetris.h"

int	get_size_l(int **tab, t_parameter *param)
{
  int	i;
  int	j;

  j = param->map_x;
  while (j > 1)
    {
      i = 1;
      while (i < param->map_y)
        {
          if (tab[i][j] > 10)
            return (j + 1);
          i++;
        }
      j--;
    }
  return (0);
}

int	get_size_h(int **tab, t_parameter *param)
{
  int	i;
  int	j;

  i = 1;
  while (i < param->map_y)
    {
      j = 1;
      while (j < param->map_x)
        {
          if (tab[i][j] > 10)
            {
              return (i - 2);
            }
          j++;
        }
      i++;
    }
  return (0);
}


int	get_pos_start_turn_j(int **tab, t_parameter *param)
{
  int	i;
  int	j;

  j = 1;
  while (j < param->map_x)
    {
      i = 1;
      while (i < param->map_y)
        {
          if (tab[i][j] > 10)
            return (j);
          i++;
        }
      j++;
    }
  return (0);
}

int	get_pos_start_turn_i(int **tab, t_parameter *param)
{
  int	i;
  int	j;

  i = param->map_y;
  while (i > 1)
    {
      j = 1;
      while (j < param->map_x)
        {
          if (tab[i][j] > 10)
            {
              return (i - 1);
            }
          j++;
        }
      i--;
    }
  return (0);
}
