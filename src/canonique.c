/*
** canonique.c for canonique in /home/brunel_d/rendu/sem_2/syst_unix/
** 
** Made by axel brunel
** Login   <brunel_d@epitech.net>
** 
** Started on  Wed Mar 16 15:17:42 2016 axel brunel
** Last update Sat Mar 19 23:27:01 2016 axel brunel
*/

#include "tetris.h"

int			mode_spe(int i)
{
  static struct termios	new_spe;
  static struct termios	old_spe;

  if (i == 0)
    {
      ioctl(0, TCGETS, &new_spe);
      ioctl(0, TCGETS, &old_spe);

      new_spe.c_lflag &= ~ECHO;
      new_spe.c_lflag &= ~ICANON;
      new_spe.c_cc[VTIME] = 0;
      new_spe.c_cc[VMIN] = 1;

      ioctl(0, TCSETS, &new_spe);
    }
  if (i == 1)
    ioctl(0, TCSETS, &old_spe);
  return (0);
}

int			mode(int i, t_parameter *param)
{
  static struct termios	new;
  static struct termios	old;

  if (i == 0)
    {
      ioctl(0, TCGETS, &new);
      ioctl(0, TCGETS, &old);

      new.c_lflag &= ~ECHO;
      new.c_lflag &= ~ICANON;
      new.c_cc[VTIME] = 16 - param->level;
      new.c_cc[VMIN] = 0;

      ioctl(0, TCSETS, &new);
    }
  if (i == 1)
    ioctl(0, TCSETS, &old);
  if (i == 2)
    {
      new.c_cc[VTIME] = 16 - param->level;
      ioctl(0, TCSETS, &new);
    }
  return (0);
}
