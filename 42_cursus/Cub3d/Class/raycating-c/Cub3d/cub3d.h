#ifndef CONSTANT_H
# define CONSTANT_H

# include <stdio.h>
# include "minilibx-linux/mlx.h"
# include <stdlib.h>
# include <unistd.h>

# define	FALSE 0
# define	TRUE 1

# define	WINDOW_WIDTH 1920
# define	WINDOW_HEIGHT 960

# define	GAME_NAME "The Cub3d"

typedef struct	s_mlx
{
	void	*graph_ptr;
	void	*win_ptr;
}				t_mlx;

#endif