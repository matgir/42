/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainex00.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 09:52:06 by mgirardo          #+#    #+#             */
/*   Updated: 2021/08/23 16:03:09 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strdup(char *src);

int	main(int ac, char **av)
{
	(void) ac;

	printf("%s\n", strdup(av[1]));
	printf("%s\n", ft_strdup(av[1]));
	return (0);
}
