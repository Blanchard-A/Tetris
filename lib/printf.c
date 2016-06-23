/*
** test.c for test in /home/blanch_p/test/printf/pointeurs
** 
** Made by Alexandre Blanchard
** Login   <blanch_p@epitech.net>
** 
** Started on  Wed Nov 11 12:11:38 2015 Alexandre Blanchard
** Last update Wed Dec  2 16:03:55 2015 Alexandre Blanchard
*/

#include "printf.h"

int	tab_flags(char tab_flag[11])
{
  tab_flag[0] = 'd';
  tab_flag[1] = 'i';
  tab_flag[2] = 'o';
  tab_flag[3] = 'u';
  tab_flag[4] = 'x';
  tab_flag[5] = 'X';
  tab_flag[6] = 'c';
  tab_flag[7] = 's';
  tab_flag[8] = 'p';
  tab_flag[9] = 'S';
  tab_flag[10] = 'b';
  tab_flag[11] = '%';
}

int	tab_fcts(int (**tab_fct)(va_list))
{
  tab_fct[0] = &entier;
  tab_fct[1] = &entier;
  tab_fct[2] = &octal;
  tab_fct[3] = &unsign;
  tab_fct[4] = &p_hexa;
  tab_fct[5] = &g_hexa;
  tab_fct[6] = &caract;
  tab_fct[7] = &chain;
  tab_fct[8] = &ptr;
  tab_fct[9] = &fct_s;
  tab_fct[10] = &bin;
  tab_fct[11] = &pct;
}

int	check_flag(int u, const char *s, int i, va_list ap)
{
  int		(**tab_fct)(va_list);
  char		tab_flag[12];

  tab_fct = malloc(sizeof(tab_fct) * 12);
  if (tab_fct == NULL)
    return (1);
  tab_flags(tab_flag);
  tab_fcts(tab_fct);
  if (s[i] == '%' && s[i + 1] == '\0')
    return (2);
  while (tab_flag[u])
    {
      if (tab_flag[u] == s[i + 1])
	{
	  tab_fct[u](ap);
	  free(tab_fct);
	  return (1);
	}
      u = u + 1;
    }
  return (0);
}

int		aff_no_reco(const char *s, int i)
{
  my_putchar(s[i]);
  my_putchar(s[i + 1]);
  i = i + 2;
  return (i);
}

int		my_printf(const char *s, ...)
{
  va_list	ap;
  int		i;
  int		u;

  i = 0;
  va_start(ap, s);
  while (s[i])
    {
      u = 0;
      if (s[i] == '%')
	{
	  if (check_flag(u, s, i, ap) == 1)
	    i = i + 2;
	  else if (check_flag(u, s, i, ap) == 0)
	    aff_no_reco(s, i);
	  else if (check_flag(u, s, i, ap) == 2)
	    return (0);
	}
      else
	{
	  my_putchar(s[i]);
	  i = i + 1;
	}
    }
}
