/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcim <jalcim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/09 14:20:15 by jalcim            #+#    #+#             */
/*   Updated: 2014/03/21 16:24:19 by jalcim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include "libft.h"

void strap(char fmt, va_list *ap, int **tab_ti, unsigned int *size);
int ft_printf(const char *fmt, ...)
{
	va_list ap;
	int *tab_ti;
	unsigned int size;

	va_start (ap, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
			{
				fmt++;
				strap(*fmt, &ap, &tab_ti, &size);
				fmt++;
			}
		else
		{
			ft_putchar (*fmt);
			fmt++;
		}
	}
	va_end(ap);
	return (1);
}

void strap(char fmt, va_list *ap, int **tab_ti, unsigned int *size)
{
	if (fmt == 'd')
		ft_putnbr(va_arg (*ap, int));
	else if (fmt == 's')
		ft_putstr(va_arg (*ap, char *));
	else if (fmt == 'c')
		ft_putchar(va_arg (*ap, int));
	else if (fmt == 't')
	{
		(*tab_ti) = va_arg (*ap, int *);
		*size = sizeof(*tab_ti);
		while ((--(*size)) + 1)
		{
			ft_putnbr(*(*tab_ti));
			tab_ti++;
		}
	}
}

int main()
{
	int tab[10] = {0,1,2,3,4,5,6,7,8,9};

	ft_printf("%t\n", tab);
}
