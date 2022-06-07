/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 16:38:59 by mgirardo          #+#    #+#             */
/*   Updated: 2022/06/07 17:21:37 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfdf.h"

int	main(int ac, char **av)
{
	t_coord	*coord;

	if (ac != 2)
	{
		ft_putendl_fd("Please select one map to render", 1);
		return(1);
	}
	coord = parse_map(av[1]);
	if (coord == NULL)
		return (1);
	display_fdf("File de fer", coord);
	return (0);
}
