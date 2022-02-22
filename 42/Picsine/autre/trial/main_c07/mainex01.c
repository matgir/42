/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainex01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 11:36:13 by mgirardo          #+#    #+#             */
/*   Updated: 2021/08/20 12:32:46 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	*ft_range(int min, int max);

int	main(void)
{
	int	min;
	int	max;
	unsigned int i;
	int *tab;

	min = -2147483648;
	max = 2147483647;
	i = 0;
	tab = ft_range(min, max);
	if (tab == 0)
		return (0);
	while (i < (unsigned int)(max - min))
	{
		printf("%d\n", tab[i]);
		i++;
	}
	return (0);
}
