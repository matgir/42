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

#include "mlx.h"

/*int	main(void)
{
	void	*mlx;
	void	*mlx_wind;

	mlx = mlx_init();
	mlx_wind = mlx_new_window(mlx, 1920, 1080, "Hello world !");
//	mlx_new_window(struct t_xvar, width of the window, height of the window, name of the window)
	mlx_loop(mlx);
}*/
//	this funcion open a window that you need to close with CTRL C

typedef struct	s_date{
	void	*imp;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

/*int	main(void)
{
	void	*mlx;
	t_data	img;

	mlx = mlx_init();
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
}*/

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->length + x * (data->bits_per_pixel / 8));
//	this calculate the memory offset unsing de line lenght set by mlx_get_data_addr
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_wind;
	t_data	img;

	mlx = mlx_init();
	mlx_wind = mlx_new_window(mlx, 1920, 1080, "Hello world !");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	/*my_mlx_pixel_put(&img, 5, 6, 0x00FF0000);
	my_mlx_pixel_put(&img, 5, 7, 0x00FF0000);
	my_mlx_pixel_put(&img, 5, 8, 0x00FF0000);
	my_mlx_pixel_put(&img, 5, 9, 0x00FF0000);
	my_mlx_pixel_put(&img, 5, 10, 0x00FF0000);
	my_mlx_pixel_put(&img, 5, 11, 0x00FF0000);
	my_mlx_pixel_put(&img, 6, 6, 0x00FF0000);
	my_mlx_pixel_put(&img, 6, 7, 0x00FF0000);
	my_mlx_pixel_put(&img, 6, 8, 0x00FF0000);
	my_mlx_pixel_put(&img, 6, 9, 0x00FF0000);
	my_mlx_pixel_put(&img, 6, 10, 0x00FF0000);
	my_mlx_pixel_put(&img, 6, 11, 0x00FF0000);
	my_mlx_pixel_put(&img, 7, 6, 0x00FF0000);
	my_mlx_pixel_put(&img, 7, 7, 0x00FF0000);
	my_mlx_pixel_put(&img, 7, 8, 0x00FF0000);
	my_mlx_pixel_put(&img, 7, 9, 0x00FF0000);
	my_mlx_pixel_put(&img, 7, 10, 0x00FF0000);
	my_mlx_pixel_put(&img, 7, 11, 0x00FF0000);
	my_mlx_pixel_put(&img, 8, 6, 0x00FF0000);
	my_mlx_pixel_put(&img, 8, 7, 0x00FF0000);
	my_mlx_pixel_put(&img, 8, 8, 0x00FF0000);
	my_mlx_pixel_put(&img, 8, 9, 0x00FF0000);
	my_mlx_pixel_put(&img, 8, 10, 0x00FF0000);
	my_mlx_pixel_put(&img, 8, 11, 0x00FF0000);
	my_mlx_pixel_put(&img, 9, 6, 0x00FF0000);
	my_mlx_pixel_put(&img, 9, 7, 0x00FF0000);
	my_mlx_pixel_put(&img, 9, 8, 0x00FF0000);
	my_mlx_pixel_put(&img, 9, 9, 0x00FF0000);
	my_mlx_pixel_put(&img, 9, 10, 0x00FF0000);
	my_mlx_pixel_put(&img, 9, 11, 0x00FF0000);*/
	mlx_pixel_put(&img, 5, 6, 0x00FF0000);
	mlx_pixel_put(&img, 5, 7, 0x00FF0000);
	mlx_pixel_put(&img, 5, 8, 0x00FF0000);
	mlx_pixel_put(&img, 5, 9, 0x00FF0000);
	mlx_pixel_put(&img, 5, 10, 0x00FF0000);
	mlx_pixel_put(&img, 5, 11, 0x00FF0000);
	mlx_pixel_put(&img, 6, 6, 0x00FF0000);
	mlx_pixel_put(&img, 6, 7, 0x00FF0000);
	mlx_pixel_put(&img, 6, 8, 0x00FF0000);
	mlx_pixel_put(&img, 6, 9, 0x00FF0000);
	mlx_pixel_put(&img, 6, 10, 0x00FF0000);
	mlx_pixel_put(&img, 6, 11, 0x00FF0000);
	mlx_pixel_put(&img, 7, 6, 0x00FF0000);
	mlx_pixel_put(&img, 7, 7, 0x00FF0000);
	mlx_pixel_put(&img, 7, 8, 0x00FF0000);
	mlx_pixel_put(&img, 7, 9, 0x00FF0000);
	mlx_pixel_put(&img, 7, 10, 0x00FF0000);
	mlx_pixel_put(&img, 7, 11, 0x00FF0000);
	mlx_pixel_put(&img, 8, 6, 0x00FF0000);
	mlx_pixel_put(&img, 8, 7, 0x00FF0000);
	mlx_pixel_put(&img, 8, 8, 0x00FF0000);
	mlx_pixel_put(&img, 8, 9, 0x00FF0000);
	mlx_pixel_put(&img, 8, 10, 0x00FF0000);
	mlx_pixel_put(&img, 8, 11, 0x00FF0000);
	mlx_pixel_put(&img, 9, 6, 0x00FF0000);
	mlx_pixel_put(&img, 9, 7, 0x00FF0000);
	mlx_pixel_put(&img, 9, 8, 0x00FF0000);
	mlx_pixel_put(&img, 9, 9, 0x00FF0000);
	mlx_pixel_put(&img, 9, 10, 0x00FF0000);
	mlx_pixel_put(&img, 9, 11, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_wind, img.img, 0, 0);
	mlx_loop(mlx);
}