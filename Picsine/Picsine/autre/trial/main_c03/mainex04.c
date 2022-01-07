/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainex04.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 10:00:51 by mgirardo          #+#    #+#             */
/*   Updated: 2021/08/19 14:44:21 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strstr(char *str, char *to_find);

int	main(int ac ,char **av)
{
	(void) ac;

	printf("%s\n", strstr(av[1], av[2]));
	printf("%s\n", ft_strstr(av[1], av[2]));
	return (0);
}
