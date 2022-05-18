/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   incorporates_z.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:28:36 by mgirardo          #+#    #+#             */
/*   Updated: 2022/05/02 16:28:37 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

t_coord	**incorporate_z(t_coord **coo, char ***z_coordinates, int x, int y)
{
	int	i;
	int	j;

	i = -1;
	while (++i < y)
	{
		j = 0;
		coo[i][j].y_axe -= (ft_atoi(z_coordinates[i][j]));
		while (j < x)
		{
			coo[i][j].y_axe -= (ft_atoi(z_coordinates[i][j]));
			j++;
		}
	}
	return (coo);
}