/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 12:34:00 by mgirardo          #+#    #+#             */
/*   Updated: 2021/08/24 18:34:08 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	minbis;

	minbis = min;
	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	*range = malloc (sizeof(int) * (max - min));
	if (*range == 0)
		return (-1);
	i = 0;
	while (minbis < max)
	{
		(*range)[i] = minbis;
		i++;
		minbis++;
	}
	return (max - min);
}
