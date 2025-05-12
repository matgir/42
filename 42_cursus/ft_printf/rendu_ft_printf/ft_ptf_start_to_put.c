/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 11:22:06 by mgirardo          #+#    #+#             */
/*   Updated: 2022/01/20 17:00:12 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_puthex(unsigned int n, char *hexbase)
{
	unsigned int	ntmp;
	int				i;
	char			*str;
	int				len;

	i = 1;
	ntmp = n;
	while (n / 16 != 0)
	{
		n = n / 16;
		i++;
	}
	len = i;
	str = malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (0);
	str[i] = '\0';
	while (--i >= 0)
	{
		str[i] = hexbase[ntmp % 16];
		ntmp /= 16;
	}
	ft_putstr_fd(str, 1);
	free(str);
	return (len);
}

int	ft_putuhex(unsigned long int uli, char *hexbase)
{
	unsigned long int	ntmp;
	int					i;
	char				*str;
	int					len;

	i = 1;
	ntmp = uli;
	while (uli / 16 != 0)
	{
		uli = uli / 16;
		i++;
	}
	len = i;
	str = malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (0);
	str[i] = '\0';
	while (--i >= 0)
	{
		str[i] = hexbase[ntmp % 16];
		ntmp /= 16;
	}
	ft_putstr_fd(str, 1);
	free(str);
	return (len);
}

void	ft_putunbr(unsigned int n)
{
	if (n >= 10)
		ft_putunbr(n / 10);
	ft_putchar_fd(n % 10 + 48, 1);
}

void	ft_putpurcent(int *puted, int *i)
{
	ft_putchar_fd('%', 1);
	*puted = *puted + 1;
	*i = *i + 1;
}
