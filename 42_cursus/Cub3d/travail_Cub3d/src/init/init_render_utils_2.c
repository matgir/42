/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_render_utils_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:56:37 by mgirardo          #+#    #+#             */
/*   Updated: 2024/01/15 14:56:40 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	hexa_str_to_int(t_color *color, int *hex)
{
	int	res;
	int	i;
	int	c;

	i = 2;
	res = 0;
	while (color->hexa[i])
	{
		c = hexa_char_to_int(color->hexa[i]);
		res = res * 16 + c;
		i++;
	}
	*hex = res;
}
