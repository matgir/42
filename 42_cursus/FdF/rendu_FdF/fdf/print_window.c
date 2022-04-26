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


/*

// print a red pixel in the middle of the window and kill the program with esckey

#include <stdlib.h>
#include <stdio.h>

#include <X11/X.h>
#include <X11/keysym.h>
#include "mlx.h"

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 300

#define MLX_ERROR 1

#define RED_PIXEL 0xFF0000

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
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, RED_PIXEL);
	return (0);
}

int	main(void)
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (MLX_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "my window");
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
}





// print a violet line in the window

#include <X11/X.h>
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
}





//	do nothing

#include <stdlib.h>
#include "mlx.h"

int	main(void)
{
	void	*mlx;

	mlx = mlx_init();
	mlx_destroy_display(mlx);
	free(mlx);
}








// put a white dot in the middle of the window


#include "mlx.h"
#include <unistd.h>
#include <stdlib.h>

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		color;
	int		x;
	int		y;
}	t_data;

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long int	nbr;

	nbr = n;
	if (nbr < 0)
	{
		nbr *= -1;
		ft_putchar_fd('-', fd);
	}
	if (nbr >= 10)
		ft_putnbr_fd(nbr / 10, fd);
	ft_putchar_fd(nbr % 10 + 48, fd);
}

int	deal_key(int key, t_data *data)
{
	if (key == 65307)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	return(0);
}

int	main()
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, 500, 500, "Bonsoir");
	mlx_pixel_put(data.mlx_ptr, data.win_ptr, 250, 250, 0x00FFFFFF);
	mlx_key_hook(data.win_ptr, deal_key, &data);
	mlx_loop(data.mlx_ptr);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
}





*/

// print the coordinate in white in the window

#include "mlx.h"
#include "../libfdf.h"



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
 