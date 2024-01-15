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

int	main(int argc, char *argv[]) //ajouter destroy_textures() partout ou ca quitte le programme
{
	int		fd;
	t_vars	var;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			return (print_error("map not read\n"), 1);
		if (check_extension(argv[1]) == 1)
			return (print_error("file.cub needed\n"), close(fd), 1);
		var.mlx = mlx_init();
		if (!var.mlx)
			return (close(fd), 1);
		if ((var.infile = cub_to_tab(fd)) == NULL)
			return (close(fd), free_mlxptr(&var), 1);
		if ((var.map = get_map(&var, var.infile)) == NULL)
			return (close(fd), free_tab(var.infile), free_mlxptr(&var), 1);
		if (parsing(&var) == 1)
			return (close(fd), free_for_parser(&var), 1);
		def_var(&var);
		mlx_put_image_to_window(var.mlx, var.win.win, var.img.img, 0, 0);
		mlx_hook(var.win.win, 2, 1L<<0, key_hook, &var);
		mlx_hook(var.win.win, 17, 0, free_mlx, &var); // clic sur la croix
		mlx_loop(var.mlx);
	}
	else
		print_error("Invalid number of arguments\n");
	return (0);
}
