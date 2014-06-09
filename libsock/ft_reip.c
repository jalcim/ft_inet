/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reip.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcim <jalcim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 02:21:53 by jalcim            #+#    #+#             */
/*   Updated: 2014/06/09 01:30:15 by jalcim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "ft_inet.h"

char	*ft_reip(char *origin)
{
    char *final;
    int cpt1;
    int cpt2;

	if (!origin)
		error("no ip adresse");
	final = (char *)malloc(20);
    final[0] = '1';
    final[1] = '0';
    final[2] = '.';
    final[3] = '1';
    cpt1 = 1;
    cpt2 = 4;
    while (origin[cpt1])
    {
        if (origin[cpt1]>= '0' && origin[cpt1] <= '9')
            final[cpt2] = origin[cpt1];
        else
            final[cpt2] = '.';
        cpt2++;
        cpt1++;
    }
	return (final);
/*
	char	*s2;
	int		i;
	int		count;
	int		offset[3];

	i = count = 0;
	s2 = NULL;
	if (s)
	{
		offset[0] = offset[1] =  offset[2] = 0;
		if (!(s2 = malloc(sizeof(char) * 12)))
			error("malloc error\n");
		while (s[i])
		{
			if (s[i] <= '9' && s[i] >= '0')
				count++;
			i++;
		}
		if (count == 4 && s[5] >= '0' && s[5] <= '9')
			offset[0] = offset[2] = 1;
		else if (count == 4)
			offset[1] = 1;
		else if (count == 3)
			offset[2] = offset[1] = offset[0] = 1;
		s2[0] = s2[3] = s2[6] = '1';
		s2[9 - offset[0]] = s[6 - offset[1]];
		s2[1] = '0';
		s2[2] = s2[5] = s2[8 - offset[0]] = '.';
		s2[4] = s[1];
		s2[7 - offset[0]] = s[4 - offset[0]];
		s2[10 - offset[0] - offset[1]] = s[7 - offset[0] - offset[1]];
		s2[11 - offset[0] - offset[1]] = 0;
		free(s);
	}
	printf("ip = :%s:\n", s2);
	printf("ip = :%s:\n", s);
	return (s2);
 */
}
