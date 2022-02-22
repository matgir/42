/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainmemcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 12:24:09 by mgirardo          #+#    #+#             */
/*   Updated: 2021/12/08 12:24:13 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stddef.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int	main()
{
	char		dest1[] = "bonjour a vous";
	const char	src1[] = "Bonsoir de vous et de lui";
	size_t		n;

	n = 57;
	printf("%s\n", dest1);
	memcpy(dest1, src1, n);
	printf("%s\n", dest1);
	return (0);
}
