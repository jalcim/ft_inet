/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbahri <nbahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 13:37:50 by nbahri            #+#    #+#             */
/*   Updated: 2013/11/30 23:13:43 by nbahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	str = (char *) malloc(sizeof(char) * size + 1);
	if (!str)
		return (NULL);
	while (size)
		str[size--] = '\0';
	str[size] = '\0';
	return (str);
}
