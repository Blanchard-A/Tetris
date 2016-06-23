/*
** my_put_ptr.c for my_put_ptr in /home/blanch_p/Librairie/lib_utile
** 
** Made by Alexandre Blanchard
** Login   <blanch_p@epitech.net>
** 
** Started on  Wed Nov 11 17:59:10 2015 Alexandre Blanchard
** Last update Wed Nov 11 17:59:26 2015 Alexandre Blanchard
*/

int	my_put_ptr(long nb, int base, int ajout)
{
  if (nb < 0)
    nb = nb * -1;
  if (nb >= base)
    {
      my_put_ptr(nb / base, base, ajout);
      my_put_ptr(nb % base, base, ajout);
    }
  if (base > 10)
    {
      if (nb < base && nb >= 10)
        my_putchar(48 + ajout + nb);
    }
  if (nb < base && nb >= 0 && nb < 10)
    my_putchar(48 + nb);
}
