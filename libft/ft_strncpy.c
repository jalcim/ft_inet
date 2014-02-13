/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcim <jalcim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 04:01:21 by jalcim            #+#    #+#             */
/*   Updated: 2013/12/01 19:31:13 by jalcim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char * ft_strncpy (char *dest, const char *src, size_t size)
{
	size_t compt;
	int boll;

	compt = 0;
	boll = 0;

	while (compt < size)
	{
		if (src[compt] == '\0' || boll)
		{
			dest[compt] = '\0';
			boll = 1;
		}

		if (!boll)
			dest[compt] = src[compt];

		compt++;
	}
	return (dest);
}
