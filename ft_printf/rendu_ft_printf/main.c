/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:41:00 by mgirardo          #+#    #+#             */
/*   Updated: 2022/01/20 14:39:51 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftptf.h"
#include <stdio.h>

int	main(void)
{
	char			c = ' ';
	char			str[] = "et bonjour";
	char			str2[] = "et bonjour";
	char			str3[] = "et bonjour";
	char			str4[] = "et bonjour";
	char			str5[] = "et bonjour";
	int				i = 2147483647;
	unsigned int	ui = -122;

	printf("\n%i\n", ft_printf("%%bonsoir%c%s %i %d %u %x %X %p", c, str, i, i, ui, ui, ui, str));
	printf("\n%i\n", printf("%%bonsoir%c%s %i %d %u %x %X %p", c, str, i, i, ui, ui, ui, str));
}
