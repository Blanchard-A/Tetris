/*
** next.c for next in /home/brunel_d/rendu/sem_2/syst_unix/PSU_2015_tetris
** 
** Made by axel brunel
** Login   <brunel_d@epitech.net>
** 
** Started on  Wed Mar 16 15:24:31 2016 axel brunel
** Last update Sat Mar 19 22:52:36 2016 axel brunel
*/

#include "tetris.h"

void	clear_next(t_parameter *param)
{
  int	x;
  int	y;

  x = 0;
  while (x < 80)
    {
      y = param->map_x + 38;
      mvprintw(x++, y, "                                     ");
    }
}

void	print_color(int color, int x, int y)
{
  attron(COLOR_PAIR(color));
  mvprintw(x, y, "*");
  attroff(COLOR_PAIR(color));
}

void	show_next(t_tetri *tetri, t_parameter *param)
{
  int	i;
  int	j;
  int	x;
  int	y;

  x = 0;
  i = -1;
  clear_next(param);
  if (param->hide_next == 0)
    {
      put_next();
      mvprintw(x++, (39 + param->map_x), "______________");
      while (tetri->form2d[++i] != NULL && (j = 0) > -1)
        {
          y = param->map_x + 38;
          mvprintw(x, y, "|");
          while (tetri->form2d[i][j] && y++ > 0)
            {
              if (tetri->form2d[i][j++] == '*')
		  print_color(tetri->color, x, y);
            }
          mvprintw(x++, param->map_x + 39 + 14, "|");
        }
      mvprintw(x++, (39 + param->map_x), "______________");
    }
}

int	get_next_form(t_tetriminos *minos)
{
  int	cpt;
  srand(time(0) * getpid());
  cpt = rand() % minos->num;
  while (minos->tetri[cpt].error != 0 || minos->tetri[cpt].in_map != 0)
    {
      cpt = rand() % minos->num;
    }
  return (cpt);
}
