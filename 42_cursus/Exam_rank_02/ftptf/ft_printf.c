/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:42:30 by mgirardo          #+#    #+#             */
/*   Updated: 2022/04/06 18:00:54 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int is_variable(char c)
{
	if (c == 's' || c == 'd' || c == 'x')
		return (0);
	else
		return (1);
}

int ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	if (str == NULL)
		return ;
	write(1, str, ft_strlen(str));
}


int	ft_print_s(va_list *ap)
{
	char	*str;

	str = va_arg(*ap, char *);
	va_end(*ap);
	if (str == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	ft_putstr(str);
	return (ft_strlen(str));
}

void	ft_putnbr(long int nb)
{
	if (nb < 0)
	{
		nb *= -1;
		ft_putchar('-');
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + 48);
}

int	ft_print_d(va_list *ap)
{
	int	i;
	int	puted;

	puted = 1;
	i = va_arg(*ap, long int);
	va_end(*ap);
	ft_putnbr(i);
	if (i < 0)
		puted++;
	while (i / 10 != 0)
	{
		puted++;
		i = i / 10;
	}
	return (puted);
}

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
	ft_putstr(str);
	free(str);
	return (len);
}

int	ft_print_x(va_list *ap)
{
	unsigned int	i;
	char			*hexbase;

	hexbase = "0123456789abcdef";
	i = va_arg(*ap, unsigned int);
	va_end(*ap);
	return (ft_puthex(i, hexbase));
}

int print_variable(char c, va_list *ap)
{
	if (c == 's')
		return (ft_print_s(ap));
	else if (c == 'd')
		return (ft_print_d(ap));
	else
		return (ft_print_x(ap));
	return (0);
}

int	what_variable(char *str, int *i,  va_list *ap)
{
	int	puted;

	if (str[*i + 1] && is_variable(str[*i + 1]) == 0)
	{
		puted = print_variable(str[*i + 1], ap);
		*i = *i + 1;
		return (puted);
	}
	else
	{
		ft_putchar(str[*i + 1]);
		*i = *i + 1;
		return (1);
	}
}

int	ft_printf(const char *str, ... )
{
	va_list	ap;
	int		i;
	int		puted;

	i = 0;
	puted = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] != '%')
		{
			ft_putchar(str[i]);
			puted++;
		}
		else
			puted += what_variable((char *)str, &i,  &ap);
		i++;
	}
	return (puted);
}
