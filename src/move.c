/*
** move.c for move in /home/brunel_d/rendu/sem_2/syst_unix/PSU_2015_tetris/
** 
** Made by axel brunel
** Login   <brunel_d@epitech.net>
** 
** Started on  Thu Mar 17 11:08:57 2016 axel brunel
** Last update Sat Mar 19 23:16:11 2016 axel brunel
*/

#include "tetris.h"

char	*my_getch()
{
  char	*tmp;
  char	*poub;

  poub = malloc(sizeof(char) * 16);
  tmp = malloc(sizeof(char) * 16);
  my_put_zero(tmp, 16);
  if ((read(0, tmp, 16) > 0))
    {
      return (tmp);
    }
  else
    {
      my_put_zero(poub, 16);
      poub[1] = 100;
      poub[0] = 10;
      return (poub);
    }
  return (tmp);
}

void	change_val_tab(int **tab, t_parameter *param)
{
  int	i;
  int	j;

  i = 0;
  while (i < param->map_y + 1)
    {
      j = 0;
      while (j < param->map_x + 1)
        {
          if (tab[i][j] > 10)
            tab[i][j] = tab[i][j] - 10;
          j++;
        }
      i++;
    }
}

int	move_end(int **tab, t_parameter *param)
{
  int	i;
  int	j;

  i = param->map_y;
  j = 1;
  while (j < param->map_x)
    {
      if (tab[i][j] > 10)
        return (1);
      j++;
    }
  return (0);
}


int	verif_cores_pt_func(char *ch, char *tab_get)
{
  int	i;

  i = 0;
  while (ch[i] != 0)
    {
      if (ch[i] != tab_get[i])
        return (0);
      i++;
    }
  if (ch[i] != tab_get[i])
    return (0);
  return (1);
}

char	*my_cpy(char *str)
{
  int	i;
  char	*cpy;

  i = 0;
  while (str[i] != 0)
    i++;
  cpy = malloc(sizeof(char) * (i + 1));
  i = 0;
  while (str[i] != 0)
    {
      cpy[i] = str[i];
      i++;
    }
  cpy[i] = '\0';
  return (cpy);
}
