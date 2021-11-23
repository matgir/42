/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ten_power.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepiney <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 21:31:54 by llepiney          #+#    #+#             */
/*   Updated: 2021/08/22 19:08:15 by llepiney         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

char	*ten_power(int pow)
{
	char	*power;
	int	i;

	i = 4;
	power = malloc(sizeof(char) * (5 + (pow - 1) * 3));
	if (!power)
		return (0);
	power[0] = '1';
	power[1] = '0';
	power[2] = '0';
	power[3] = '0';
	if (pow == 1)
	{
		power[i] = '\0';
		return (power);
	}
	else
	{
		while (i < (4 + (pow - 1) * 3))
		{
			power[i] = '0';
			i++;
		}
		power[i] = '\0';
	}
	return (power);
}
