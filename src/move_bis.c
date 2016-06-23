/*
** move_bis.c for move_b in /home/brunel_d/rendu/sem_2/syst_unix/PSU_2
** 
** Made by axel brunel
** Login   <brunel_d@epitech.net>
** 
** Started on  Thu Mar 17 11:15:44 2016 axel brunel
** Last update Sat Mar 19 22:48:40 2016 axel brunel
*/

#include "tetris.h"

void	kick_last_form(int **tab, t_parameter *param)
{
  int	i;
  int	j;

  i = 0;
  while (i < param->map_y)
    {
      j = 0;
      while (j < param->map_x)
        {
          if (tab[i][j] > 10)
            {
              tab[i][j] = 0;
            }
          j++;
        }
      i++;
    }
}

void	get_tempo_color(int **tab, t_parameter *param)
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
            param->color_tempo = tab[i][j];
          j++;
        }
      i++;
    }
}

void	my_put_zero(char *str, int i)
{
  int	j;

  j = 0;
  while (j < i)
    {
      str[j] = 0;
      j++;
    }
}

void	put_tempo_form(char **tempo, int **tab, int i, t_parameter *param)
{
  int	j;
  int	k;
  int	l;
  int	size_h;
  int	size_l;

  j = get_pos_start_turn_j(tab, param);
  size_h = i - get_size_h(tab, param);
  size_l = get_size_l(tab, param) - j;
  k = 0;
  i++;
  while (k < size_l)
    {
      l = 0;
      while (l < size_h)
        {
          if (tab[i--][j] > 10)
            tempo[k][l++] = '*';
          else
            tempo[k][l++] = ' ';
        }
      i = i + size_h;
      tempo[k++][l] = '\0';
      j++;
    }
}

char	**get_tempo_form(int **tab, int i, int j, t_parameter *param)
{
  int	size_h;
  int	size_l;
  char	**tempo;
  int	k;

  k = 0;
  size_h = i - get_size_h(tab, param);
  size_l = get_size_l(tab, param) - j;
  tempo = malloc(sizeof(char *) * (size_l + 1));
  while (k < size_l)
    {
      tempo[k] = malloc(sizeof(char) * (size_h + 1));
      k++;
    }
  tempo[k] = NULL;
  put_tempo_form(tempo, tab, i, param);
  return (tempo);
}
