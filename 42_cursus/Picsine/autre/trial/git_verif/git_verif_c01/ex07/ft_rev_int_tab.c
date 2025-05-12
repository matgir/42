/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 21:54:04 by mgirardo          #+#    #+#             */
/*   Updated: 2021/08/10 11:12:57 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rev_int_tab(int	*tab, int	size)
{
	int	i;
	int	sw;

	i = 0;
	while (i < (size / 2))
	{
		sw = tab[i];
		tab [i] = tab[size - i - 1];
		tab[size - i - 1] = sw;
		i++;
	}
}
