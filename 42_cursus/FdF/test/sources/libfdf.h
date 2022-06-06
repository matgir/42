/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 16:45:24 by mgirardo          #+#    #+#             */
/*   Updated: 2022/03/31 16:45:27 by mgirardo         ###   ########.fr       */
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
t_coord	*parse_map(char *z_map);
int	**ft_parsing(int fd, int *column_count, int *line_count);
char	*fdf_gnl(int fd, int *gnl_error);
char	*ft_gnl_strjoin(char *line, char *buffer);
void	ft_gnl_strlcpy(char *dst, const char *src, size_t size);
int		ft_gnl_strlen(const char *str);
int		**specifie_error(int **coord, int gnl_error);




/*char	*fdf_get_next_line(int fd);
int		fdf_dbt(char *s);
int		fdf_nw(char *s, size_t stop);
char	**fdf_free_all(char **tab);
char	**ft_fdf_split(char *s, int *x);
int		find_y(char *map);
char	***free_z(char ***z);
char	***ft_store_z(char ***z_coordinates, int fd, int *x);
char	***ft_parsing(char *map_b_parsing, int *y, int *x);
int		main(int ac, char **av);
void	window(int x, int y, t_coord **coo);
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
t_coord	**incorporate_z(t_coord **coo, char ***z_coordinates, int x, int y);
void	draw_line(t_mlx *mlx, t_coord **coo, t_img *img, int x, int y);
void	ft_to_trace(t_mlx *mlx, t_coord coo0, t_coord coo1, t_img *img);*/

#endif
