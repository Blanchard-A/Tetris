/*
** title_color.c for title in /home/brunel_d/rendu/sem_2/syst_u
** 
** Made by axel brunel
** Login   <brunel_d@epitech.net>
** 
** Started on  Wed Mar 16 14:28:12 2016 axel brunel
** Last update Wed Mar 16 14:30:29 2016 axel brunel
*/

#include "tetris.h"

void	put_T()
{
  attron(COLOR_PAIR(2));
  mvprintw(3, 4, "*");
  mvprintw(3, 5, "*");
  mvprintw(3, 6, "*");
  mvprintw(4, 5, "*");
  mvprintw(5, 5, "*");
  mvprintw(6, 5, "*");
  mvprintw(7, 5, "*");
  attroff(COLOR_PAIR(2));
}

void	put_R()
{
  attron(COLOR_PAIR(3));
  mvprintw(3, 16, "*");
  mvprintw(4, 16, "*");
  mvprintw(5, 16, "*");
  mvprintw(6, 16, "*");
  mvprintw(7, 16, "*");
  mvprintw(3, 17, "*");
  mvprintw(3, 18, "*");
  mvprintw(4, 18, "*");
  mvprintw(5, 17, "*");
  mvprintw(6, 18, "*");
  mvprintw(7, 18, "*");
  attroff(COLOR_PAIR(3));
}

void	put_T_bis()
{
  attron(COLOR_PAIR(4));
  mvprintw(3, 12, "*");
  mvprintw(3, 13, "*");
  mvprintw(3, 14, "*");
  mvprintw(4, 13, "*");
  mvprintw(5, 13, "*");
  mvprintw(6, 13, "*");
  mvprintw(7, 13, "*");
  attroff(COLOR_PAIR(4));
}

void	put_E()
{
  attron(COLOR_PAIR(5));
  mvprintw(3, 8, "*");
  mvprintw(3, 9, "*");
  mvprintw(3, 10, "*");
  mvprintw(4, 8, "*");
  mvprintw(5, 8, "*");
  mvprintw(5, 9, "*");
  mvprintw(6, 8, "*");
  mvprintw(7, 8, "*");
  mvprintw(7, 9, "*");
  mvprintw(7, 10, "*");
  attroff(COLOR_PAIR(5));
}

void	put_S()
{
  attron(COLOR_PAIR(6));
  mvprintw(3, 22, "*");
  mvprintw(3, 23, "*");
  mvprintw(3, 24, "*");
  mvprintw(4, 22, "*");
  mvprintw(5, 22, "*");
  mvprintw(5, 23, "*");
  mvprintw(5, 24, "*");
  mvprintw(6, 24, "*");
  mvprintw(7, 22, "*");
  mvprintw(7, 23, "*");
  mvprintw(7, 24, "*");
  attroff(COLOR_PAIR(6));
}
