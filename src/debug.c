/*
** debug.c for tetris in /home/blanch_p/rendu/Semestre2/Unix/PSU_2015_tetris
** 
** Made by Alexandre Blanchard
** Login   <blanch_p@epitech.net>
** 
** Started on  Fri Mar 11 12:18:22 2016 Alexandre Blanchard
** Last update Sun Mar 20 14:18:47 2016 Alexandre Blanchard
*/

#include "tetris.h"

void	check_carac(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] == ' ')
      	my_printf("(space)");
      else if (str[i] == 27)
	my_printf("^E");
      else
	my_printf("%c", str[i]);
      i++;
    }
  my_printf("\n");
}

int	last_star(char *str)
{
  int	i;

  while (str[i] != '\0')
    {
      i++;
    }
  while (str[i] != '*')
    {
      i--;
    }
  return (i + 1);
}

int	bigger_name(t_tetriminos *minos)
{
  int	i;
  int	size;
  int	tmp;

  tmp = 0;
  size = my_strlen(minos->tetri[0].name);
  i = 0;
  while (i < minos->num)
    {
      tmp = my_strlen(minos->tetri[i].name);
      if (tmp > size)
	size = tmp;
      i++;
    }
  return (size);
}

char	**rempli_name(char **str, t_tetriminos *minos)
{
  int	i;

  i = 0;
  while (i < minos->num)
    {
      str[i] = minos->tetri[i].name;
      i++;
    }
  return (str);
}

int	my_strcmp_value(char *s1, char *s2)
{
  int	i;
  int	diff;

  i = 0;
  diff = 0;
  while (s1[i] == s2[i])
    {
      i++;
    }
  if (s1[i] == '.' && s1[i + 1] == 't')
    {
      return (0);
    }
  if (s2[i] == '.' && s2[i + 1] == 't')
    {
      return (-1);
    }

  diff = s1[i] - s2[i];
  return (diff);
}
