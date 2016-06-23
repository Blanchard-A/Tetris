/*
** truekey.c for truekey in /home/brunel_d/rendu/sem_2/syst_unix/PSU_20
** 
** Made by axel brunel
** Login   <brunel_d@epitech.net>
** 
** Started on  Sat Mar 19 22:27:46 2016 axel brunel
** Last update Sat Mar 19 22:29:11 2016 axel brunel
*/

#include "tetris.h"

void	get_truekey(char *truekey, char *key)
{
  int	i;
  int	j;

  j = 0;
  i = 0;
  while (key[i] != '=' && key[i] != '\0')
    {
      i++;
    }
  i++;
  while (key[i])
    {
      truekey[j] = key[i];
      j++;
      i++;
    }
}

void	poub_zero(char *nb1, char *nb2)
{
  my_put_zero(nb1, 20);
  my_put_zero(nb2, 20);
}

void	resize_map(t_parameter *param, char *truekey, int i, int j)
{
  char	*nb1;
  char	*nb2;

  while (truekey[++i])
    {
      if ((truekey[i] < 48 || truekey[i] > 57))
        {
          if (truekey[i] != ',')
            exit(-1);
        }
    }
  nb2 = malloc(sizeof(char) * 20);
  nb1 = malloc(sizeof(char) * 20);
  poub_zero(nb1, nb2);
  i = -1;
  while (truekey[++i] != ',')
    nb1[i] = truekey[i];
  while (truekey[++i])
    nb2[++j] = truekey[i];
  if ((j = my_getnbr(nb1)) < 1)
    exit(-1);
  param->map_x = j;
  if ((j = my_getnbr(nb2)) < 1)
    exit(-1);
  param->map_y = j;
}

void	truekey_ok(char *truekey, char *key)
{
  my_put_zero(truekey, 20);
  get_truekey(truekey, key);
  if (truekey[0] == 0)
    {
      my_putstr("Error, try with --help\n");
      exit(-1);
    }
}
