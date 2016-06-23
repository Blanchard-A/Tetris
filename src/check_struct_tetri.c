/*
** check_struct_tetri.c for tetris in /blanch_p/Semestre2/Unix/PSU_2015_tetris/src
** 
** Made by Alexandre Blanchard
** Login   <blanch_p@epitech.net>
** 
** Started on  Tue Mar  8 12:41:19 2016 Alexandre Blanchard
** Last update Fri Mar 18 20:24:23 2016 Alexandre Blanchard
*/

#include "tetris.h"

int	my_strcmp_spe(char *src, char *cmp)
{
  int	i;
  int	j;

  i = my_strlen(src);
  j = 0;
  while (src[i] != '.')
    {
      i--;
    }
  while (cmp[j] != '\0')
    {
      if (src[i] != cmp[j])
	return (1);
      i++;
      j++;
    }
  if (src[i] == '\0')
    return (0);
  else
    return (1);
}
