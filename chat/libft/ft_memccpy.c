/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbahri <nbahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 18:52:18 by nbahri            #+#    #+#             */
/*   Updated: 2013/11/28 17:07:36 by nbahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char			*ptr_dst;
	const char		*ptr_src;

	ptr_dst = dest;
	ptr_src = src;
	if (n)
	{
		while (n && *ptr_src != c)
		{
			*ptr_dst++ = *ptr_src++;
			n--;
		}
		if (*ptr_src == c && n)
		{
			*ptr_dst++ = *ptr_src;
			return (ptr_dst);
		}
	}
	return (NULL);
}
