/*
** show_tetris_map.c for stm in /home/brunel_d/rendu/sem_2/syst_unix/PS
** 
** Made by axel brunel
** Login   <brunel_d@epitech.net>
** 
** Started on  Sat Mar 19 22:21:08 2016 axel brunel
** Last update Sat Mar 19 22:22:40 2016 axel brunel
*/

#include "tetris.h"

void	show_tetris_map(int **tab, t_parameter *param, int x)
{
  int	i;
  int	j;
  int	y;

  i = -1;
  while (++i < param->map_y + 2 && ++x > 0 && (y = 35) > 0 && (j = -1) > -4)
    {
      while (++j < param->map_x + 2)
        {
          if (tab[i][j] == -2)
            mvprintw(x, y++, "-");
          else if (tab[i][j] == -1)
            mvprintw(x, y++, "|");
          else if (tab[i][j] == 0)
            mvprintw(x, y++, " ");
          else
            {
              if (tab[i][j] < 10 && tab[i][j] > 0)
                print_color(tab[i][j], x, y++);
              else if (tab[i][j] > 10)
                print_color(tab[i][j] - 10, x, y++);
            }
        }
      printw("\n");
    }
}

void	fall_tetri_tab(int **tab, t_parameter *param)
{
  int	i;
  int	j;

  j = param->map_y;
  while (j > 1)
    {
      i = param->map_x;
      while (i > 0)
        {
          if (tab[j - 1][i] > 10)
            {
              tab[j][i] = tab[j - 1][i];
              tab[j - 1][i] = 0;
            }
          i--;
        }
      j--;
    }
}


void	add_new_tetri_tab(int **tab, t_tetri *tetri, t_parameter *param)
{
  int	i;
  int	j;
  int	k;
  int	l;

  i = 0;
  l = 1;
  while (tetri->form2d[i] != NULL)
    {
      k = param->map_x / 2;
      j = 0;
      while (tetri->form2d[i][j])
        {
          if (tetri->form2d[i][j] == '*')
            {
              tab[l][k] = tetri->color + 10;
            }
          k++;
          j++;
        }
      i++;
      l++;
    }
  param->score += 10;
}

void	end_tetris(t_parameter *param)
{
  mode(1, param);
  endwin();
  my_printf("Game END, YOU LOOSE, your score is %d\n", (param->score - 10));
  exit(0);
}

void	my_putchar_fd(int fd, char c)
{
  write(fd, &c, 1);
}
