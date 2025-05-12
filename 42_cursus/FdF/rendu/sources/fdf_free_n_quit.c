/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_n_quit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:46:20 by mgirardo          #+#    #+#             */
/*   Updated: 2022/06/20 16:46:24 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

t_mlx	*free_and_quit(t_mlx *mlx)
{
	int	i;

	i = -1;
	while (++i < mlx->coord->line_count)
		free((mlx->coord->coord)[i]);
	free(mlx->coord->coord);
	free(mlx->coord);
	free(mlx);
	return (NULL);
}

t_mlx	*free_and_quit_win(t_mlx *mlx)
{
	int	i;

	if (mlx->mlx_ptr)
		mlx_destroy_display(mlx->mlx_ptr);
	i = -1;
	while (++i < mlx->coord->line_count)
		free((mlx->coord->coord)[i]);
	free(mlx->coord->coord);
	free(mlx->coord);
	free(mlx);
	return (NULL);
}

int	free_and_quit_img(t_mlx *mlx)
{
	int	i;

	if (mlx->mlx_ptr && mlx->win_ptr)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	if (mlx->mlx_ptr)
		mlx_destroy_display(mlx->mlx_ptr);
	i = -1;
	while (++i < mlx->coord->line_count)
		free((mlx->coord->coord)[i]);
	free(mlx->coord->coord);
	free(mlx->coord);
	free(mlx);
	return (0);
}
