/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbahri <nbahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 14:09:25 by nbahri            #+#    #+#             */
/*   Updated: 2013/12/01 16:10:02 by nbahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmap(char const *s, char (*f) (char))
{
	char	*ptr;
	int		i;

	i = -1;
	ptr = (char *) malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!ptr)
		return (NULL);
	while (s[++i])
		ptr[i] = f(s[i]);
	ptr[i] = '\0';
	return (ptr);
}
