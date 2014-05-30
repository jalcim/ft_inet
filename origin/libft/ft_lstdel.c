/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbahri <nbahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 19:03:14 by nbahri            #+#    #+#             */
/*   Updated: 2013/11/26 20:55:59 by nbahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*l_ptr;
	t_list	*tmp;

	l_ptr = *alst;
	while (l_ptr->next)
	{
		tmp = l_ptr;
		del(l_ptr->content, l_ptr->content_size);
		l_ptr = l_ptr->next;
		free(tmp);
	}
	del(l_ptr->content, l_ptr->content_size);
	free(l_ptr);
	*alst = NULL ;
}
