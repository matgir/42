/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:41:00 by mgirardo          #+#    #+#             */
/*   Updated: 2022/01/19 16:29:41 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftptf.h"
#include <stdio.h>

int	main(void)
{
	char	c = ' ';
	char	str[] = "et bonjour";
	int		i = 2147483647;

	printf("\n%i\n", ft_printf("%%bonsoir%c%s %i %d", c, str, i, i));
	printf("\n%i\n", printf("%%bonsoir%c%s %i %d", c, str, i, i));
}
