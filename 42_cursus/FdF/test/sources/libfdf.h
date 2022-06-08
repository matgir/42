/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 16:45:24 by mgirardo          #+#    #+#             */
/*   Updated: 2022/06/07 17:21:24 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFDF_H
# define LIBFDF_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"

# define BUFFER_SIZE 42

# define WHIDTH 1920
# define HEIGHT 960

# define ESC 65307
# define PLUS 65451
# define MINUS 65453
# define W 119
# define A 97
# define S 115
# define D 100

# define LEFT_CLICK 1
# define RIGHT_CLICK 3
# define WHEEL_DOWN 4
# define WHEEL_UP 5

# define TRUE 1

typedef struct s_iso
{
	int	x;
	int	y;
	int	z;
}				t_iso;

typedef struct s_point
{
	int		x;
	int		y;
	t_iso	r_point;
}				t_point;

typedef struct s_camera
{
	int		zoom;
	float	z_scale;
	int		x_offset;
	int		y_offset;
}				t_camera;

typedef struct s_coord
{
	int			**coord;
	int			line_count;
	int			column_count;
	int			z_range;
	int			z_max;
	int			z_min;
	t_camera	camera;
}				t_coord;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_coord	*coord;
}				t_mlx;

typedef struct i_data
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

int		main(int ac, char **av);
t_mlx	*display_fdf(char *win_name, t_coord *coord);
int		mouse_press(int click, int x, int y, t_mlx *mlx);
int		key_press(int key, void *ptr);
void	press_d(t_mlx *mlx);
void	press_s(t_mlx *mlx);
void	press_a(t_mlx *mlx);
void	press_w(t_mlx *mlx);
void	press_minus(t_mlx *mlx);
void	press_plus(t_mlx *mlx);
void	press_esc(t_mlx *mlx);
int		quit(t_mlx *mlx);
t_mlx	*display(t_mlx *mlx);
void	trace_line(t_point p1, t_point p2, t_img *img);
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
t_point	set_sign(t_point p1, t_point p2);
t_point	project(t_iso point, t_coord *coord);
void	project_iso(int *x, int *y, int z);
t_iso	init_iso(int x, int y, int z);
t_coord	init_map(t_coord coord);
t_coord	setup_camera(t_coord coord);
int		def_min(int w, int h);
t_mlx	*free_and_quit(t_mlx *mlx);
t_mlx	*free_and_quit_img(t_mlx *mlx, t_img *img);
t_coord	*parse_map(char *z_map);
int		**ft_parsing(int fd, int *column_count, int *line_count);
int		count_lines(char *z_map);
int		**add_line(char *line, int **coord, int *column_count);
int		*get_int(char *line, int *column_count);
int		**add_coord(int **coord);
int		coord_current_lines(int **coord);
int		**specifie_error(int **coord, int gnl_error);
char	**ft_fdf_split(char *s, char *x);
char	**fdf_free_all(char **tab);
int		fdf_nw(char *s, size_t stop);
int		fdf_dbt(char *s);
char	*fdf_gnl(int fd, int *gnl_error);
char	*ft_gnl_strjoin(char *line, char *buffer);
void	ft_gnl_strlcpy(char *dst, const char *src, size_t size);
int		ft_gnl_strlen(const char *str);
void	fill_img(t_point delta, t_point cur, t_point p1, t_img *img);
int		first_check(int *line_count, char *z_map, int *fd);
int		check_buf_n_fd(int fd, int *gnl_error);
int		check_line(char *line, int *gnl_error);
int		check_end(int end, char *line, int *gnl_error);
int		malloc_check(char *line, int **coord, int *gnl_error);

#endif
