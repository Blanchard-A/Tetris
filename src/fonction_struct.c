/*
** fonction_struct.c for tetris in /home/Semestre2/PSU_2015_tetris/src
** 
** Made by Alexandre Blanchard
** Login   <blanch_p@epitech.net>
** 
** Started on  Sun Mar 20 14:07:12 2016 Alexandre Blanchard
** Last update Sun Mar 20 14:10:39 2016 Alexandre Blanchard
*/

#include "tetris.h"

char	*my_strcat_spe(char *s1, char *s2)
{
  char	*s;
  int	len1;
  int	len2;
  int	i;
  int	j;

  j = 0;
  i = 0;
  len1 = my_strlen(s1);
  len2 = my_strlen(s2);
  s = malloc(sizeof(char) * (len1 + len2 + 2));
  while (i < len1)
    {
      s[i] = s1[i];
      i++;
    }
  s[i++] = '/';
  while (j < len2)
    {
      s[i] = s2[j];
      i++;
      j++;
    }
  s[i] = '\0';
  return (s);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      i++;
    }
  return (i);
}
