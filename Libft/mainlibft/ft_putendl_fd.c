/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 18:09:36 by mgirardo          #+#    #+#             */
/*   Updated: 2021/12/20 18:13:42 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_putendl_fd(char *s, int fd);

int	main(int ac, char **av)
{
	(void) ac;

	ft_putendl_fd(av[1], atoi(av[2]));
	return (0);
}
