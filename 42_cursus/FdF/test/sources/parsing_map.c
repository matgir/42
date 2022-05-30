/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 16:38:59 by mgirardo          #+#    #+#             */
/*   Updated: 2022/05/02 16:28:06 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

int	**specifie_error(int **coord, int gnl_error)
{
	int	i;

	i = -1;
	if (coord == NULL)
	{
		while (coord[++i] != NULL)
			free(coord[i]);
		free(coord);
	}
	if (gnl_error == -1)
		perror("The map you choose cannot be read, please select another");
	if (gnl_error == -2)
		ft_putendl_fd("There was an error during the allocation of the memory, please try again", 1);
	if (gnl_error == -3)
		ft_putendl_fd("Cannot parse file, please select another",1);
	return(NULL);
}

int	coord_current_lines(int **coord)
{
	int	i;

	i = 0;
	while (coord[i] != NULL)
		i++;
	return (i);
}

int	**add_coord(int **coord)
{
	int	**new_coord;
	int	i;

	if (coord == NULL)
	{
		coord = malloc(sizeof(*coord));
		if (coord == NULL)
			return (NULL);
		coord[0] = NULL;
	}
	new_coord = malloc(sizeof(*coord) * (coord_current_lines(coord) + 2));
	if (new_coord == NULL)
		return (NULL);
	i = -1;
	while (++i < coord_current_lines(coord))
		new_coord[i] = coord[i];
	new_coord[i++] = NULL;
	new_coord[i] = NULL;
	free(coord);
	return (new_coord);
}

int	*get_int(char *line, int *column_count)
{
	char	**split;
	int		*get_int;
	int		column;
	int		i;

	split = ft_split(line, ' ');
	if (split == NULL)
		return (NULL);
	column = 0;
	while (split[column] != NULL) //maybe !='\0'
		column++;
	get_int = malloc(sizeof(int) * column);
	if (get_int)
	{
		i = -1;
		while (++i < column)
			get_int[i] = ft_atoi(split[i]);
		*column_count = i;
	}
	while (column >= 0)
		free(split[column]);
	free(split);
	return (get_int);
}

int **add_line(char *line, int **coord, int *column_count)
{
	int	*pre_line;

	coord = add_coord(coord);
	if (coord == NULL)
		return (NULL);
	pre_line = get_int(line, column_count);
	if (pre_line == NULL)
		return (NULL);
	if (coord_current_lines(coord) == 0)
		coord[0] = pre_line;
	else
		coord[coord_current_lines(coord)] = pre_line;
	return (coord);
}

int	**ft_parsing(int fd, int *column_count, int *line_count)
{
	char	*line;
	int		gnl_error;
	int		**coord;

	coord = NULL;
	gnl_error = 0;
	while (TRUE) // voir pour mettre autre condition
	{
		line = fdf_gnl(fd, &gnl_error);
		if (line == NULL)
		{
			if (gnl_error < 0)
				return (specifie_error(coord, gnl_error));
			break;
		}
		*line_count = *line_count + 1;
		coord = add_line(line, coord, column_count);
		if (coord == NULL)
		{
			free(line);
			return(specifie_error(coord, -3));
		}
		free(line);
	}
	return (coord);
}

t_coord	*parse_map(char *z_map)
{
	int		fd;
	int		**z_coord;
	int		column_count;
	int		line_count;
	t_coord	*coord;

	line_count = 0;
	fd = open(z_map, O_RDONLY);
	if (fd == -1)
	{
		perror("The map you choose cannot be read, please select another");
		return (NULL);
	}
	z_coord = ft_parsing(fd, &column_count, &line_count);
	coord = malloc(sizeof(t_coord));
	if (coord == NULL)
		return (NULL);
	coord->coord = z_coord;
	coord->line_count = line_count;
	coord->column_count = column_count;
	close(fd);
	return(coord);
}

t_mlx	*free_and_quit(t_mlx *mlx)
{
	int i;

	i = -1;
	while (++i < mlx->coord->line_count)
		free((mlx->coord->coord)[i]);
	free(mlx->coord->coord);
	free(mlx->coord);
	free(mlx);
	if (mlx->mlx_ptr && mlx->win_ptr)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	if (mlx->mlx_ptr)
	{
		mlx_destroy_display(mlx->mlx_ptr);
		free(mlx->mlx_ptr);
	}
	return (NULL);
}

int	def_min(int w, int h)
{
	if (w < h)
		return (w);
	return (h);
}

t_coord	setup_camera(t_coord coord)
{
	coord.camera.zoom = def_min(WHIDTH / coord.column_count / 2,
			HEIGHT / coord.line_count / 2);
	coord.camera.z_scale = 7;
	coord.camera.x_offset = 96; // a verif
	coord.camera.y_offset = 192; // avreif
	return (coord);
}

t_coord	init_map(t_coord coord)
{
	int	i;
	int	j;

	coord.z_max = coord.coord[0][0];
	coord.z_min = coord.coord[0][0];
	i = -1;
	while (++i < coord.line_count)
	{
		j = -1;
		while (++j < coord.column_count)
		{
			if (coord.coord[i][j] > coord.z_max)
				coord.z_max = coord.coord[i][j];
			if (coord.coord[i][j] < coord.z_min)
				coord.z_min = coord.coord[i][j];
		}
	}
	coord.z_range = coord.z_max - coord.z_min;
	return (setup_camera(coord));
}

t_iso	init_iso(int x, int y, int z)
{
	t_iso	iso_point;

	iso_point.x = x;
	iso_point.y = y;
	iso_point.z = z;
	return (iso_point);
}

void	project_iso(int *x, int *y, int z)
{
	int	x_tmp;
	int	y_tmp;

	x_tmp = *x;
	y_tmp = *y;
	*x = (x_tmp - y_tmp) * cos(0.523599);
	*y = -z + (x_tmp + y_tmp) * sin(0.523599);
}

t_point	project(t_iso point, t_coord *coord)
{
	t_point	displayed_point;

	displayed_point.r_point = point;
	point.x *= coord->camera.zoom;
	point.y *= coord->camera.zoom;
	point.z *= coord->camera.zoom / coord->camera.z_scale;
	point.x -= (coord->column_count * coord->camera.zoom) / 2;
	point.y -= (coord->line_count * coord->camera.zoom) / 2;
	project_iso(&point.x, &point.y, point.z);
	point.x += WHIDTH / 2 + coord->camera.x_offset;
	point.y += (HEIGHT + coord->line_count * coord->camera.zoom) / 2
		+ coord->camera.y_offset;
	displayed_point.x = point.x;
	displayed_point.y = point.y;
	return (displayed_point);
}

t_point	set_sign(t_point p1, t_point p2)
{
	t_point	sign;

	if (p2.x < p1.x)
		sign.x = 1;
	else
		sign.x = -1;
	if (p2.y < p1.y)
		sign.y = 1;
	else
		sign.y = -1;
	return (sign);
}

void	trace_line(t_point p1, t_point p2, t_mlx *mlx)
{
	t_point	delta;
	t_point	sign;
	t_point	cur;
	int		error[2];

	delta.x = abs(p1.x - p2.x);
	delta.y = abs(p1.y - p2.y);
	sign = set_sign(p1, p2);
	error[0] = delta.x - delta.y;
	cur = p2;
	while (cur.x != p1.x || cur.y != p1.y)
	{
		mlx_pixel_put(mlx->mlx_ptr, mlx->win_ptr, cur.x, cur.y, 0x00FF00);
		error[1] = error[0] * 2;
		if (error[1] > -delta.y)
		{
			error[0] -= delta.y;
			cur.x += sign.x;
		}
		if (error[1] < delta.x)
		{
			error[0] += delta.x;
			cur.y += sign.y;
		}
	}
}

void	display(t_mlx *mlx)
{
	int		i;
	int		j;
	t_iso	p;

	if (mlx->coord->z_range == -10)
		*(mlx->coord) = init_map(*(mlx->coord));
	i = -1;
	while (++i < mlx->coord->line_count)
	{
		j = -1;
		while (++j < mlx->coord->column_count)
		{
			p = init_iso(j, i, mlx->coord->coord[i][j]); // peut etre inverser i et j;
			if (j > 0)
				trace_line(project(p, mlx->coord), project(init_iso(j - 1, i, mlx->coord->coord[i][j - 1]), mlx->coord), mlx);
			if (i > 0)
				trace_line(project(p, mlx->coord), project(init_iso(j, i - 1, mlx->coord->coord[i - 1][j]), mlx->coord), mlx);
		}
	}
}

void	press_esc(t_mlx *mlx)
{
	free_and_quit(mlx);
}

void	press_plus(t_mlx *mlx)
{
	if (mlx->coord->camera.z_scale > 1)
		mlx->coord->camera.z_scale -= 1;
	if (mlx->coord->camera.z_scale < 0)
		mlx->coord->camera.z_scale -= 1;
	if (mlx->coord->camera.z_scale == -20)
		mlx->coord->camera.z_scale = 20;
	display(mlx);
}

void	press_minus(t_mlx *mlx)
{
	if (mlx->coord->camera.z_scale < 20 && mlx->coord->camera.z_scale > 0)
		mlx->coord->camera.z_scale += 1;
	if (mlx->coord->camera.z_scale < -1 && mlx->coord->camera.z_scale < 0)
		mlx->coord->camera.z_scale += 1;
	if (mlx->coord->camera.z_scale == -20)
		mlx->coord->camera.z_scale = 20;
	display(mlx);
}

void	press_w(t_mlx *mlx)
{
	mlx->coord->camera.y_offset -= 25;
	display(mlx);
}

void	press_a(t_mlx *mlx)
{
	mlx->coord->camera.x_offset -= 25;
	display(mlx);
}

void	press_s(t_mlx *mlx)
{
	mlx->coord->camera.y_offset += 25;
	display(mlx);
}

void	press_d(t_mlx *mlx)
{
	mlx->coord->camera.x_offset += 25;
	display(mlx);
}

int	key_press(int key, void *ptr)
{
	if (key == ESC)
		press_esc((t_mlx *) ptr);
	if (key == PLUS)
		press_plus((t_mlx *) ptr);
	if (key == MINUS)
		press_minus((t_mlx *) ptr);
	if (key == W)
		press_w((t_mlx *) ptr);
	if (key == A)
		press_a((t_mlx *) ptr);
	if (key == S)
		press_s((t_mlx *) ptr);
	if (key == D)
		press_d((t_mlx *) ptr);
	return (0);
}

int	mouse_press(int click, int x, int y, t_mlx *mlx)
{
	(void) x;
	(void) y;
	if (click == WHEEL_UP)
		mlx->coord->camera.zoom += 1;
	if (click == WHEEL_DOWN)
	{
		if (mlx->coord->camera.zoom > 0)
			mlx->coord->camera.zoom -= 1;
	}
	display(mlx);
	return (0);
}

t_mlx	*display_fdf(char *win_name, t_coord *coord)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	if (mlx == NULL)
		return (NULL);
	mlx->coord = coord;
	mlx->coord->z_range = -10;
	mlx->mlx_ptr = mlx_init();
	if (mlx->mlx_ptr == NULL)
		return (free_and_quit(mlx));
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WHIDTH, HEIGHT, win_name);
	if (mlx->win_ptr == NULL)
		return (free_and_quit(mlx));
	mlx_key_hook(mlx->win_ptr, key_press, mlx);
	mlx_mouse_hook(mlx->win_ptr, mouse_press, mlx);
	display(mlx);
	mlx_loop(mlx->mlx_ptr);
	return (mlx);
}

int	main(int ac, char **av)
{
	t_coord	*coord;

	if (ac != 2)
	{
		ft_putendl_fd("Please select one map to render", 1);
		return(1);
	}
	coord = parse_map(av[1]);
	if (coord == NULL)
		return (1);
	display_fdf("File de fer", coord);
	return (0);
}
