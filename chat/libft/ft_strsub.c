/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbahri <nbahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 18:41:19 by nbahri            #+#    #+#             */
/*   Updated: 2014/03/17 09:00:22 by nbahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*ret;
	size_t	end;

	i = 0;
	ret = (char *) malloc(sizeof(char) * len + 1);
	end = start + len;
	if (!ret)
		return (NULL);
	while (start < end)
		ret[i++] = s[start++];
	ret[i] = '\0';
	return (ret);
}
