/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbahri <nbahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/09 15:33:46 by nbahri            #+#    #+#             */
/*   Updated: 2014/01/19 03:08:22 by nbahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		find_c(int size, char const *s)
{
	while (s[size] != '\n' && s[size])
		++size;
	return (size);
}

static int		alloc_c(int *size, char ***tab, char const *s, int j)
{
	if (s[*size] == '\n' && s[(*size) - 1] == '\n')
	{
		(*tab)[j] = (char *) malloc(sizeof(char));
		(*tab)[j++][0] = '\0';
	}
	return (j);
}

static int		ft_get_len(char const *s)
{
	int		i;
	int		match;

	i = -1;
	match = 0;
	while (s[++i])
	{
		if (s[i] == '\n')
			match++;
	}
	return (match);
}

char	**ft_get_tab(char const *s)
{
	char	**tab;
	int		size;
	int		i;
	int		j;
	int		k;

	tab = (char **) malloc(sizeof(char *) * (ft_get_len(s) + 2));
	i = 0;
	j = 0;
	while (s[i++])
	{
		size = i - 1;
		k = 0;
		size = find_c(size, s);
		j = alloc_c(&size, &tab, s, j);
		if (size >= i)
		{
			tab[j] = (char *) malloc(sizeof(char) * (size - --i) + 1);
			while (s[i] != '\n' && s[i])
				tab[j][k++] = s[i++];
			tab[j++][k] = '\0';
		}
	}
	tab[j] = '\0';
	return (tab);
}
