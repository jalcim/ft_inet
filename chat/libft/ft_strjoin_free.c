/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbahri <nbahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 02:32:45 by nbahri            #+#    #+#             */
/*   Updated: 2014/03/17 02:07:39 by nbahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin_free(char *a, char *b, int nb)
{
	char	*str;
	int		i;
	int		j;

	i = -1;
	j = -1;
	str = (char *) malloc(sizeof(char) * (ft_strlen(a) + ft_strlen(b)) + 1);
	while (a[++i])
		str[i] = a[i];
	while (b[++j])
		str[i++] = b[j];
	str[i] = '\0';
	if (nb == 1 || nb == 3)
		ft_strdel(&a);
	if (nb == 2 || nb == 3)
		ft_strdel(&b);
	return (str);
}
