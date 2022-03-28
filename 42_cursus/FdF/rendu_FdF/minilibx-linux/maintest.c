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
/*#include <stdlib.h>
#include <stdio.h>

#include <X11/X.h>
#include <X11/keysym.h>
#include "mlx.h"

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 300

#define MLX_ERROR 1

#define RED_PIXEL 0x0000FF

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_data;

int	handle_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	return (0);
}

int	render(t_data *data)
{
//	if window has been destroyed, we don't want to put the pixel !
	if (data->win_ptr != NULL)
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, 
			WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, RED_PIXEL);
	return (0);
}

int	main(void)
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (MLX_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT,
								"my window");
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		return (MLX_ERROR);
	}

//	Setup hooks
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data);

	mlx_loop(data.mlx_ptr);

//	we will exit the loop if there's no window left, and execute this code
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
}*/

/*#include <X11/X.h>
#include <X11/keysym.h>
#include "mlx.h"
#include <stdio.h>

typedef struct s_data
{
	void	*mlx;
	void	*mlx_wind;
	int		color;
	int		x;
	int		y;
}	t_data;

int	main(void)
{
	t_data	data;

	data.mlx = mlx_init();
	data.mlx_wind = mlx_new_window(data.mlx, 1920, 1080, "Hello world !");
	data.color = 0x00FF00FF;
	data.x = 0;
	data.y = 50;
//	mlx_loop_hook(data.mlx, &pixel_put, &data);
	while (data.x++ < 1920)
		mlx_pixel_put(data.mlx, data.mlx_wind, data.x, data.y, data.color);
	mlx_loop(data.mlx);
}*/

#include <stdlib.h>
#include "mlx.h"

int	main(void)
{
	void	*mlx;

	mlx = mlx_init();
	mlx_destroy_display(mlx);
	free(mlx);
}