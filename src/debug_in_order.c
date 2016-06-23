/*
** debug_in_order.c for tetris in /blanch_p/Semestre2/Unix/PSU_2015_tetris
** 
** Made by Alexandre Blanchard
** Login   <blanch_p@epitech.net>
** 
** Started on  Sun Mar 20 14:16:45 2016 Alexandre Blanchard
** Last update Sun Mar 20 14:40:17 2016 Alexandre Blanchard
*/

#include "tetris.h"

char	**tri_tab(char **tab, int size)
{
  int	i;
  int	changes;
  char	*tmp;

  changes = 1;
  tmp = malloc(sizeof(char) * (size + 1));
  while (changes != 0)
    {
      i = 0;
      changes = 0;
      while (tab[i + 1] != NULL)
        {
          if (my_strcmp_value(tab[i], tab[i + 1]) > 0)
            {
              tmp = tab[i];
              tab[i] = tab[i + 1];
              tab[i + 1] = tmp;
              changes++;
            }
          i++;
        }
    }
  return (tab);
}

char	**in_order(t_tetriminos *minos)
{
  char	**str;
  int	size;
  int	i;

  size = bigger_name(minos);

  i = 0;
  str = malloc(sizeof(char *) * (minos->num + 1));
  while (i < minos->num)
    {
      str[i] = malloc(sizeof(char) * size + 1);
      i++;
    }
  str[i] = NULL;
  str = rempli_name(str, minos);
  str = tri_tab(str, size);
  return (str);
}
