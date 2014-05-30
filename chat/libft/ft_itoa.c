/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbahri <nbahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 20:35:37 by nbahri            #+#    #+#             */
/*   Updated: 2013/12/01 17:49:06 by nbahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		i;
	int		op;
	int		min;
	char	*str;

	i = 0;
	op = 10;
	min = 0;
	str = (char *) malloc(sizeof(*str) * 12);
	if (n < 0)
	{
		n += (n == -2147483648 && ++min) ? 1 : 0;
		n = -n;
		str[i++] = '-';
	}
	op = ft_power(op, ft_int_len(n) - 1);
	while (op)
	{
		n += (!(op / 10) && min) ? 1 : 0;
		str[i++] = n / op % 10 + 48;
		n %= op;
		op /= 10;
	}
	str[i] = '\0';
	return (str);
}
