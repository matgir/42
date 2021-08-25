/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainex04.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 15:49:40 by mgirardo          #+#    #+#             */
/*   Updated: 2021/08/25 12:36:16 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_putnbr_base(int nbr, char *base);

int	main(int argc, char **argv)
{
	(void) argc;
	ft_putnbr_base(atoi(argv[1]), argv[2]);
	return (0);
}
