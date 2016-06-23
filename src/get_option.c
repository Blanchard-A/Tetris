/*
** get_option.c for get_options in /home/brunel_d/rendu
** 
** Made by axel brunel
** Login   <brunel_d@epitech.net>
** 
** Started on  Mon Mar 14 14:01:43 2016 axel brunel
** Last update Sat Mar 19 23:27:34 2016 axel brunel
*/

#include "tetris.h"

void	exit_error(char **av, int i)
{
  my_printf("Invalid option with [%s]\nTry '%s --help'\n",
	 av[i], av[0]);
  exit(-1);
}

int	option_error(char **av, char **options)
{
  int	j;
  int	nb;
  int	i;
  char	*tmp;

  i = 0;
  tmp = malloc(sizeof(char) * 20);
  while (av[++i] != NULL && (j = -1) > -6 && (nb = 0) > -6)
    {
      tmp = recup_arg(av[i], tmp);
      while (++j < 20 && nb == 0)
	nb = compare_str(options[j], tmp);
      if (nb == 0)
	exit_error(av, i);
      if (j < 8 && i++)
	{
	  if (av[i] == NULL)
	    exit_error(av, i);
	}
    }
  free(tmp);
  return (0);
}

void	get_option(t_parameter *param, char **av)
{
  char	**options;

  param->debug_mode = 0;
  options = possible_option();
  option_error(av, options);
  affect_options(options, param, av);
}
