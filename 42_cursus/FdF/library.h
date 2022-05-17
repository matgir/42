/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   library.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:58:12 by mgirardo          #+#    #+#             */
/*   Updated: 2022/05/17 16:58:13 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBRARY.H
# define LIBRARY.H

# define LEFT_CLICK 1
# define RIGHT_CLICK 3
# define WHEEL_UP 5
# define WHEEL_DOWN 4

# define ESC 65307
# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363
# define PLUS 65451
# define MINUS 65453
# define CTRL_RIGHT 65508
# define OPTION 65027
# define W 119
# define A 97
# define S 115
# define D 100
# define C 99
# define P 112

# define WIDTH 1920
# define HEIGHT 1080
# define MENU_WIDTH 300

//###############################################################################

# include "libft.h"
# include "mlx.h"

# include <fcntl.h>
# include <stdio.h>
# include <math.h>

//###############################################################################


typedef enum e_bool {
	TRUE = 1,
	FALSE = 0
}	t_bool;

typedef enum e_proj {
	ISO,
	PARALLEL
}	t_proj;

typedef struct s_camera
{
	int		zoom;
	double	alpha;
	double	beta;
	double	gamma;
	float	z_scale;
	int		x_offset;
	int		y_offset;
	t_proj	proj;
}	t_camera;

typedef struct s_map
{
	int			**map;
	int			line_size;
	int			line_count;
	int			z_min;
	int			z_max;
	int			z_range;
	t_camera	camera;
	t_bool		colors;
}	t_map;

typedef struct s_3d_point
{
	int	x;
	int	y;
	int	z;
}	t_3d_point;

typedef struct s_point
{
	int			x;
	int			y;
	t_3d_point	real_point;
}	t_point;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*window_ptr;
	t_map	*map;
}	t_mlx;

//###############################################################################

//Parse functions
t_map		*parse_map(char *file);
int			**process_line(char *line, int **table, int *line_size);
t_mlx		*quit_before_start(t_mlx *mlx);

//Display functions
t_mlx		*init_window(char *name, t_map *map);
int			encode_rgb(int red, int green, int blue);
void		display(t_mlx *mlx);
void		trace_line(t_point point1, t_point point2, t_mlx *mlx);
void		display_background(t_mlx *mlx, int color);
void		display_points(t_mlx *mlx);
void		display_menu(t_mlx *mlx, int background_color, int text_color);
int			get_color(t_3d_point point, int z_min, int z_max);
int			get_gradient_color(t_point point1, t_point point2, t_point cur,
				t_map *map);
int			get_green(t_3d_point point, int z_min, int z_max);
int			get_blue(t_3d_point point, int z_min, int z_max);
int			get_red(t_3d_point point, int z_min, int z_max);

//Calcul function
t_3d_point	init_3d_point(int x, int y, int z);
t_point		project(t_3d_point point, t_map *map);
t_map		init_map(t_map map);

//Input functions
int			handle_key(int key, void *ptr);
int			handle_mouse(int button, int x, int y, void *ptr);
void		press_up(t_mlx *mlx);
void		press_down(t_mlx *mlx);
void		press_left(t_mlx *mlx);
void		press_right(t_mlx *mlx);
void		press_w(t_mlx *mlx);
void		press_a(t_mlx *mlx);
void		press_s(t_mlx *mlx);
void		press_d(t_mlx *mlx);
void		press_escape(t_mlx *mlx);
void		press_ctrl(t_mlx *mlx);
void		press_option(t_mlx *mlx);
void		press_plus(t_mlx *mlx);
void		press_minus(t_mlx *mlx);
void		press_c(t_mlx *mlx);
void		press_p(t_mlx *mlx);

//System functions
void		quit(t_mlx *mlx);

#endif
