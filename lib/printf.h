/*
** my.h for my in /home/blanch_p/test/printf/pointeurs
** 
** Made by Alexandre Blanchard
** Login   <blanch_p@epitech.net>
** 
** Started on  Wed Nov 11 15:36:28 2015 Alexandre Blanchard
** Last update Sun Jan 24 19:11:08 2016 Alexandre Blanchard
*/

#ifndef PRINTF_H_
#define PRINTF_H_

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

int	p_hexa(va_list ap);
int	g_hexa(va_list ap);
int	octal(va_list ap);
int	bin(va_list ap);
int	fct_s(va_list ap);
int	entier(va_list ap);
int	unsign(va_list ap);
int	caract(va_list ap);
int	chain(va_list ap);
int	ptr(va_list ap);
int	pct(va_list ap);
int	my_printf(const char *s, ...);

#endif /* PRINTF_H_ */
