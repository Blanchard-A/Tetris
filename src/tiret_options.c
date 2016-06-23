/*
** tiret_options.c for tiret_options in /home/brunel_d/rendu/sem_2/sys
** 
** Made by axel brunel
** Login   <brunel_d@epitech.net>
** 
** Started on  Sat Mar 19 22:29:38 2016 axel brunel
** Last update Sat Mar 19 23:11:05 2016 axel brunel
*/

#include "tetris.h"

void	doble_tiret(t_parameter *param, char *key, int j)
{
  char	*truekey;
  int	nb;

  truekey = malloc(sizeof(char) * 20);
  truekey_ok(truekey, key);
  if (j == 7)
    param->left = truekey;
  if (j == 8)
    param->turn = truekey;
  if (j == 9)
    {
      if ((nb = my_getnbr(truekey)) < 1)
        exit(-1);
      param->level = nb;
    }
  if (j == 10)
    param->drop = truekey;
  if (j == 11)
    param->right = truekey;
  if (j == 12)
    param->quit = truekey;
  if (j == 13)
    resize_map(param, truekey, -1, -1);
  if (j == 14)
    param->pause = truekey;
}

void	simple_tiret(t_parameter *param, char *key, int j)
{
  int	nb;

  if (key[0] == 0)
    exit(-1);
  if (j == 0)
    param->pause = key;
  if (j == 1)
    param->quit = key;
  if (j == 2)
    param->drop = key;
  if (j == 3)
    param->left = key;
  if (j == 4)
    param->turn = key;
  if (j == 5)
    param->right = key;
  if (j == 6)
    {
      if ((nb = my_getnbr(key)) < 1)
        exit(-1);
      param->level = nb;
    }
}

void	help_mode(char **av)
{
  my_putstr("Usage: ");
  my_putstr(av[0]);
  my_putstr(" [options]\nOptions:\n  --help\t\tDisplay this help\n");
  my_putstr("  -l --level={num}\tStart Tetris at level num\n");
  my_putstr("  -kl --key-left={K}\tMove tetrimino on LEFT with key K\n");
  my_putstr("  -kr --key-right={K}\tMove tetrimino on RIGHT with key K\n");
  my_putstr("  -kt --key-turn={K}\tTURN tetrimino with key K\n");
  my_putstr("  -kd --key-drop={K}\tSet default DROP on key K\n");
  my_putstr("  -kq --key-quit={K}\tQuit program when press key K\n");
  my_putstr("  -kp --key-pause={K}\t");
  my_putstr("Pause and restart game when press key K\n");
  my_putstr("  --map-size={row,col}\tSet game size at row, col\n");
  my_putstr("  -w --without-next\tHide next tetrimino\n");
  my_putstr("  -d --debug\t\tDebug mode\n");
  exit(0);
}

void	tiret_empty(t_parameter *param, int j, char **av)
{
  if (j == 15)
    {
      help_mode(av);
    }
  if (j == 16 || j == 17)
    {
      param->hide_next = 1;
    }
  if (j == 18 || j == 19)
    {
      param->debug_mode = 1;
    }
}

void	affect_options(char **options, t_parameter *param, char **av)
{
  int	j;
  int	i;

  i = 1;
  while (av[i] != NULL)
    {
      j = get_j_to_options(options, av[i]);
      if (j < 7)
        {
          simple_tiret(param, av[i + 1], j);
          i++;
        }
      if (j > 6 && j < 15)
        {
          doble_tiret(param, av[i], j);
        }
      if (j > 14)
        {
          tiret_empty(param, j, av);
        }
      i++;
    }
}
