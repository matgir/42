/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahani <itahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 15:35:56 by itahani           #+#    #+#             */
/*   Updated: 2024/01/14 22:27:41 by itahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

/*------ free tableau -------*/
void	*ft_free(t_vars *var)
{
	int	i;

	i = -1;
	while (var->map[++i])
		free(var->map[i]);
	free(var->map);
	return (NULL);
}

void	*free_config(t_vars *var)
{
	// if (var->config.ceiling)
		// free(var->config.ceiling);
	// if (var->config.floor)
	// 	free(var->config.floor);
	if (var->config.north)
		free(var->config.north);
	if (var->config.south)
		free(var->config.south);
	if (var->config.east)
		free(var->config.east);
	if (var->config.west)
		free(var->config.west);
	return (NULL);
}

/*------ free mlx et fermer programme -------*/
int	free_mlx(t_vars *var)
{
	if (var->mlx && var->img.img)
		mlx_destroy_image(var->mlx, var->img.img);
	if (var->mlx && var->map)
		ft_free(var);
	if (var->mlx && var->infile)
		free_tab(var->infile);
	if (var->mlx && var->config.tab)
		free_tab(var->config.tab);
	free_config(var);
	if (var->mlx && var->win.win)
		mlx_destroy_window(var->mlx, var->win.win);
	destroy_textures(var);
	if (var->mlx)
	{
		mlx_destroy_display(var->mlx);
		free(var->mlx);
	}
	return (1);
	// exit(1);
}

/*------ free mlx only et fermer programme -------*/
int	free_mlxptr(t_vars *var)
{
	
	if (var->mlx)
	{
		mlx_destroy_display(var->mlx);
		free(var->mlx);
	}	return (1);
	// exit(1);
}

/*------ free mlx et map et fermer programme -------*/
int	free_for_parser(t_vars *var)
{
	if (var->mlx && var->map)
		ft_free(var);
	if (var->mlx && var->infile)
		free_tab(var->infile);
	if (var->mlx && var->config.tab)
		free_tab(var->config.tab);
	if (var->mlx)
	{
		mlx_destroy_display(var->mlx);
		free(var->mlx);
	}	return (1);
	// exit(1);
}
