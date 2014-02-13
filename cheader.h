/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheader.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalcim <jalcim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/13 17:44:19 by jalcim            #+#    #+#             */
/*   Updated: 2014/02/13 17:47:19 by jalcim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_inet_aton(const char *cp, struct in_addr *addr);
unsigned short ft_htons(unsigned short value);
unsigned int ft_htonl(unsigned int value);
void error();
