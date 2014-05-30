/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbahri <nbahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/07 20:37:33 by nbahri            #+#    #+#             */
/*   Updated: 2014/01/24 10:10:58 by nbahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int			get_tmp(int const fd, char **tmp, char *buf)
{
	int				ret;

	ret = BUFF_SIZE;
	*tmp = ft_strnew(0);
	while (ret == BUFF_SIZE && (ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		ft_putstr_fd(buf, 2);
		if (ret < 40)
			get_tmp(fd, tmp, buf);
		if (!ft_isprint(buf[1]) || !ft_isprint(buf[0]))
			return (0);
		*tmp = ft_strjoin_free(*tmp, buf);
		ft_strclr(buf);
 	}
	return (0);
}

char				**get_tab_fd(int const fd)
{
	char			buf[BUFF_SIZE + 1];
	char			*tmp;
	char			**tab;

	if (fd == -1 || BUFF_SIZE > 8280000)
		return (NULL);
	if (get_tmp(fd, &tmp, buf) == -1)
		return (NULL);
	tab = ft_get_tab(tmp);
	ft_strclr(tmp);
	ft_strdel(&tmp);
	return (tab);
}
