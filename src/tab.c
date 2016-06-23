/*
** tab.c for tab in /home/blanch_p/rendu/Semestre2/Unix/PSU_2015_tetris/src
** 
** Made by Alexandre Blanchard
** Login   <blanch_p@epitech.net>
** 
** Started on  Mon Feb 29 14:33:07 2016 Alexandre Blanchard
** Last update Sat Mar 19 23:32:53 2016 axel brunel
*/

#include "tetris.h"

void	show_map(int **tab)
{
  int	i;
  int	j;

  i = 0;
  while (i < 22)
    {
      j = 0;
      while (j < 12)
	{
	  my_printf("%d ", tab[i][j]);
	  j++;
	}
      i++;
      my_printf("\n");
    }
}

int	**malloc_tab(int **tab, t_parameter *param)
{
  int	i;

  i = 0;
  tab = malloc(sizeof(int *) * (param->map_y + 2));
  while (i < param->map_y + 2)
    {
      tab[i] = malloc(sizeof(int) * (param->map_x + 2));
      i++;
    }
  return (tab);
}

int	**tab_in_frame(int **tab, t_parameter *param)
{
  int	i;
  int	j;

  j = 0;
  while (j < param->map_y + 2)
    {
      i = 0;
      while (i < param->map_x + 2)
	{
	  if (j == 0 || j == (param->map_y + 1))
	    {
	      tab[j][i] = -2;
	    }
	  else if ((j != 0 || j != (param->map_y + 1)) &&
		   (i == 0 || i == (param->map_x + 1)))
	    {
	      tab[j][i] = -1;
	    }
	  else
	    tab[j][i] = 0;
	  i++;
	}
      j++;
    }
  return (tab);
}

int	**get_tab(int **tab, t_parameter *param)
{
  tab = malloc_tab(tab, param);
  tab = tab_in_frame(tab, param);
  return (tab);
}
