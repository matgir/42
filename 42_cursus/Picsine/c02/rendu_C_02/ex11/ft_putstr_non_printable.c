/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 19:09:41 by mgirardo          #+#    #+#             */
/*   Updated: 2021/08/11 20:40:18 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	unsigned int	i;
	unsigned int	g;
	unsigned int	d;
	char			*conv;

	conv = "0123456789abcdef";
	i = 0;
	while (str[i])
	{
		if (str[i] < ' ' || str[i] > '~')
		{
			g = (unsigned char) str[i] / 16;
			d = (unsigned char) str[i] % 16;
			write(1, "\\", 1);
			write(1, &conv[g], 1);
			write(1, &conv[d], 1);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}
