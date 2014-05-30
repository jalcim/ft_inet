/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbahri <nbahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 19:11:22 by nbahri            #+#    #+#             */
/*   Updated: 2014/02/16 21:00:49 by nbahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	sort_int(int *t, int size)
{
	int		i;
	int		j;
	int		match;
	int		tmp;

	i = -1;
	while (++i < size - 1)
	{
		j = i;
		match = i;
		while (++j < size)
		{
			if (t[j] < t[i] && t[j] < t[match])
				match = j;
		}
		tmp = t[match];
		t[match] = t[i];
		t[i] = tmp;
	}
}
