/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbahri <nbahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 11:58:25 by nbahri            #+#    #+#             */
/*   Updated: 2013/11/29 19:24:47 by nbahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char const *str1, char const *str2, size_t n)
{
	int		i;
	size_t	j;
	char	*ret;

	i = -1;
	if (*str2 == '\0')
		return ((char *) str1);
	while (str1[++i])
	{
		j = 0;
		while ((i < (int)  n) && str1[i] && str2[j] && str1[i] == str2[j])
		{
			if (j++ == 0)
				ret = (char *) &str1[i];
			i++;
		}
		if (j && str2[j])
			i -= j;
		if (!str2[j])
			return (ret);
	}
	return (NULL);
}
