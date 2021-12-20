/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainft_striteri.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:24:22 by mgirardo          #+#    #+#             */
/*   Updated: 2021/12/20 16:32:47 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char*));

void	iter(unsigned int i, char * s) {*s += i	;}

int	main(void)
{
	char	str[] = "0000000000";

	ft_striteri(str, iter);
	printf("%s\n", str);
	return (0);
}
