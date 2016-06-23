/*
** fct.c for tetris in /home/blanch_p/rendu/Semestre2/Unix/PSU_2015_tetris/src
** 
** Made by Alexandre Blanchard
** Login   <blanch_p@epitech.net>
** 
** Started on  Mon Mar 21 11:09:29 2016 Alexandre Blanchard
** Last update Mon Mar 21 11:14:11 2016 Alexandre Blanchard
*/

#include "tetris.h"

void	print_name(char *str)
{
  int	i;

  i = 0;
  my_printf("Tetriminos : Name ");
  while (str[i] != '.')
    {
      my_printf("%c", str[i]);
      i++;
    }
  my_printf(" : ");
}
