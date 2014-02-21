/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcim <jalcim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 16:35:45 by jalcim            #+#    #+#             */
/*   Updated: 2014/02/21 13:11:29 by jalcim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h>
#include <string.h>

char *ft_strnew(size_t size)
{
  size_t compt;
  char *s1;

  compt = -1;

  if (!(s1 = (char *)malloc ((size + 1) * sizeof(char))))
      return (NULL);

  while (++compt <= size)
    {
      *s1 = '\0';

       s1++;
    }
  *s1 = '\0';
  s1 -= compt;

  return (s1);
}
