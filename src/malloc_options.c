/*
** malloc_options.c for m_a in /home/brunel_d/rendu/sem_2/syst_unix/PSU_
** 
** Made by axel brunel
** Login   <brunel_d@epitech.net>
** 
** Started on  Sat Mar 19 22:25:42 2016 axel brunel
** Last update Sat Mar 19 23:12:13 2016 axel brunel
*/

#include "tetris.h"

void	put_in_options(char *mot, char *str)
{
  int	i;

  i = 0;
  my_put_zero(str, 20);
  while (mot[i])
    {
      str[i] = mot[i];
      i++;
    }
}

char	**get_malloc_options(char **options)
{
  options = malloc(sizeof(char *) * 20);
  options[0] = malloc(sizeof(char) * 20);
  options[1] = malloc(sizeof(char) * 20);
  options[2] = malloc(sizeof(char) * 20);
  options[3] = malloc(sizeof(char) * 20);
  options[4] = malloc(sizeof(char) * 20);
  options[5] = malloc(sizeof(char) * 20);
  options[6] = malloc(sizeof(char) * 20);
  options[7] = malloc(sizeof(char) * 20);
  options[8] = malloc(sizeof(char) * 20);
  options[9] = malloc(sizeof(char) * 20);
  options[10] = malloc(sizeof(char) * 20);
  options[11] = malloc(sizeof(char) * 20);
  options[12] = malloc(sizeof(char) * 20);
  options[13] = malloc(sizeof(char) * 20);
  options[14] = malloc(sizeof(char) * 20);
  options[15] = malloc(sizeof(char) * 20);
  options[16] = malloc(sizeof(char) * 20);
  options[17] = malloc(sizeof(char) * 20);
  options[18] = malloc(sizeof(char) * 20);
  options[19] = malloc(sizeof(char) * 20);
  return (options);
}

char	**possible_option()
{
  char	**options;

  options = NULL;
  options = get_malloc_options(options);
  put_in_options("-kp", options[0]);
  put_in_options("-kq", options[1]);
  put_in_options("-kd", options[2]);
  put_in_options("-kl", options[3]);
  put_in_options("-kt", options[4]);
  put_in_options("-kr", options[5]);
  put_in_options("--key-right=", options[11]);
  put_in_options("--key-left=", options[7]);
  put_in_options("--key-turn=", options[8]);
  put_in_options("--level=", options[9]);
  put_in_options("--key-drop=", options[10]);
  put_in_options("-l", options[6]);
  put_in_options("--key-quit=", options[12]);
  put_in_options("--help", options[15]);
  put_in_options("--key-pause=", options[14]);
  put_in_options("--map-size=", options[13]);
  put_in_options("-w", options[16]);
  put_in_options("--without-next", options[17]);
  put_in_options("-d", options[18]);
  put_in_options("--debug", options[19]);
  return (options);
}

char	*recup_arg(char *str, char *tmp)
{
  int	i;

  i = 0;
  my_put_zero(tmp, 20);
  while (str[i] != '=' && str[i] != '\0')
    {
      tmp[i] = str[i];
      i++;
    }
  tmp[i] = str[i];
  return (tmp);
}

int	get_j_to_options(char **options, char *str)
{
  char	*tmp;
  int	nb;
  int	j;

  tmp = malloc(sizeof(char) * 20);
  tmp = recup_arg(str, tmp);
  nb = 0;
  j = 0;
  while (nb == 0)
    {
      nb = compare_str(tmp, options[j]);
      j++;
    }
  free(tmp);
  return (j - 1);
}
