/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcim <jalcim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 09:15:07 by jalcim            #+#    #+#             */
/*   Updated: 2013/12/01 18:54:06 by jalcim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char * ft_itoa(int n);
void ft_putstr_fd(const char *s, int fd);

void ft_putnbr_fd(int n, int fd)
{
		ft_putstr_fd(ft_itoa(n), fd);
}
