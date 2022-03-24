/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 11:09:50 by mgirardo          #+#    #+#             */
/*   Updated: 2022/03/24 11:09:53 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

int	main(void)
{
	void	*mlx;
	void	*mlx_wind;

	mlx = mlx_init();
	mlx_wind = mlx_new_window(mlx, 1920, 1080, "Hello world !");
	mlx_loop(mlx);
}