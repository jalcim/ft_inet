/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbahri <nbahri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 18:31:17 by nbahri            #+#    #+#             */
/*   Updated: 2013/12/01 18:36:58 by nbahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_params(int size, char **tab)
{
	int		i;
	int		j;
	int		k;
	char	*tmp;

	j = 0;
	while (++j < size)
	{
		k = j;
		while (++k < size)
		{
			i = 0;
			while ((tab[j][i] && tab[k][i]) && (tab[j][i] == tab[k][i]))
				i++;
			if ((tab[j][i] > tab[k][i]) || (!tab[k][i] && tab[j][i]))
			{
				tmp = tab[j];
				tab[j] = tab[k];
				tab[k] = tmp;
			}
		}
	}
}
