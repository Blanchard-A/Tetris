/*
** put_interface.c for put_interface in /home/brunel_d/rendu/
** 
** Made by axel brunel
** Login   <brunel_d@epitech.net>
** 
** Started on  Wed Mar 16 14:32:21 2016 axel brunel
** Last update Sun Mar 20 18:44:23 2016 axel brunel
*/

#include "tetris.h"

void	put_interface(t_parameter *param)
{
  put_T();
  put_E();
  put_T_bis();
  put_R();
  put_I();
  put_S();
  put_cadre_score();
  mvprintw(12, 5, "level = %d", param->level);
  mvprintw(16, 5, "line kick = %d", param->line_suppr);
  mvprintw(20, 5, "score = %d", param->score);
  mvprintw(24, 5, "High score = %d", param->h_score);
}

void	put_cadre_score()
{
  int	x;
  int	y;

  x = 10;
  while (x < 35)
    {
      y = 3;
      while (y < 28)
        {
          if (x == 10 || x == 34)
            mvprintw(x, y, "-");
          else if (y == 3 || y == 27)
            mvprintw(x, y, "|");
          y++;
        }
      x++;
    }
}

void	put_next()
{
  attron(COLOR_PAIR(3));
  mvprintw(2, 30, "NEXT ===>");
  attroff(COLOR_PAIR(3));
}

void	verif_dimension(t_parameter *param)
{
  int	col;
  int	raw;
  int	raw_base;
  int	col_base;

  raw_base = 36;
  col_base = 35 + param->map_x + 2 + 18;
  if (param->map_y + 10 > raw_base)
    raw_base = param->map_y + 13;
  col = tigetnum("cols");
  raw = tigetnum("lines");
  if (raw < raw_base || col < col_base)
    {
      endwin();
      my_putstr("Fenetre trop petite...\n");
      exit(-1);
    }
}

void	config_term(t_parameter *param)
{
  param->line_suppr = 10 * param->level - 10;
  newterm(termname(), stderr, stdin);
  curs_set(0);
  set_escdelay(0);
  keypad(stdscr, TRUE);
  noecho();
  start_color();
  init_pair(1, COLOR_CYAN, COLOR_BLACK);
  init_pair(2, COLOR_RED, COLOR_BLACK);
  init_pair(3, COLOR_GREEN, COLOR_BLACK);
  init_pair(4, COLOR_YELLOW, COLOR_BLACK);
  init_pair(5, COLOR_BLUE, COLOR_BLACK);
  init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
  init_pair(7, COLOR_CYAN, COLOR_BLACK);
  init_pair(8, COLOR_WHITE, COLOR_BLACK);
  init_pair(9, COLOR_GREEN, COLOR_BLACK);
  put_interface(param);
  verif_dimension(param);
}
