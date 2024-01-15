/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 18:08:51 by itahani           #+#    #+#             */
/*   Updated: 2022/04/14 16:15:09 by itahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

void	ft_putstr(char *s, int *ret_value)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		*ret_value += 6;
		return ;
	}
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	*ret_value += i;
}

void	ft_putchar(char c, int *ret_value)
{
	if (write (1, &c, 1))
		*ret_value += 1;
}

void	ft_put_u(unsigned int nb, int *ret_value)
{
	long int	nbr;

	nbr = (long int) nb;
	if (nbr > 9)
		ft_putnbr(nbr / 10, ret_value);
	ft_putchar((nbr % 10) + '0', ret_value);
}

void	ft_putnbr(int nb, int *ret_value)
{
	long int	nbr;

	nbr = (long int) nb;
	if (nbr < 0)
	{
		nbr *= -1;
		ft_putchar('-', ret_value);
	}
	if (nbr > 9)
		ft_putnbr(nbr / 10, ret_value);
	ft_putchar((nbr % 10) + '0', ret_value);
}
