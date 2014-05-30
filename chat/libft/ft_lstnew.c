/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbahri <nbahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 13:50:29 by nbahri            #+#    #+#             */
/*   Updated: 2013/11/27 14:41:20 by nbahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*l_ptr;

	l_ptr = (t_list *) malloc(sizeof(*l_ptr));
	if (l_ptr)
	{
		l_ptr->content = (void *) content;
		if (content == NULL)
			l_ptr->content_size = 0;
		else
			l_ptr->content_size = content_size;
		l_ptr->next = NULL;
		return (l_ptr);
	}
	return (NULL);
}
