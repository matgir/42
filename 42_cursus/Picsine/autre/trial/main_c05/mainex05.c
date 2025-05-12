/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainex05.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 19:27:28 by mgirardo          #+#    #+#             */
/*   Updated: 2021/08/24 11:50:05 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_sqrt(int nb);

int	main(int ac, char **av)
{
	(void) ac;
	printf("%d\n", ft_sqrt(atoi(av[1])));
	return (0);
}
