/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbahri <nbahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 14:15:01 by nbahri            #+#    #+#             */
/*   Updated: 2014/03/18 18:46:43 by nbahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char const *s1)
{
	int		i;
	char	*ret;

	i = -1;
	if (!(ret = (char *) malloc(sizeof(*ret) * ft_strlen(s1) + 1)))
		return (NULL);
	while (s1[++i])
		ret[i] = s1[i];
	ret[i] = '\0';
	return (ret);
}
