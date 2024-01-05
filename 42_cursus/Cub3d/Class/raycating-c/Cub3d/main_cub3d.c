#include "cub3d.h"

void	ft_write_str(char *str)
{
	while (*str)
		write(2, str++, 1);
	return;
}

int	ft_exit(char *str)
{
	ft_write_str("Error\n");
	ft_write_str(str);
	exit(1);
	return TRUE;
}

void	ft_destroy(t_mlx *mlx)
{
	if (mlx->graph_ptr && mlx->win_ptr)
		mlx_destroy_window(mlx->graph_ptr, mlx->win_ptr);
	if (mlx->graph_ptr)
		mlx_destroy_display(mlx->graph_ptr);
	free(mlx);
	return;
}

int	main()
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		return ft_exit("specific error message 1\n");

	mlx->graph_ptr = mlx_init();
	if (!mlx->graph_ptr)
		return ft_exit("specific error message 2\n");
	
	mlx->win_ptr = mlx_new_window(mlx->graph_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, GAME_NAME);
	if (mlx->win_ptr)
		return ft_exit("specific error message 3\n");

	mlx_loop(mlx->graph_ptr);

	ft_destroy(mlx);

	return 0;
}