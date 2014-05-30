/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbahri <nbahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 17:32:01 by nbahri            #+#    #+#             */
/*   Updated: 2013/11/29 18:54:37 by nbahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dest_size)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = ft_strlen(dest);
	j = 0;
	k = i;
	if (i > dest_size)
		return (ft_strlen(src) + dest_size);
	while (src[j] && i + 1 < dest_size)
		dest[i++] = src[j++];
	dest[i] = '\0';
	return (k + ft_strlen(src));
}
