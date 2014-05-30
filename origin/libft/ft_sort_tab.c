/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbahri <nbahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 17:59:45 by nbahri            #+#    #+#             */
/*   Updated: 2014/02/13 01:15:49 by nbahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_sort_t(int i, int size, char **t)
{
	int		j;
	int		k;
	char	*tmp;

	while (++i < size)
	{
		k = i;
		while (++k < size)
		{
			j = 0;
			while ((t[i][j] && t[k][j]) && (t[i][j] == t[k][j]))
				j++;
			if ((t[i][j] > t[k][j]) || (!t[k][j] && t[i][j]))
			{
				tmp = t[i];
				t[i] = t[k];
				t[k] = tmp;
			}
		}
	}
}
