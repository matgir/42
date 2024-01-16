/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahani <itahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 20:09:34 by itahani           #+#    #+#             */
/*   Updated: 2024/01/14 20:30:21 by itahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_write_str(char *str)
{
	int i;

	while (*str)
		 i = write(2, str++, 1);
	(void)i;
	return (1);
}

int	ft_exit(char *str)
{
	ft_write_str("Error\n");
	ft_write_str(str);
	exit(1);
	return (0);
}

int	entry_test(t_vars *var, int fd, char *argv)
{
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		return (ft_exit("Map not read\n"));
	if (check_extension(argv) == 1)
		return (close(fd), ft_exit("<filename.cub> needed\n"));
	var->mlx = mlx_init();
	if (!var->mlx)
		return (close(fd), ft_exit("Could not use graphical tools\n"));
	var->infile = cub_to_tab(fd);
	if (var->infile == NULL)
		return (close(fd), free_mlxptr(var), ft_exit("Could not malloc\n"));
	var->map = get_map(var, var->infile);
	if (var->map == NULL)
		return (close(fd), free_tab(var->infile), free_mlxptr(var), ft_exit("Invalid identifier\n"));
	parsing(var, fd);
	// if (parsing(var) == 1)
	// 	return (close(fd), free_for_parser(var), ft_exit("Invalid map\n"));
	return (0);
}

int	main(int argc, char *argv[])
{
	int		fd;
	t_vars	var;

	if (argc == 2)
	{
		fd = 0;
		entry_test(&var, fd, argv[1]);
			// {
			// 	fd = open(argv[1], O_RDONLY);
			// 	if (fd == -1)
			// 		return (print_error("map not read\n"), 1);
			// 	if (check_extension(argv[1]) == 1)
			// 		return (print_error("file.cub needed\n"), close(fd), 1);
			// 	var.mlx = mlx_init();
			// 	if (!var.mlx)
			// 		return (close(fd), 1);
			// 	if ((var.infile = cub_to_tab(fd)) == NULL)
			// 		return (close(fd), free_mlxptr(&var), 1);
			// 	if ((var.map = get_map(&var, var.infile)) == NULL)
			// 		return (close(fd), free_tab(var.infile), free_mlxptr(&var), 1);
			// 	if (parsing(&var) == 1)
			// 		return (close(fd), free_for_parser(&var), 1);
			// }			
		def_var(&var);
		mlx_put_image_to_window(var.mlx, var.win.win, var.img.img, 0, 0);
		mlx_hook(var.win.win, 2, 1L << 0, key_hook, &var);
		mlx_hook(var.win.win, 17, 0, free_mlx, &var); // clic sur la croix
		mlx_loop(var.mlx);
	}
	else
		print_error("Invalid number of arguments\n");
	return (0);
}
