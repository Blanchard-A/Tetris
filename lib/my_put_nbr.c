/*
** my_put_nbr.c for my_put_nbr in /home/blanch_p/Librairie/lib_utile
** 
** Made by Alexandre Blanchard
** Login   <blanch_p@epitech.net>
** 
** Started on  Wed Nov 11 17:58:11 2015 Alexandre Blanchard
** Last update Fri Nov 13 15:09:23 2015 Alexandre Blanchard
*/

int	my_put_nbr(int nb, int base, int ajout)
{
  int	i;

  i = nb;
  if (nb < 0)
    nb = nb * -1;
  if (i < 0 && base == 10)
    my_putchar('-');
  if (nb >= base)
    {
      my_put_nbr(nb / base, base, ajout);
      my_put_nbr(nb % base, base, ajout);
    }
  if (base > 10)
    {
      if (nb < base && nb >= 10)
        my_putchar(48 + ajout + nb);
    }
  if (nb < base && nb >= 0 && nb < 10)
    my_putchar(48 + nb);
}
