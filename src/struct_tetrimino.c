/*
** struct_tetrimino.c for tetris in /blanch_p/Semestre2/PSU_2015_tetris/src
** 
** Made by Alexandre Blanchard
** Login   <blanch_p@epitech.net>
** 
** Started on  Sun Mar 20 14:24:39 2016 Alexandre Blanchard
** Last update Sun Mar 20 14:41:21 2016 Alexandre Blanchard
*/

#include "tetris.h"

char	*recup_all(char *file)
{
  int	fd;
  char  *buffer;
  int   rd;
  int   size;

  fd = open(file, O_RDONLY);
  size = 1;
  buffer = malloc(1);
  while ((rd = read(fd, buffer + size - 1, 1)) == 1)
    {
      size++;
      if ((buffer = my_realloc(buffer, size)) == NULL)
	return (NULL);
    }
  buffer[size - 1] = '\0';
  return (buffer);
}

void	envoi_struct(char *s, int elem, t_tetri *def)
{
  if (elem == 4)
    {
      if ((def->form = malloc(sizeof(char) *
			      ((def->width + 1) * (def->height)) + 1)) == NULL)
	exit (-1);
    }
  if (elem == 1)
    def->width = my_getnbr(s);
  if (elem == 2)
    def->height = my_getnbr(s);
  if (elem == 3)
    def->color = my_getnbr(s);
  if (elem == 4)
    check_good_dim(def);
  if (elem >= 4)
    {
      if (def->error == 0)
	def = in_the_form(s, def, elem);
    }
}

void	in_struct(char *str, t_tetri *def)
{
  int	i;
  char	*s;
  int	size;
  int	elem;

  i = 0;
  elem = 0;
  while (str[i] != '\0')
    {
      s = malloc(10);
      size = 0;
      while ((elem > 2 || str[i] != ' ') && str[i] != '\n' && str[i] != '\0')
        {
          s[size] = str[i];
          size++;
          i++;
        }
      elem++;
      s[size] = '\0';
      if (str[i] == '\n' && elem > 3)
        s[size] = '\n';
      envoi_struct(s, elem, def);
      i++;
      free(s);
    }
}

char	**my_str_to_word_tab(char *str, char **form2d, int height, int width)
{
  int	i;
  int	j;
  int	k;

  i = 0;
  j = 0;
  k = 0;
  while (k < (height * (width + 1)))
    {
      if (str[k] == '\n')
	{
	  form2d[j][i] = '\0';
	  k++;
	  j++;
	  i = 0;
	}
      form2d[j][i] = str[k];
      i++;
      k++;
    }
  form2d[j] = NULL;
  return (form2d);
}

int	check(t_tetri *def, t_parameter *param)
{
  char	*str;

  str = recup_all(def->path);
  if (check_file(str) == -1)
    def->error = 1;
  else
    def->error = 0;
  if (def->error == 0)
    {
      in_struct(str, def);
      def->form2d = my_malloc(def->form2d, def->height + 1, def->width + 1);
      def->form2d = my_str_to_word_tab(def->form, def->form2d, def->height,
				       def->width);
    }
  if (check_in_map(def, param) == -1)
    def->in_map = 1;
  else
    def->in_map = 0;
  return (0);
}
