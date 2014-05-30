/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reip.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcim <jalcim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 02:21:53 by jalcim            #+#    #+#             */
/*   Updated: 2014/03/26 02:21:54 by jalcim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

char	*ft_reip(char *s)
{
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
		{
			free(s);
			return (0);
		}
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
	return (s2);
}
