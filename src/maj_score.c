/*
** maj_score.c for maj_score in /home/brunel_d/rendu/sem_2/syst_unix/
** 
** Made by axel brunel
** Login   <brunel_d@epitech.net>
** 
** Started on  Sat Mar 19 22:23:22 2016 axel brunel
** Last update Sat Mar 19 23:13:48 2016 axel brunel
*/

#include "tetris.h"

void	my_putstr_fd(int fd, char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      my_putchar_fd(fd, str[i]);
      i++;
    }
}

void	MaJ_hscore(t_parameter *param)
{
  int	hscore;
  int	fd;

  hscore = get_hscore();
  if (param->score > hscore)
    {
      fd = open("high_score.txt", O_WRONLY);
      my_putnbr_fd(param->score, 0, fd);
      param->h_score = param->score;
      close(fd);
    }
}

void	else_boucle_tetris(t_parameter *param, t_tetriminos *minos, int **tab)
{
  epur_map(tab, param);
  change_val_tab(tab, param);
  add_new_tetri_tab(tab, &minos->tetri[param->next], param);
  if (check_end_fall(tab, param) == 0)
    end_tetris(param);
  param->next = get_next_form(minos);
  show_next(&minos->tetri[param->next], param);
}

void	adjust_struct_user(t_parameter *param)
{
  adjust_param_user(param->left, -1, 0);
  adjust_param_user(param->right, -1, 0);
  adjust_param_user(param->drop, -1, 0);
  adjust_param_user(param->turn, -1, 0);
  adjust_param_user(param->quit, -1, 0);
  adjust_param_user(param->pause, -1, 0);
}

void	press_key()
{
  char	poub[16];

  mode_spe(0);
  my_putstr("Press a key to start Tetris\n");
  read(0, poub, 16);
  mode_spe(1);
}
