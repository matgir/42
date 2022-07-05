/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 11:26:46 by mgirardo          #+#    #+#             */
/*   Updated: 2022/07/05 11:26:58 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"

int	main(int ac, char **av)
{
	if (ft_ps_parsing(ac, av) == 0)
		return (0);
	ft_printf("ready for the real shit");
}
