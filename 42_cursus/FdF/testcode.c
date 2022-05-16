/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testcode.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:31:30 by mgirardo          #+#    #+#             */
/*   Updated: 2022/05/16 16:31:32 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	count_table_lines(int **table)
{
	int	i;

	i = 0;
	while (table[i] != NULL)
		i++;
	return (i);
}

int	**table_realloc(int **table)
{
	int	**new_table;
	int	i;

	if (!table)
	{
		table = malloc(sizeof(*table));
		if (!table)
			return (NULL);
		table[0] = NULL;
	}
	new_table = malloc(sizeof(*table) * (count_table_lines(table) + 2));
	if (!new_table)
		return (NULL);
	i = -1;
	while (++i < count_table_lines(table))
	{
		new_table[i] = table[i];
	}
	new_table[i++] = NULL;
	new_table[i] = NULL;
	free(table);
	return (new_table);
}

int	*get_int_line(char *line, int *line_size)
{
	char	**split;
	int		*int_line;
	int		length;
	int		i;

	split = ft_split(line, ' ');
	if (!split)
		return (NULL);
	length = 0;
	while (split[length] != NULL)
		length++;
	int_line = malloc(sizeof(int) * (length));
	if (int_line)
	{
		i = -1;
		while (++i < length)
			int_line[i] = ft_atoi(split[i]);
		*line_size = i;
	}
	length = -1;
	while (split[++length] != NULL)
		free(split[length]);
	free(split);
	return (int_line);
}

int	**process_line(char *line, int **table, int *line_size)
{
	int	*int_line;

	table = table_realloc(table);
	if (!table)
		return (NULL);
	int_line = get_int_line(line, line_size);
	if (!int_line)
		return (NULL);
	if (count_table_lines(table) == 0)
		table[0] = int_line;
	else
		table[count_table_lines(table)] = int_line;
	return (table);
}

int	**read_error(int **table, int status)
{
	int	i;

	i = -1;
	if (!table)
	{
		while (table[++i] != NULL)
			free(table[i]);
		free(table);
	}
	if (status == -1)
		ft_putendl_fd("Memory allocation error", 1);
	if (status == -2)
		perror("The specified file cannot be read");
	if (status == -3)
		ft_putendl_fd("Impossible to parse file", 1);
	return (NULL);
}

int	**read_file(int fd, int *line_size, int *line_count)
{
	char	*line;
	int		status;
	int		**table;

	table = NULL;
	status = 0;
	while (TRUE)
	{
		line = get_next_line(fd, &status);
		if (!line)
		{
			if (status < 0)
				return (read_error(table, status));
			break ;
		}
		*line_count = *line_count + 1;
		table = process_line(line, table, line_size);
		if (!table)
		{
			free(line);
			return (read_error(table, -3));
		}
		free(line);
	}
	return (table);
}

t_map	*parse_map(char *file)
{
	int		fd;
	int		**table;
	int		line_size;
	int		line_count;
	t_map	*map;

	line_count = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror("The specified file cannot be open");
		return (NULL);
	}
	table = read_file(fd, &line_size, &line_count);
	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->map = table;
	map->line_count = line_count;
	map->line_size = line_size;
	close(fd);
	return (map);
}

t_mlx	*quit_before_start(t_mlx *mlx)
{
	int	i;

	i = -1;
	while (++i < mlx->map->line_count)
	{
		free((mlx->map->map)[i]);
	}
	free(mlx->map->map);
	free(mlx->map);
	free(mlx);
	if (mlx->mlx_ptr && mlx->window_ptr)
		mlx_destroy_window(mlx->mlx_ptr, mlx->window_ptr);
	if (mlx->mlx_ptr)
	{
		mlx_destroy_display(mlx->mlx_ptr);
		free(mlx->mlx_ptr);
	}
	return (NULL);
}

void	press_up(t_mlx *mlx)
{
	mlx->map->camera.alpha += 0.05;
	mlx->map->colors = FALSE;
	display(mlx);
}

void	press_down(t_mlx *mlx)
{
	mlx->map->camera.alpha -= 0.05;
	mlx->map->colors = FALSE;
	display(mlx);
}

void	press_left(t_mlx *mlx)
{
	mlx->map->camera.gamma += 0.05;
	mlx->map->colors = FALSE;
	display(mlx);
}

void	press_right(t_mlx *mlx)
{
	mlx->map->camera.gamma -= 0.05;
	mlx->map->colors = FALSE;
	display(mlx);
}

void	press_ctrl(t_mlx *mlx)
{
	mlx->map->camera.beta += 0.05;
	mlx->map->colors = FALSE;
	display(mlx);
}

void	press_option(t_mlx *mlx)
{
	mlx->map->camera.beta -= 0.05;
	mlx->map->colors = FALSE;
	display(mlx);
}

void	press_plus(t_mlx *mlx)
{
	if (mlx->map->camera.z_scale > 1)
		mlx->map->camera.z_scale -= 1;
	if (mlx->map->camera.z_scale < 0)
		mlx->map->camera.z_scale -= 1;
	if (mlx->map->camera.z_scale == -20)
		mlx->map->camera.z_scale = 20;
	mlx->map->colors = FALSE;
	display(mlx);
}

void	press_minus(t_mlx *mlx)
{
	if (mlx->map->camera.z_scale < 20 && mlx->map->camera.z_scale > 0)
		mlx->map->camera.z_scale += 1;
	if (mlx->map->camera.z_scale < -1 && mlx->map->camera.z_scale < 0)
		mlx->map->camera.z_scale += 1;
	if (mlx->map->camera.z_scale == 20)
		mlx->map->camera.z_scale = -20;
	mlx->map->colors = FALSE;
	display(mlx);
}

void	press_w(t_mlx *mlx)
{
	mlx->map->camera.y_offset -= 25;
	mlx->map->colors = FALSE;
	display(mlx);
}

void	press_a(t_mlx *mlx)
{
	mlx->map->camera.x_offset -= 25;
	mlx->map->colors = FALSE;
	display(mlx);
}

void	press_s(t_mlx *mlx)
{
	mlx->map->camera.y_offset += 25;
	mlx->map->colors = FALSE;
	display(mlx);
}

void	press_d(t_mlx *mlx)
{
	mlx->map->camera.x_offset += 25;
	mlx->map->colors = FALSE;
	display(mlx);
}

void	press_c(t_mlx *mlx)
{
	if (mlx->map->colors)
		mlx->map->colors = FALSE;
	else
		mlx->map->colors = TRUE;
	display(mlx);
}

void	press_p(t_mlx *mlx)
{
	if (mlx->map->camera.proj == ISO)
		mlx->map->camera.proj = PARALLEL;
	else
		mlx->map->camera.proj = ISO;
	mlx->map->camera.alpha = 0;
	mlx->map->camera.beta = 0;
	mlx->map->camera.gamma = 0;
	display(mlx);
}


void	press_escape(t_mlx *mlx)
{
	quit(mlx);
}

int	handle_key2(int key, void *ptr)
{
	if (key == W)
		press_w((t_mlx *) ptr);
	if (key == A)
		press_a((t_mlx *) ptr);
	if (key == S)
		press_s((t_mlx *) ptr);
	if (key == D)
		press_d((t_mlx *) ptr);
	if (key == C)
		press_c((t_mlx *) ptr);
	if (key == P)
		press_p((t_mlx *) ptr);
	return (0);
}

int	handle_key(int key, void *ptr)
{
	if (key == ESC)
		press_escape((t_mlx *) ptr);
	if (key == UP)
		press_up((t_mlx *) ptr);
	if (key == LEFT)
		press_left((t_mlx *) ptr);
	if (key == DOWN)
		press_down((t_mlx *) ptr);
	if (key == RIGHT)
		press_right((t_mlx *) ptr);
	if (key == OPTION)
		press_option((t_mlx *) ptr);
	if (key == CTRL_RIGHT)
		press_ctrl((t_mlx *) ptr);
	if (key == PLUS)
		press_plus((t_mlx *) ptr);
	if (key == MINUS)
		press_minus((t_mlx *) ptr);
	return (handle_key2(key, ptr));
}

t_mlx	*init_window(char *name, t_map *map)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		return (NULL);
	mlx->mlx_ptr = NULL;
	mlx->window_ptr = NULL;
	mlx->map = map;
	mlx->map->z_range = -10;
	mlx->map->colors = FALSE;
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		return (quit_before_start(mlx));
	mlx->window_ptr = mlx_new_window(mlx->mlx_ptr, WIDTH, HEIGHT, name);
	if (!mlx->window_ptr)
		return (quit_before_start(mlx));
	mlx_key_hook(mlx->window_ptr, handle_key, mlx);
	mlx_mouse_hook(mlx->window_ptr, handle_mouse, mlx);
	display(mlx);
	mlx_loop(mlx->mlx_ptr);
	return (mlx);
}

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc != 2)
	{
		ft_putendl_fd("Please specify one map", 1);
		return (1);
	}
	map = parse_map(argv[1]);
	if (!map)
		return (1);
	init_window("Fdf", map);
	return (0);
}

void	quit(t_mlx *mlx)
{
	int	i;

	i = -1;
	while (++i < mlx->map->line_count)
	{
		free((mlx->map->map)[i]);
	}
	free(mlx->map->map);
	free(mlx->map);
	mlx_loop_end(mlx->mlx_ptr);
	mlx_destroy_window(mlx->mlx_ptr, mlx->window_ptr);
	mlx_destroy_display(mlx->mlx_ptr);
	free(mlx->mlx_ptr);
	free(mlx);
	exit(0);
}



int	get_color(t_3d_point point, int z_min, int z_max)
{
	int	step;
	int	current_z;
	int	red;
	int	green;
	int	blue;

	step = z_max - z_min;
	current_z = point.z - z_min;
	if (current_z <= step / 2)
	{
		blue = 0;
		red = 255 - ((510 * current_z) / step);
		green = 255 - red;
	}
	else
	{
		red = 0;
		blue = (255 * current_z) / step;
		green = 255 - blue;
	}
	return (encode_rgb(red, green, blue));
}

int	get_red(t_3d_point point, int z_min, int z_max)
{
	int	step;
	int	current_z;

	step = z_max - z_min;
	current_z = point.z - z_min;
	if (current_z <= step / 2)
		return (255 - ((510 * current_z) / step));
	else
		return (0);
}

int	get_blue(t_3d_point point, int z_min, int z_max)
{
	int	step;
	int	current_z;

	step = z_max - z_min;
	current_z = point.z - z_min;
	if (current_z <= step / 2)
		return (0);
	else
		return ((255 * current_z) / step);
}

int	get_green(t_3d_point point, int z_min, int z_max)
{
	int	step;
	int	current_z;

	step = z_max - z_min;
	current_z = point.z - z_min;
	if (current_z <= step / 2)
		return (255 - (255 - ((510 * current_z) / step)));
	else
		return (255 - ((255 * current_z) / step));
}

void	display_points(t_mlx *mlx)
{
	int			i;
	int			j;
	t_3d_point	p;

	if (mlx->map->z_range == -10)
		*(mlx->map) = init_map(*(mlx->map));
	i = -1;
	while (++i < mlx->map->line_count)
	{
		j = -1;
		while (++j < mlx->map->line_size)
		{
			p = init_3d_point(j, i, mlx->map->map[i][j]);
			if (j > 0)
				trace_line(project(p, mlx->map), project(init_3d_point(j - 1,
							i, mlx->map->map[i][j - 1]), mlx->map), mlx);
			if (i > 0)
				trace_line(project(p, mlx->map), project(init_3d_point(j,
							i - 1, mlx->map->map[i - 1][j]), mlx->map), mlx);
		}
	}
}

void	display_background(t_mlx *mlx, int color)
{
	int		x;
	int		y;
	void	*img_ptr;
	int		*data;
	int		useless;

	img_ptr = mlx_new_image(mlx->mlx_ptr, WIDTH, HEIGHT);
	data = (int *)mlx_get_data_addr(img_ptr, &useless, &useless, &useless);
	x = -1;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			data[y * WIDTH + x] = color;
		}
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->window_ptr, img_ptr, 0, 0);
	mlx_destroy_image(mlx->mlx_ptr, img_ptr);
}

void	display_menu_2(t_mlx *mlx, int text_color)
{
	if (mlx->map->camera.proj == ISO)
		mlx_string_put(mlx->mlx_ptr, mlx->window_ptr, 30, 330, text_color,
			"Current projection: Isometric");
	if (mlx->map->camera.proj == PARALLEL)
		mlx_string_put(mlx->mlx_ptr, mlx->window_ptr, 30, 330, text_color,
			"Current projection: Parallel");
}

void	display_menu_string(t_mlx *mlx, int text_color)
{
	mlx_string_put(mlx->mlx_ptr, mlx->window_ptr, 30, 50, text_color,
		"Arrows UP / DOWN | Rotate X axis");
	mlx_string_put(mlx->mlx_ptr, mlx->window_ptr, 30, 70, text_color,
		"Arrows RIGHT / LEFT | Rotate Z axis");
	mlx_string_put(mlx->mlx_ptr, mlx->window_ptr, 30, 90, text_color,
		"CTRL right / OPT right | Rotate Y axis");
	mlx_string_put(mlx->mlx_ptr, mlx->window_ptr, 30, 130, text_color,
		"Wheel UP / DOWN | Zoom in/out");
	mlx_string_put(mlx->mlx_ptr, mlx->window_ptr, 30, 170, text_color,
		"Keypad + / - | Change Z scale");
	mlx_string_put(mlx->mlx_ptr, mlx->window_ptr, 30, 210, text_color,
		"W / A / S / D | Move projection");
	mlx_string_put(mlx->mlx_ptr, mlx->window_ptr, 30, 250, text_color,
		"C | Toggle color mod");
	mlx_string_put(mlx->mlx_ptr, mlx->window_ptr, 30, 265, text_color,
		"(All projection movements disable");
	mlx_string_put(mlx->mlx_ptr, mlx->window_ptr, 30, 280, text_color,
		" colors to reduce lag)");
	mlx_string_put(mlx->mlx_ptr, mlx->window_ptr, 30, 310, text_color,
		"P | Toggle projection (Iso, Parallel)");
	display_menu_2(mlx, text_color);
}

void	display_menu(t_mlx *mlx, int background_color, int text_color)
{
	int		x;
	int		y;
	void	*img_ptr;
	int		*data;
	int		useless;

	img_ptr = mlx_new_image(mlx->mlx_ptr, MENU_WIDTH, HEIGHT);
	data = (int *)mlx_get_data_addr(img_ptr, &useless, &useless, &useless);
	x = -1;
	while (++x < MENU_WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
		{
			data[y * MENU_WIDTH + x] = background_color;
		}
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->window_ptr, img_ptr, 0, 0);
	mlx_destroy_image(mlx->mlx_ptr, img_ptr);
	display_menu_string(mlx, text_color);
}



void	display(t_mlx *mlx)
{
	display_background(mlx, encode_rgb(0, 0, 0));
	display_points(mlx);
	display_menu(mlx, encode_rgb(0, 0, 0), encode_rgb(255, 255, 255));
}

int	encode_rgb(int red, int green, int blue)
{
	return (red << 16 | green << 8 | blue);
}

int	get_gradient(int c1, int c2, float d1, float d2)
{
	float		range;
	float		part;

	range = c1 - c2;
	part = d2 / (d1 + d2);
	return (c2 + (part * range));
}

int	get_gradient_color(t_point point1, t_point point2, t_point cur, t_map *map)
{
	float	distance1;
	float	distance2;

	distance1 = sqrt(pow(abs(point1.x - cur.x), 2)
			+ pow(abs(point1.y - cur.y), 2));
	distance2 = sqrt(pow(abs(point2.x - cur.x), 2)
			+ pow(abs(point2.y - cur.y), 2));
	return (encode_rgb(get_gradient(get_red(point1.real_point, map->z_min,
					map->z_max), get_red(point2.real_point, map->z_min,
					map->z_max), distance1, distance2),
			get_gradient(get_green(point1.real_point, map->z_min, map->z_max),
				get_green(point2.real_point, map->z_min, map->z_max), distance1,
				distance2), get_gradient(get_blue(point1.real_point,
					map->z_min, map->z_max), get_blue(point2.real_point,
					map->z_min, map->z_max), distance1, distance2)));
}

void	color_pixel(t_mlx *mlx, t_point cur, t_point point1, t_point point2)
{
	if (mlx->map->colors)
		mlx_pixel_put(mlx->mlx_ptr, mlx->window_ptr, cur.x,
			cur.y, get_gradient_color(point1, point2, cur, mlx->map));
	else
		mlx_pixel_put(mlx->mlx_ptr, mlx->window_ptr, cur.x,
			cur.y, encode_rgb(100, 200, 100));
}

t_point	set_sign(t_point point1, t_point point2)
{
	t_point	sign;

	if (point2.x < point1.x)
		sign.x = 1;
	else
		sign.x = -1;
	if (point2.y < point1.y)
		sign.y = 1;
	else
		sign.y = -1;
	return (sign);
}

void	trace_line(t_point point1, t_point point2, t_mlx *mlx)
{
	t_point	delta;
	t_point	sign;
	t_point	cur;
	int		error[2];

	delta.x = abs(point1.x - point2.x);
	delta.y = abs(point1.y - point2.y);
	sign = set_sign(point1, point2);
	error[0] = delta.x - delta.y;
	cur = point2;
	while (cur.x != point1.x || cur.y != point1.y)
	{
		color_pixel(mlx, cur, point1, point2);
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

t_3d_point	init_3d_point(int x, int y, int z)
{
	t_3d_point	point;

	point.x = x;
	point.y = y;
	point.z = z;
	return (point);
}

void	rotate_x(int *y, int *z, double alpha)
{
	int	previous_y;

	previous_y = *y;
	*y = previous_y * cos(alpha) + *z * sin(alpha);
	*z = -previous_y * sin(alpha) + *z * cos(alpha);
}

void	rotate_y(int *x, int *z, double beta)
{
	int	previous_x;

	previous_x = *x;
	*x = previous_x * cos(beta) + *z * sin(beta);
	*z = -previous_x * sin(beta) + *z * cos(beta);
}

void	rotate_z(int *x, int *y, double gamma)
{
	int	previous_x;
	int	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = previous_x * cos(gamma) - previous_y * sin(gamma);
	*y = previous_x * sin(gamma) + previous_y * cos(gamma);
}

void	project_iso(int *x, int *y, int z)
{
	int	previous_x;
	int	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -z + (previous_x + previous_y) * sin(0.523599);
}

t_point	project(t_3d_point point, t_map *map)
{
	t_point	projected_point;

	projected_point.real_point = point;
	point.x *= map->camera.zoom;
	point.y *= map->camera.zoom;
	point.z *= map->camera.zoom / map->camera.z_scale;
	point.x -= (map->line_size * map->camera.zoom) / 2;
	point.y -= (map->line_count * map->camera.zoom) / 2;
	rotate_x(&point.y, &point.z, map->camera.alpha);
	rotate_y(&point.x, &point.z, map->camera.beta);
	rotate_z(&point.x, &point.y, map->camera.gamma);
	if (map->camera.proj == ISO)
		project_iso(&point.x, &point.y, point.z);
	point.x += (WIDTH - MENU_WIDTH) / 2 + map->camera.x_offset;
	point.y += (HEIGHT + map->line_count * map->camera.zoom)
		/ 2 + map->camera.y_offset;
	projected_point.x = point.x;
	projected_point.y = point.y;
	return (projected_point);
}

int	min(int i1, int i2)
{
	if (i1 < i2)
		return (i1);
	return (i2);
}

t_map	setup_camera(t_map map)
{
	map.camera.zoom = min(WIDTH / map.line_size / 2,
			HEIGHT / map.line_count / 2);
	map.camera.alpha = 0;
	map.camera.beta = 0;
	map.camera.gamma = 0;
	map.camera.z_scale = 7;
	map.camera.x_offset = MENU_WIDTH;
	map.camera.y_offset = -250;
	map.camera.proj = ISO;
	return (map);
}

t_map	init_map(t_map map)
{
	int	i;
	int	j;

	map.z_max = map.map[0][0];
	map.z_min = map.map[0][0];
	i = -1;
	while (++i < map.line_count)
	{
		j = -1;
		while (++j < map.line_size)
		{
			if (map.map[i][j] > map.z_max)
				map.z_max = map.map[i][j];
			if (map.map[i][j] < map.z_min)
				map.z_min = map.map[i][j];
		}
	}
	map.z_range = map.z_max - map.z_min;
	return (setup_camera(map));
}





void	up(t_mlx *mlx)
{
	mlx->map->camera.zoom += 1;
	mlx->map->colors = FALSE;
	display(mlx);
}

void	down(t_mlx *mlx)
{
	if (mlx->map->camera.zoom > 0)
		mlx->map->camera.zoom -= 1;
	mlx->map->colors = FALSE;
	display(mlx);
}

int	handle_mouse(int button, int x, int y, void *ptr)
{
	(void) x;
	(void) y;
	if (button == WHEEL_UP)
		up((t_mlx *) ptr);
	if (button == WHEEL_DOWN)
		down((t_mlx *) ptr);
	return (0);
}

















