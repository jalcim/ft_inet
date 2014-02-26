/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcim <jalcim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 13:43:24 by jalcim            #+#    #+#             */
/*   Updated: 2013/12/01 22:43:33 by jalcim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	ft_bzero(void *src, size_t size)
{
	size_t	compt;
	compt = 0;

	char	*tab;
	tab = (char *) src;

	while (compt < size)
	{
		tab[compt] = 0;
		compt++;
	}
}
