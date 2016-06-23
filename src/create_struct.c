/*
** create_struct.c for tetris in /home/blanch_p/Semestre2/PSU_2015_tetris
** 
** Made by Alexandre Blanchard
** Login   <blanch_p@epitech.net>
** 
** Started on  Sun Mar 20 14:06:50 2016 Alexandre Blanchard
** Last update Sun Mar 20 14:45:50 2016 Alexandre Blanchard
*/

#include "tetris.h"

int		how_many_files()
{
  struct dirent	*entry;
  DIR		*open;
  int		nb;

  nb = 0;
  if ((open = opendir("tetriminos")) == NULL)
    return (-1);
  while ((entry = readdir(open)) != NULL)
    {
      if ((my_strcmp_spe(entry->d_name, ".tetrimino")) == 0)
	nb++;
    }
  return (nb);
}

int		the_check(char *buff, t_tetri *def, int line, int car)
{
  int		i;

  i = 0;
  while (buff[i++] != '\n');
  while (buff[i])
    {
      if (buff[i] != '*' && buff[i] != ' ' && buff[i] != '\n')
	return (-1);
      while (buff[i] == ' ' && (buff[i + 1] == ' ' || buff[i + 1] == '\n'))
	i++;
      if (buff[i] == '\n')
      	{
      	  if (car > def->width)
	    return (-1);
      	  line++;
      	  car = -1;
      	}
      i++;
      car++;
    }
  if (buff[i] == '\0' && buff[i - 1] != '\n')
    line++;
  if (line != def->height)
    return (-1);
  return (0);
}

int		check_good_dim(t_tetri *def)
{
  int		fd;
  char		*buffer;
  int		rd;
  int		size;

  fd = open(def->path, O_RDONLY);
  size = 0;
  buffer = malloc(4096);
  while ((rd = read(fd, buffer + size, 4096)) == 4096)
    {
      size = size + 4096;
      if ((buffer = my_realloc(buffer, size)) == NULL)
	return (-1);
    }
  if (the_check(buffer, def, 0, 0) == -1)
    {
      def->error = 1;
      return (-1);
    }
  return (0);
}

int		check_all_good(t_tetriminos *minos)
{
  int		i;

  i = 0;
  while (i < minos->num)
    {
      if (minos->tetri[i].error == 0 && minos->tetri[i].in_map == 0)
	{
	  return (1);
	}
      i++;
    }
  return (0);
}

t_tetri		*create_struct(t_tetriminos *minos, t_parameter *param, int i)
{
  struct dirent	*entry;
  DIR		*open;
  t_tetri	*def;

  if ((minos->num = how_many_files()) == -1)
    exit(-1);
  if ((def = malloc(sizeof(t_tetri) * minos->num)) == NULL)
    return (NULL);
  open = opendir("tetriminos");
  while ((entry = readdir(open)) != NULL)
    {
      if (my_strcmp_spe(entry->d_name, ".tetrimino") == 0)
  	{
  	  def[i].dos = "tetriminos";
  	  def[i].name = entry->d_name;
  	  def[i].path = my_strcat_spe(def[i].dos, def[i].name);
	  i++;
  	}
    }
  i = 0;
  minos->good = 0;
  while (i < minos->num)
    check(&def[i++], param);
  return (def);
}
