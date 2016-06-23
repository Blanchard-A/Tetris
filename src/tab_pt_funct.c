/*
** tab_pt_funct.c for tb_pt_fct in /home/brunel_d/rendu/sem_2/syst_un
** 
** Made by axel brunel
** Login   <brunel_d@epitech.net>
** 
** Started on  Tue Mar  1 11:46:48 2016 axel brunel
** Last update Wed Mar  9 13:56:17 2016 axel brunel
*/

#include "tetris.h"

int	tab_ch(char **tab, t_parameter *param)
{
  tab[0] = param->right;
  tab[1] = param->left;
  tab[2] = param->turn;
  tab[3] = param->drop;
  tab[4] = param->pause;
  return (0);
}

int	tab_func(void (**table)(char *ch, int **tab, t_parameter *param))
{
  table[0] = &right;
  table[1] = &left;
  table[2] = &turn;
  table[3] = &drop;
  table[4] = &pause_utilisateur;
  return (0);
}
