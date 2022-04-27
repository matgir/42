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
# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"

typedef struct	c_data
{
	float	x_axe;
	float	y_axe;
}				coord;

typedef struct	s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}				mlx;

typedef struct	v_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				i_data;

int		fdf_dbt(char *s);
int		fdf_nw(char *s, size_t stop);
char	**fdf_free_all(char **tab);
char	**ft_fdf_split(char *s, int *x);
int		find_y(char *map);
char	***free_z(char ***z);
char	***ft_store_z(char ***z_coordinates, int fd, int *x);
char	***ft_parsing(char *map_b_parsing, int *y, int *x);
int		main(int ac, char **av);
void	window(int x, int y, coord **coo);
void	my_mlx_pixel_put(i_data *data, int x, int y, int color);

#endif
