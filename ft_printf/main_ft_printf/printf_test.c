/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:59:42 by mgirardo          #+#    #+#             */
/*   Updated: 2022/01/17 14:34:54 by mgirardo         ###   ########.fr       */
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
	printf("\n%d\n", i);
	printf("%p\n", &i);
	printf("%p\n", pointeur);
	printf("%s\n", tmp);

	return (0);
}
