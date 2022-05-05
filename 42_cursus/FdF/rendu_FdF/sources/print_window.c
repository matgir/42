/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 11:09:50 by mgirardo          #+#    #+#             */
/*   Updated: 2022/05/02 16:28:19 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// print the coordinate in white in the window

#include "libfdf.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	window(int x, int y, t_coord **coo)
{
	t_mlx		mlx;
	//int		i;
	//int		j;
	t_img	img;

	mlx.mlx_ptr = mlx_init();
	if (mlx.mlx_ptr == NULL)
		return ; // voir pour faire comprendre que erreur
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, 1920, 960, "Bonjour bonsoir");
	if (mlx.win_ptr == NULL)
		return ; // voir pour faire comprendre que erreur
	img.img = mlx_new_image(mlx.mlx_ptr, 1920, 960);
	if (img.img == NULL)
		return ; // voir pour faire comprendre que erreur et free tout le bazar
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
																&img.endian);
	/*i = -1;
	while(++i < y)
	{
		j = -1;
		while(++j < x)
		{
			my_mlx_pixel_put(&img, coo[i][j].x_axe, coo[i][j].y_axe, 0x0000FF00);
			//printf("coord %i,%i = (%f;%f)\n", i, j, coo[i][j].x_axe, coo[i][j].y_axe);
		}
	}*/
	draw_line(&mlx, coo, &img, x, y);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, img.img, 0, 0);
	mlx_loop(mlx.mlx_ptr);
	return ;
}
 
