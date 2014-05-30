/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbahri <nbahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 14:13:34 by nbahri            #+#    #+#             */
/*   Updated: 2013/11/30 15:29:46 by nbahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del) (void *, size_t))
{
	t_list	*l_ptr;

	l_ptr = *alst;
	del(l_ptr->content, l_ptr->content_size);
	free(l_ptr);
	*alst = NULL;
}
