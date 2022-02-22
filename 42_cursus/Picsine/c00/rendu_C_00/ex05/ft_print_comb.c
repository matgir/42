/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 12:05:27 by mgirardo          #+#    #+#             */
/*   Updated: 2021/08/06 21:13:26 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	g_a;
char	g_b;
char	g_c;

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb(void)
{
	g_a = '0';
	while (g_a <= '7')
	{
		g_b = g_a + 1;
		while (g_b <= '8')
		{
			g_c = g_b + 1;
			while (g_c <= '9')
			{
				ft_putchar(g_a);
				ft_putchar(g_b);
				ft_putchar(g_c);
				if (!(g_a == '7' && g_b == '8' && g_c == '9'))
				{
					write (1, ", ", 2);
				}
				g_c++;
			}
			g_b++;
		}
		g_a++;
	}
}
