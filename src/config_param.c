/*
** config_param.c for cfg_param in /home/brunel_d/rendu/sem_2/syst_un
** 
** Made by axel brunel
** Login   <brunel_d@epitech.net>
** 
** Started on  Wed Mar 16 15:19:32 2016 axel brunel
** Last update Sun Mar 20 00:55:09 2016 axel brunel
*/

#include "tetris.h"

void	param_size_base(t_parameter *param)
{
  param->map_x = 10;
  param->map_y = 20;
  param->hide_next = 0;
  param->line_suppr = 0;
  param->score = 0;
}

void	config_param(t_parameter *param, char *const envp[])
{
  int	err;
  char	*keypad;

  if (setupterm(my_termname(envp), 1, &err) == -1)
    exit(-1);
  if ((keypad = tigetstr("smkx")) != NULL)
    {
      if (keypad == NULL)
	exit(-1);
    }
  param->level = 1;
  param->left = tigetstr("kcub1");
  param->right = tigetstr("kcuf1");
  param->turn = tigetstr("kcuu1");
  param->drop = tigetstr("kcud1");
  param->quit = malloc(sizeof(char) * 20);
  my_put_zero(param->quit, 20);
  param->quit[0] = 'q';
  param->pause = malloc(sizeof(char) * 20);
  my_put_zero(param->pause, 20);
  param->pause[0] = ' ';
  param_size_base(param);
  param->h_score = get_hscore();
}

char	*my_termname(char *const envp[])
{
  char	*str;
  int	i;
  int	j;
  char	*name;

  if ((str = get_termname_env(envp)) == NULL)
    exit(-1);
  i = 4;
  j = 0;
  while (str[++i])
    {
      j++;
    }
  if ((name = malloc(sizeof(char) * (j + 1))) == NULL)
    return (NULL);
  i = 5;
  j = 0;
  while (str[i])
    {
      name[j] = str[i];
      j++;
      i++;
    }
  name[j] = '\0';
  return (name);
}

char	*get_termname_env(char *const envp[])
{
  int	i;

  i = 0;
  while (envp[i] != NULL)
    {
      if (compare_str("TERM=", envp[i]) == 1)
        return (envp[i]);
      i++;
    }
  return (NULL);
}

int	compare_str(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i])
    {
      if (s1[i] != s2[i])
        return (0);
      i++;
    }
  return (1);
}
