/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbahri <nbahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 16:42:34 by nbahri            #+#    #+#             */
/*   Updated: 2013/12/09 16:15:23 by nbahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memmove(void *s1, const void *s2, size_t n)
{
	char		*dest;
	const char	*src;

	dest = s1;
	src = s2;
	if (n && src <= dest)
	{
		dest = dest + (n - 1);
		src = src + (n - 1);
		while (n--)
			*dest-- = *src--;
	}
	else if (n)
	{
		while (n--)
			*dest++ = *src++;
	}
	return (s1);
}
