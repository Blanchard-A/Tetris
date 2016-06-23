/*
** struct_check.c for tetris in /home/blanch_p/rendu/Semestre2/PSU_2015_tetris
** 
** Made by Alexandre Blanchard
** Login   <blanch_p@epitech.net>
** 
** Started on  Sun Mar 20 14:22:11 2016 Alexandre Blanchard
** Last update Sun Mar 20 14:40:51 2016 Alexandre Blanchard
*/

#include "tetris.h"

int		check_espace(char *s, int j)
{
  int		spaces;

  spaces = 0;
  while (s[j] != '\n')
    {
      if (s[j] == ' ')
        spaces++;
      if (s[j] != ' ')
        {
          return (0);
        }
      j++;
    }
  return (1);
}

t_tetri		*in_the_form(char *s, t_tetri *def, int elem)
{
  static int	i = 0;
  int		j;
  static int	spaces = 0;

  j = 0;
  while (s[j] != '\n' && j < def->width)
    {
      if (s[j + 1] == '\n' && j + 1 < def->width)
        spaces = spaces + ((def->width) - (j + 1));
      def->form[i] = s[j];
      i++;
      j++;
    }
  def->form[i] = '\n';
  i++;
  def->form[i] = '\0';
  if (elem >= 4 && i >= ((def->width + 1) * def->height) - spaces)
    {
      spaces = 0;
      i = 0;
    }
  return (def);
}

int		check_file(char *str)
{
  int		i;
  int		star;

  star = 0;
  i = 0;
  while (str[i] != '\n')
    {
      if ((str[i] < 48 || str[i] > 57) && str[i] != ' ')
        {
          return (-1);
        }
      i++;
    }
  while (str[i] != '\0')
    {
      if (str[i] == '*')
        star++;
      i++;
    }
  if (star == 0)
    return (-1);
  return (0);
}

int		check_in_map(t_tetri *def, t_parameter *param)
{
  if (def->height * 2 > param->map_y)
    {
      return (-1);
    }
  if (def->width * 2 > param->map_x)
    {
      return (-1);
    }
  return (0);
}
