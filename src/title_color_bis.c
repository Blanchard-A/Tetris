/*
** title_color_bis.c for title_bis in /home/brunel_d/rendu/sem_2/sy
** 
** Made by axel brunel
** Login   <brunel_d@epitech.net>
** 
** Started on  Wed Mar 16 14:30:36 2016 axel brunel
** Last update Wed Mar 16 14:31:06 2016 axel brunel
*/

#include "tetris.h"

void	put_I()
{
  attron(COLOR_PAIR(7));
  mvprintw(3, 20, "*");
  mvprintw(5, 20, "*");
  mvprintw(6, 20, "*");
  mvprintw(7, 20, "*");
  attroff(COLOR_PAIR(7));
}
