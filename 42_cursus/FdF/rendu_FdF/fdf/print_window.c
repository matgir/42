/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 11:09:50 by mgirardo          #+#    #+#             */
/*   Updated: 2022/03/24 11:09:53 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// print the coordinate in white in the window

#include "libfdf.h"

void	window(int x, int y, coord **coo)
{
	t_data	data;
	int		i;
	int		j;

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return;
	data.win_ptr = mlx_new_window(data.mlx_ptr, 1920, 960, "Bonjour bonsoir");
	if (data.win_ptr == NULL)
		return ;
	i = -1;
	while(++i < y)
	{
		j = -1;
		while(++j < x)
		{
			mlx_pixel_put(data.mlx_ptr, data.win_ptr, coo[i][j].x_axe, coo[i][j].y_axe, 0xFFFFFF);
			printf("coord %i,%i = (%f;%f)\n", i, j, coo[i][j].x_axe, coo[i][j].y_axe);
		}
	}
	mlx_pixel_put(data.mlx_ptr, data.win_ptr, coo[1][1].x_axe, coo[1][1].y_axe, 0xFFFFFF);
	mlx_loop(data.mlx_ptr);
	return ;
}
//	permet d'afficher un rectangle de point de longueur x et hauteur y
 