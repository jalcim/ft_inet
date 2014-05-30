/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbahri <nbahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 11:18:49 by nbahri            #+#    #+#             */
/*   Updated: 2013/12/24 09:37:10 by nbahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(char *str)
{
	int		j;
	int		ret;

	j = 0;
	ret = 0;
	while ((*str > 8 && *str < 14) || *str == ' ')
		str++;
	if (*str == '-')
	{
		j = 1;
		str++;
	}
	if (*str == '+' && *(str - 1) != '-')
		str++;
	while (*str && *str >= '0' && *str <= '9')
		ret = ret * 10 + (*str++ - 48);
	if (j)
		return (-ret);
	return (ret);
}
