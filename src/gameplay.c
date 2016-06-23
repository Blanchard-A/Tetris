/*
** gameplay.c for gameplay in /home/brunel_d/rendu/sem_2/syst_unix/PSU_
** 
** Made by axel brunel
** Login   <brunel_d@epitech.net>
** 
** Started on  Wed Mar 16 15:43:02 2016 axel brunel
** Last update Sat Mar 19 23:16:49 2016 axel brunel
*/

#include "tetris.h"

void	fall_tetri_tab_spe(int **tab, t_parameter *param, int j)
{
  int	i;

  while (j > 1)
    {
      i = param->map_x;
      while (i > 0)
        {
          if (tab[j - 1][i] > -1)
            {
              tab[j][i] = tab[j - 1][i];
              tab[j - 1][i] = 0;
            }
          i--;
        }
      j--;
    }
}

void	epur_map(int **tab, t_parameter *param)
{
  int	i;

  i = param->map_y;
  while (i > 1)
    {
      if (check_epur(tab, param, i) == 1)
        {
          fall_tetri_tab_spe(tab, param, i);
          param->line_suppr++;
          param->level = param->line_suppr / 10 + 1;
          if (param->level > 15)
            param->level = 15;
          i = param->map_y + 1;
          mvprintw(12, 5, "level = %d", param->level);
          mvprintw(16, 5, "line kick = %d", param->line_suppr);
	  param->score += 150;
        }
      i--;
    }
}


int	check_epur(int **tab, t_parameter *param, int i)
{
  int	j;

  j = 1;
  while (j < param->map_x + 1)
    {
      if (tab[i][j] == 0)
        return (0);
      j++;
    }
  return (1);
}

char	*get_move(char *ch, int **tab, t_parameter *param)
{
  void	(**table)(char *, int **, t_parameter *);
  int	i;
  char	*tab_get[5];
  char	*cpy;

  cpy = my_cpy(ch);
  table = malloc(sizeof(table) * 5);
  tab_func(table);
  tab_ch(tab_get, param);
  i = 0;
  ch = my_cpy(cpy);
  if (move_end(tab, param) == 0)
    {
      while (i < 5)
        {
          if (verif_cores_pt_func(cpy, tab_get[i]) == 1)
            {
              table[i](cpy, tab, param);
              return (ch);
            }
          i++;
        }
    }
  return (ch);
}

void	effect_turn(int **tab, char **tempo, t_parameter *param, int size_l)
{
  int	a;
  int	b;
  int	k;
  int	i;
  int	j;

  j = get_pos_start_turn_j(tab, param);
  i = get_pos_start_turn_i(tab, param);
  a = -1;
  i = i - size_l + 1;
  kick_last_form(tab, param);
  while (++a < size_l && (b = 0) > -6)
    {
      k = j;
      while (tempo[a][b])
        {
          if (tempo[a][b] == '*')
            {
              tab[i][k] = param->color_tempo;
            }
          b++;
          k++;
        }
      i++;
    }
}
