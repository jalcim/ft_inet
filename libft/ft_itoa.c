/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcim <jalcim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 20:56:36 by jalcim            #+#    #+#             */
/*   Updated: 2013/12/01 22:48:52 by jalcim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

#define compt util_i[0]
#define decompt util_i[1]
#define tmp2 util_i[2]
#define tmp util_c[0]

char * ft_itoa(int n)
{
    char *a;
    int util_i[3] = {-1, 0, 0};
    char util_c[1] = {0};
    a = (char *)malloc(6 * sizeof(char));
    tmp2 = n;

    while (n)
    {
		a[++compt] = (char)((n % 10) + 48);
		n /= 10;
    }

    a[++compt] = '\0';
    decompt = compt;
    compt = -1;
    while (++compt != --decompt && compt <= decompt)
    {
		tmp = a[compt];
		a[compt] = a[decompt];
		a[decompt] = tmp;
    }
    return (a);
}
