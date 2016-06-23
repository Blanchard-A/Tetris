/*
** my_revstr.c for my_revstr_lib in /home/celor_t/lib
** 
** Made by tristan celor
** Login   <celor_t@epitech.net>
** 
** Started on  Mon Oct 26 10:35:34 2015 tristan celor
** Last update Fri Mar 18 14:51:15 2016 axel brunel
*/

#include "tetris.h"

char	*my_revstr(char *str)
{
  int   i;
  int   c;
  char  *temp;

  if ((temp = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    return (NULL);
  i = 0;
  while (str[i] != '\0')
    {
      temp[i] = str[i];
      i = i + 1;
    }
  c = i - 1;
  i = 0;
  while (c >= 0)
    {
      str[i] = temp[c];
      c = c - 1;
      i = i + 1;
    }
  return (str);
}
