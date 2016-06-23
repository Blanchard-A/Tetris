/*
** print_debug.c for tetris in /home/blanch_p/Semestre2/Unix/PSU_2015_tetris
** 
** Made by Alexandre Blanchard
** Login   <blanch_p@epitech.net>
** 
** Started on  Sun Mar 20 14:11:40 2016 Alexandre Blanchard
** Last update Mon Mar 21 11:13:40 2016 Alexandre Blanchard
*/

#include "tetris.h"

void	print_key(t_parameter *param)
{
  my_printf("Key Left : ");
  check_carac(param->left);
  my_printf("Key Right : ");
  check_carac(param->right);
  my_printf("Key Turn : ");
  check_carac(param->turn);
  my_printf("Key Drop : ");
  check_carac(param->drop);
  my_printf("Key Quit : ");
  check_carac(param->quit);
  my_printf("Key Pause : ");
  check_carac(param->pause);
  my_printf("Next : ");
  if (param->hide_next == 0)
    my_printf("Yes\n");
  if (param->hide_next == 1)
    my_printf("No\n");
  my_printf("Level : %i\n", param->level);
  my_printf("Size : %i*%i\n", param->map_y, param->map_x);
}

void	print_form(t_tetriminos *minos, int j)
{
  int	i;
  int	k;
  int	last;

  k = 0;
  i = 0;
  while (minos->tetri[j].form2d[i] != NULL)
    {
      k = 0;
      last = last_star(minos->tetri[j].form2d[i]);
      while (k < last)
	{
          my_printf("%c", minos->tetri[j].form2d[i][k]);
          k++;
        }
      my_printf("\n");
      i++;
    }
}

void	check_error_print(t_tetriminos *minos, int i)
{
  if (minos->tetri[i].error == 1 || minos->tetri[i].in_map == 1)
    {
      print_name(minos->tetri[i].name);
      my_printf("Error\n");
    }
  else
    {
      print_name(minos->tetri[i].name);
      my_printf("Size : %i*%i : ", minos->tetri[i].width,
                minos->tetri[i].height);
      my_printf("Color : %i :\n", minos->tetri[i].color);
      print_form(minos, i);
    }
}

void	print_tetri(t_tetriminos *minos, char **tab)
{
  int	i;
  int	j;

  j = 0;
  i = 0;
  my_printf("Tetriminos : %i\n", minos->num);
  while (tab[j] != NULL)
    {
      i = 0;
      while (i < minos->num)
        {
          if (compare_str(minos->tetri[i].name, tab[j]) == 1)
            {
              check_error_print(minos, i);
            }
          i++;
        }
      j++;
    }
}

void	debug_mode(t_tetriminos *minos, t_parameter *param)
{
  char	**tab;

  endwin();
  my_printf("*** DEBUG MODE ***\n");
  print_key(param);
  tab = in_order(minos);
  print_tetri(minos, tab);
}
