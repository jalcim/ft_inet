/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbahri <nbahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 12:49:22 by nbahri            #+#    #+#             */
/*   Updated: 2014/02/07 12:04:44 by nbahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_split_len(char const *s, char c)
{
	int		i;
	int		match;

	i = -1;
	match = 0;
	while (s[++i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			match++;
	}
	return (match);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		size;
	int		i;
	int		j;
	int		k;

	tab = (char **) malloc(sizeof(char *) * (ft_split_len(s, c) + 1));
	i = 0;
	j = 0;
	while (s[i++])
	{
		size = i - 1;
		k = 0;
		while (s[size] != c && s[size])
			++size;
		if (size >= i)
		{
			tab[j] = (char *) malloc(sizeof(char) * (size - --i) + 1);
			while (s[i] != c && s[i])
				tab[j][k++] = s[i++];
			tab[j++][k] = '\0';
		}
	}
	tab[j] = 0;
	return (tab);
}
