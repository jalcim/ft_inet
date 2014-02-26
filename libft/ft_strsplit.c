/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcim <jalcim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 23:41:33 by jalcim            #+#    #+#             */
/*   Updated: 2013/12/01 23:34:23 by jalcim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define compt util[0]
#define strcpt util[1]
#define compt_c util[2]

#define nb_char util[1]

#define win util[1]

static int deldupc(char *s, char c);
static void dstr(int comp, char *s);
static int strclen(char *s, char c, int nb_str);

char **  ft_strsplit(const char *s, char c)
{
	char **tab;
	int util[3];

	compt = -1;
	nb_char = deldupc((char *)s, c);

	if (!*s || *s == '\0')
		return (NULL);

	if (!(tab = (char **)malloc((nb_char + 1) * sizeof(char *))))
		return (NULL);
	while (++compt < nb_char)
	{
		if (!(tab[compt] = ft_strnew((strclen((char *)s, c, compt) + 1) * sizeof(char))))
			return (NULL);
		ft_memset(tab[compt], '\0', sizeof(tab[compt]));
	}
	tab[compt] = '\0';

	if (ft_strlen(s))
	{
		compt_c = 0;
		compt = 0;
		nb_char = -1;
		while (s[++nb_char] != '\0')
		{
			if (s[nb_char] == c)
			{
				if (nb_char)
				{
					tab[compt][compt_c] = '\0';
					compt++;
				}
					compt_c = 0;
			}
			else
			{
				tab[compt][compt_c] = s[nb_char];
				compt_c++;
			}
		}
	}
	tab[compt + 1] = '\0';
	return (tab);
}

static int deldupc(char *s, char c)
{
	int util[3];

	compt_c = 0;
	compt = -1;

	if (s[0] != c)
		compt_c++;

	while (s[++compt] != '\0')
	{
		if (s[compt] == c)
		{
			compt_c++;
			if (s[compt + 1] == c || s[compt + 1] == '\0')
			{
				dstr(compt, s);
				compt--;
			}
		}
	}
	return (compt_c);
}

static void dstr(int comp, char *s)
{
	comp -= 1;
	while (s[++comp] != '\0')
	{
		s[comp] = s[comp + 1];
	}
}

static int strclen(char *s, char c, int nb_str)
{
	int util[3];

	win = 0;
	compt = nb_str;
	compt_c = -1;

	while (s[++compt] == c && s[compt] != '\0')
		win++;

	return (win);
}
