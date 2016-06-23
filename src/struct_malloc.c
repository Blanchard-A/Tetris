/*
** struct_malloc.c for tetris in /blanch_p/Semestre2/Unix/PSU_2015_tetris
** 
** Made by Alexandre Blanchard
** Login   <blanch_p@epitech.net>
** 
** Started on  Sun Mar 20 14:19:42 2016 Alexandre Blanchard
** Last update Sun Mar 20 14:20:44 2016 Alexandre Blanchard
*/

#include "tetris.h"

char	*my_realloc(char *str, int size)
{
  char	*tmp;
  int	i;

  i = 0;
  tmp = str;
  if ((str = malloc(size + 2)) == NULL)
    return (NULL);
  while (i < size - 1)
    {
      str[i] = tmp[i];
      i++;
    }
  str[size] = '\0';
  return (str);
}

char	**my_malloc(char **str, int height, int width)
{
  int	i;

  i = 0;
  str = malloc(sizeof(char *) * (height));
  while (i < height)
    {
      str[i] = malloc(sizeof(char) * width);
      i++;
    }
  return (str);
}
