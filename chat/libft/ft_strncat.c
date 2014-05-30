/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbahri <nbahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 11:51:47 by nbahri            #+#    #+#             */
/*   Updated: 2013/11/26 12:31:35 by nbahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	int		i;

	i = 0;
	while (dest[i])
		i++;
	while (*src && n--)
		dest[i++] = *src++;
	dest[i] = '\0';
	return (dest);
}
