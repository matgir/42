/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:41:00 by mgirardo          #+#    #+#             */
/*   Updated: 2022/01/21 10:55:23 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int	main(void)
{
	char			c = ' ';
	char			str[] = "et bonjour";
	int				i = 2147483647;
	unsigned int	ui = -122;

	printf("\n%i\n", ft_printf("%%bonsoir%c%s %i %d %u %x %X %p %s", c, str, i, i, ui, ui, ui, str, NULL));
	printf("\n%i\n", printf("%%bonsoir%c%s %i %d %u %x %X %p %s", c, str, i, i, ui, ui, ui, str, NULL));
	printf(" NULL %s NULL ", NULL);
	printf("\n%i\n", printf(" %p %p ", 0, 0));
	printf("\n%i\n", ft_printf(" %p %p ", test, test));
}
