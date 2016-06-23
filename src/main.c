/*
** main.c for main in /home/brunel_d/rendu/sem_2/syst_unix/tetris/src
** 
** Made by axel brunel
** Login   <brunel_d@epitech.net>
** 
** Started on  Mon Feb 29 12:18:44 2016 axel brunel
** Last update Sun Mar 20 19:14:39 2016 axel brunel
*/

#include "tetris.h"

void	boucle_tetris(t_parameter *param, t_tetriminos *minos, int **tab)
{
  char	*ch;

  put_interface(param);
  show_tetris_map(tab, param, 9);
  ch = my_getch();
  while (verif_cores_pt_func(ch, "q") != 1)
    {
      mode(2, param);
      show_next(&minos->tetri[param->next], param);
      ch = my_getch();
      if (check_end_fall(tab, param) == 1)
	{
	  fall_tetri_tab(tab, param);
	  ch = get_move(ch, tab, param);
	}
      else
	else_boucle_tetris(param, minos, tab);
      MaJ_hscore(param);
      put_interface(param);
      show_tetris_map(tab, param, 9);
      refresh();
    }
  mode(1, param);
  endwin();
}

void	adjust_param_user(char *str, int i, int j)
{
  char	*tmp;

  while (str[++i])
    {
      if (str[i] == 27)
	return ;
    }
  tmp = malloc(sizeof(char) * 20);
  my_put_zero(tmp, 20);
  i = -1;
  while (str[++i])
    tmp[i] = str[i];
  i = 0;
  while (tmp[i])
    {
      if (tmp[i] == '^' && tmp[i + 1] == 'E' && (i += 2) > -6)
	str[j++] = 27;
      else
	str[j++] = tmp[i++];
    }
  while (str[j])
      str[j++] = 0;
  free(tmp);
}

int	get_hscore()
{
  int	fd;
  char	buf[20];

  if ((fd = open("high_score.txt", O_RDONLY)) == -1)
    {
      close(fd);
      fd = open("high_score.txt", O_CREAT, 0777);
    }
  read(fd, buf, 20);
  close(fd);
  return (my_getnbr(buf));
}

void	all_rest(t_parameter *param, t_tetriminos *minos, int **tab)
{
  config_term(param);
  add_new_tetri_tab(tab, &minos->tetri[0], param);
  param->next = get_next_form(minos);
  mode(0, param);
  boucle_tetris(param, minos, tab);
}

int		main(int ac, char **av, char *const envp[])
{
  t_parameter	param;
  t_tetriminos	minos;
  int		**tab;

  if (envp[0] == NULL)
    {
      my_printf("Error, impossible to start without env\n");
      return (-1);
    }
  config_param(&param, envp);
  if (ac > 1)
    get_option(&param, av);
  tab = NULL;
  tab = get_tab(tab, &param);
  minos.tetri = create_struct(&minos, &param, 0);
  adjust_struct_user(&param);
  if (param.debug_mode == 1)
    {
      debug_mode(&minos, &param);
      press_key();
    }
  if (minos.num > 0 && check_all_good(&minos) == 1)
    all_rest(&param, &minos, tab);
  return (0);
}
