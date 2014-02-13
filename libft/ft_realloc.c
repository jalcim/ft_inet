/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcim <jalcim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/08 17:18:13 by jalcim            #+#    #+#             */
/*   Updated: 2013/12/08 17:18:35 by jalcim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_realloc (void *replace, int size)
{
    char *ptr;

    ptr = NULL;
    if (!(ptr = (char *)malloc(size)))
        return (NULL);
	ft_bzero (ptr, size);
    ft_memcpy(ptr, (char *)replace, ((sizeof(replace) / 2) * 3));
	free(replace);
	return ((void *)ptr);
}
