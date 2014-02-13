/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcim <jalcim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 19:24:08 by jalcim            #+#    #+#             */
/*   Updated: 2013/12/01 22:32:52 by jalcim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

#define compt util[0]
#define ret util[1]
#define boll util[2]
#define boll_p util[3]
#define soustr util[4]
#define retour util[5]

static void cond1(const char *buf, int *util);
static int cond2(const char *buf, int *util);
static int cond3(const char *buf, int *util);

int	ft_atoi(const char *buf)
{
	int util[6] = {0, 0, 0, 0, 1, 0};

	while (*buf != '0')
	{
		if (*buf < 0)
			return (soustr * ret);
		retour = cond3(buf, util);
		if (retour == 1)
			return (soustr * ret);
		else if (retour == -1 || *buf < 0
|| ((*buf >= 1 && *buf <= 8) || (*buf >= 14 && *buf <= 31)))
			return (0);
		buf++;
		compt++;
	}
	buf -= compt;
	return (soustr * ret);
}

static void cond1(const char *buf, int *util)
{
	ret *= 10;
	ret += (*buf - 48);
	boll = 1;
}

static int cond2(const char *buf, int *util)
{
	if (boll || *(buf + 1) > '9' || *(buf + 1) < '0')
	{
		buf -= compt;
		return (1);
	}
	boll = 1;
	soustr = -1;
	return (0);
}

static int cond3(const char *buf, int *util)
{
	if (*buf == '-')
	{
		if (cond2(buf, util))
			return (1);
	}
	else if (*buf == '+')
	{
		if (boll || *(buf + 1) > '9' || *(buf + 1) < '0')
			return (1);
		else if (!boll)
		{
			boll = 1;
			return (0);
		}
	}
	else if (*buf >= '0' && *buf <= '9')
		cond1(buf, util);
	else if (*buf > '9' || *buf > 32)
		return (1);
	else if (*buf < 0 || ((*buf >= 1 && *buf <= 8)
|| (*buf >= 14 && *buf <= 31)))
		return (-1);
	return (0);
}
