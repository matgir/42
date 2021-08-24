/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmalloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 16:03:26 by mgirardo          #+#    #+#             */
/*   Updated: 2021/08/23 19:32:25 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int *get()
{
	int *tab;

	tab = malloc(sizeof(*tab) * 9);
	return (tab);
}

int	main(void)
{
	int *ptr;

	ptr = get();
	*ptr = -2147483648;
	printf("%d\n", *ptr);
	printf("%p\n", ptr);
	free(ptr);
	printf("%d\n", *ptr);
	printf("%p\n", ptr);
	return (0);
}
