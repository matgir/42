/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahani <itahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 19:44:43 by itahani           #+#    #+#             */
/*   Updated: 2023/11/07 21:34:25 by itahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	check_cr(char *valeur)
{
	int	x;

	x = -1;
	while (valeur[++x])
	{
		if (valeur[x] == '\n' && valeur[x + 1] == '\n')
			return (ft_putstr_fd("Error : too many \\n in map\n", 2), 1);
	}
	return (0);
}
