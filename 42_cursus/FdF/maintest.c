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








#include <stdlib.h>
#include "mlx.h"

int	main(void)
{
	void	*mlx;

	mlx = mlx_init();
	mlx_destroy_display(mlx);
	free(mlx);
}











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








#include "mlx.h"
#include <stddef.h>

typedef struct	s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}				t_data;

typedef struct	p_data
{
	int	start_point_x;
	int	start_point_y;
}				p_data;

int	main()
{
	int		x = 10;
	int		y = 10;
	t_data	data;
	p_data	start;
	int		win_height;
	int		win_width;
	int		go_down;
	int		go_right;
	int		tmp_x;

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return(1);
	win_height = 1000;
	win_width = 1000;
	data.win_ptr = mlx_new_window(data.mlx_ptr, win_width, win_height, "Test");
	if (data.win_ptr == NULL)
		return(1);
	start.start_point_x = 50;
	start.start_point_y = 50;
	tmp_x = start.start_point_x;
	go_down = 0;
	while(go_down <= y)
	{
		go_right = 0;
		while(go_right <= x)
		{
			mlx_pixel_put(data.mlx_ptr, data.win_ptr, start.start_point_x, start.start_point_y, 0xFFFFFF);
			start.start_point_x += 10;
			go_right++;
		}
		start.start_point_x = tmp_x;
		start.start_point_y += 10;
		go_down++;
	}
	mlx_loop(data.mlx_ptr);
	return(0);
}
//	permet d'afficher un rectangle de point de longueur x et hauteur y



//	objectif creer un un tableau de tableau avec dans chque case une struct ou un str de coordonnees du point
//	pour une representation comme voulu dans le rendu final

typedef struct	c_data
{
	int	x_axe;
	int	y_axe;
}				coord;

#include "mlx.h"

int	main()
{
	coord	**coo;

	coo = malloc
}