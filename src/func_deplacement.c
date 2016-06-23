/*
** func_deplacement.c for fc_dep in /home/brunel_d/rendu/sem_2/syst_unix
** 
** Made by axel brunel
** Login   <brunel_d@epitech.net>
** 
** Started on  Wed Mar 16 15:13:07 2016 axel brunel
** Last update Sat Mar 19 23:25:51 2016 axel brunel
*/

#include "tetris.h"

void	pause_utilisateur(char *ch, UNUSED int **tab, t_parameter *param)
{
  ch[0] = 'v';
  ch[1] = 0;
  while (verif_cores_pt_func(ch, param->pause) != 1)
    {
      ch = my_getch();
    }
}

void	drop(UNUSED char *ch, int **tab, t_parameter *param)
{
  while (check_end_fall(tab, param) == 1)
    {
      fall_tetri_tab(tab, param);
    }
}

void	right(UNUSED char *ch, int **tab, t_parameter *param)
{
  int	i;
  int	j;

  i = param->map_x;
  if (check_right_fall(tab, param) == 1)
    {
      while (i > 1)
        {
          j = 1;
          while (j < param->map_y)
            {
              if (tab[j][i - 1] > 10)
                {
                  tab[j][i] = tab[j][i - 1];
                  tab[j][i - 1] = 0;
                }
              j++;
            }
          i--;
        }
    }
}

void	turn(UNUSED char *ch, int **tab, t_parameter *param)
{
  int	i;
  int	j;
  char	**tempo;
  int	size_l;

  j = get_pos_start_turn_j(tab, param);
  i = get_pos_start_turn_i(tab, param);
  size_l = get_size_l(tab, param) - j;
  get_tempo_color(tab, param);
  if (verif_possible_turn(tab, i, j, param) == 1)
    {
      tempo = get_tempo_form(tab, i, j, param);
      effect_turn(tab, tempo, param, size_l);
    }
}

void	left(UNUSED char *ch, int **tab, t_parameter *param)
{
  int	i;
  int	j;

  i = 1;
  if (check_left_fall(tab, param) == 1)
    {
      while (i < param->map_x)
        {
          j = 1;
          while (j < param->map_y)
            {
              if (tab[j][i + 1] > 10)
                {
                  tab[j][i] = tab[j][i + 1];
                  tab[j][i + 1] = 0;
                }
              j++;
            }
          i++;
        }
    }
}
