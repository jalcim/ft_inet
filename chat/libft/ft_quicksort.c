/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbahri <nbahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/11 02:03:37 by nbahri            #+#    #+#             */
/*   Updated: 2014/03/17 01:46:57 by nbahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	swap_it(int *a, int *b)
{
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

int		ft_quicksort(int *intab, int beg, int end)
{
	int	i;
	int	j;
	int	piv;

	i = beg + 1;
	piv = j = beg;
	if (beg >= end || !intab)
		return (1);
	while (j <= end && i <= end)
	{
		j = i;
		if (intab[i] <= intab[piv])
			swap_it(&(intab[i++]), &(intab[piv++]));
		else if (intab[i] > intab[piv])
		{
			while (j <= end && intab[j] > intab[piv])
				j++;
			if (intab[j] <= intab[piv])
				swap_it(&(intab[i]), &(intab[j]));
		}
	}
	return (ft_quicksort(intab, beg, piv - 1)
			&& ft_quicksort(intab, piv + 1,  end));
}
