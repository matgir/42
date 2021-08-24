/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 09:47:35 by mgirardo          #+#    #+#             */
/*   Updated: 2021/08/10 11:13:50 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_sort_int_tab(int *tab, int	size)
{
	int	i;
	int	sw;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			while (tab[i] > tab[j])
			{
				sw = tab[i];
				tab[i] = tab [j];
				tab [j] = sw;
			}
			j++;
		}
		i++;
	}
}
