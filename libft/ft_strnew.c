/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcim <jalcim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 16:35:45 by jalcim            #+#    #+#             */
/*   Updated: 2014/02/26 09:06:08 by jalcim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

char *ft_strnew(size_t size)
{
  char *str;

  if (!(str = (char *)malloc(size * sizeof(char))))
      return (NULL);
  ft_bzero(str, size);

  return (str);
}
