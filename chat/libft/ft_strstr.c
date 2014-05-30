/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbahri <nbahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 12:02:48 by nbahri            #+#    #+#             */
/*   Updated: 2013/11/30 23:32:40 by nbahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char const *str1, char const *str2)
{
	int		i;
	int		j;
	char	*ret;

	i = -1;
	if (*str2 == '\0')
		return ((char *) str1);
	while (str1[++i])
	{
		j = 0;
		while (str1[i] && str2[j] && str1[i] == str2[j])
		{
			if (j++ == 0)
				ret = (char *) &str1[i];
			i++;
		}
		if (str2[j] && j)
			i -= j;
		if (!str2[j])
			return (ret);
	}
	return (NULL);
}
