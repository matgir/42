/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainft_calloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:10:56 by mgirardo          #+#    #+#             */
/*   Updated: 2021/12/13 16:33:44 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size);

int	main(void)
{
	size_t	nmemb;
	size_t	size;
	char	*ptr1;
	char	*ptr2;

	nmemb = 4;
	size = 4;
	ptr1 = calloc(nmemb,size);
	ptr2 = ft_calloc(nmemb,size);;
	printf("%s\n", ptr1);
	printf("%s\n", ptr2);
}
