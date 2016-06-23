/*
** my_getnbr.c for my_get_nbr in /home/hersen_f/rendu_Piscine/Piscine_C_J07/lib/my
** 
** Made by François Hersent
** Login   <hersen_f@epitech.net>
** 
** Started on  Thu Oct  8 10:03:00 2015 François Hersent
** Last update Fri Oct 23 14:35:00 2015 François Hersent
*/

int	my_getnbr(char *str)
{
  int   z;
  int   p;
  int	res;

  res = 0;
  p = 0;
  z = 0;
  while (str[z] == '+' || str[z] == '-')
    {
      if (str[z] == '-')
	p = p + 1;
      z++;
    }
  while (str[z] >= 48 && str[z] <= 57)
    {
      res = res + str[z]  - 48;
      res = res * 10;
      z++;
    }
  res = res / 10;
  if (p % 2 == 1)
    res = res * - 1;
  return (res);
}
