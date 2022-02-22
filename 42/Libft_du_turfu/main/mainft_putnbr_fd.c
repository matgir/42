/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 18:31:37 by mgirardo          #+#    #+#             */
/*   Updated: 2021/12/20 18:34:06 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_putnbr_fd(int n, int fd);

int		main(int ac, char **av)
{
	(void) ac;

	ft_putnbr_fd(atoi(av[1]), atoi(av[2]));
	return (0);
}
