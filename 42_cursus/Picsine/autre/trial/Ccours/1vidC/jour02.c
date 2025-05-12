/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jour02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 18:52:42 by mgirardo          #+#    #+#             */
/*   Updated: 2021/08/05 21:46:06 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_nputchar(char c, int n);

int	main(void)

{
	ft_nputchar('@', 42);
	ft_putchar('\n');
	ft_nputchar('#', 2485);
	ft_putchar('\n');
	return (0);
}

void	ft_putchar(char c)

{
	write(1, &c, 1);
	return ;
}

void	ft_nputchar(char c, int n)

{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putchar(c);
		i = i + 1;
	}
	return ;
}
