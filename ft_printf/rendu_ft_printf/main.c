/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:41:00 by mgirardo          #+#    #+#             */
/*   Updated: 2022/01/20 12:12:06 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftptf.h"
#include <stdio.h>

int	main(void)
{
	char			c = ' ';
	char			str[] = "et bonjour";
	int				i = 2147483647;
	unsigned int	ui = 122;

	printf("\n%i\n", ft_printf("%%bonsoir%c%s %i %d %X", c, str, i, i, ui));
	printf("\n%i\n", printf("%%bonsoir%c%s %i %d %X", c, str, i, i, ui));
}
