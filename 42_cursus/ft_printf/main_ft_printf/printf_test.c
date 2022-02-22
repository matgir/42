/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:59:42 by mgirardo          #+#    #+#             */
/*   Updated: 2022/01/17 16:55:56 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(void)
{
	char	*w;
	w = "58";
	printf("\n58 devient %p avec p\n", w);

	int	i = 100;
	int	*pointeur = &i;
	char	p = '5';
	char	*tmp = &p;
	printf("\n%d, 1\n", i);
	printf("%p, 2\n", &i);
	printf("%p, 3\n", pointeur);
	printf("%i, 4\n", pointeur);
	printf("%i, 5\n", tmp);
	printf("%s, 6\n", tmp);
	printf("%p, 7\n", &p);
	printf("%p, 8\n", tmp);
	printf("%u, 9\n", printf(""));

	return (0);
}
