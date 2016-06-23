/*
** divers_checks.c for d_c in /home/brunel_d/rendu/sem_2/syst_unix/PSU_20
** 
** Made by axel brunel
** Login   <brunel_d@epitech.net>
** 
** Started on  Wed Mar 16 15:32:46 2016 axel brunel
** Last update Sat Mar 19 16:33:26 2016 axel brunel
*/

#include "tetris.h"


int	check_column(int **tab, t_parameter *param, int i)
{
  int	j;

  j = 1;
  while (j < param->map_y + 2)
    {
      if (tab[j - 1][i] > 10 && tab[j][i] < 10 && tab[j][i] != 0)
        {
          return (0);
        }
      j++;
    }
  return (1);
}

int	check_end_fall(int **tab, t_parameter *param)
{
  int	i;

  i = 1;
  while (i < param->map_x + 1)
    {
      if (check_column(tab, param, i) == 0)
        {
          return (0);
        }
      i++;
    }
  return (1);
}

int	verif_droite(int **tab, t_parameter *param)
{
  int	i;
  int	j;

  i = 1;
  j = param->map_x;
  while (i < param->map_y)
    {
      if (tab[i][j] > 10)
        return (0);
      i++;
    }
  return (1);
}


int	verif_possible_turn(int **tab, int i, int j, t_parameter *param)
{
  int	size_h;
  int	size_l;
  int	k;

  size_l = get_size_l(tab, param) - j;
  if (verif_droite(tab, param) == 0)
    return (0);
  if (size_l < 0)
    size_l = -size_l;
  while (size_l > 0 && (k = j) > -676)
    {
      size_h = i - get_size_h(tab, param);
      while (size_h > 0)
        {
          if (tab[i][k] > 10 && k == 1)
            return (0);
          if (tab[i][k] < 10 && tab[i][k] != 0)
            return (0);
          k++;
          size_h--;
        }
      i++;
      size_l--;
    }
  return (1);
}
