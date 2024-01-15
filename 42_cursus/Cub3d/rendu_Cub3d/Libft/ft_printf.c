/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 17:17:06 by itahani           #+#    #+#             */
/*   Updated: 2024/01/15 20:08:18 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

int	val_print_hexa(const char *str, va_list *ap, int *i, int *ret_value)
{
	if (str[*i + 1] == 'x')
	{
		ft_putnbr_base(va_arg(*ap, int), 'x', ret_value);
		*i += 2;
	}
	else if (str[*i + 1] == 'X')
	{
		ft_putnbr_base(va_arg(*ap, int), 'X', ret_value);
		*i += 2;
	}
	else if (str[*i + 1] == 'p')
	{
		ft_put_p((unsigned long long int)va_arg(*ap, void *), ret_value);
		*i += 2;
	}
	else if (str[*i + 1] == 'u')
	{
		ft_put_u((unsigned int)va_arg(*ap, int), ret_value);
		*i += 2;
	}
	return (0);
}

int	val_print(const char *str, va_list *ap, int *i, int *ret_value)
{
	if (str[*i + 1] == 'c')
	{
		ft_putchar(va_arg(*ap, int), ret_value);
		*i += 2;
	}
	else if (str[*i + 1] == '%')
	{
		ft_putchar('%', ret_value);
		*i += 2;
	}
	else if (str[*i + 1] == 'd' || str[*i + 1] == 'i')
	{
		ft_putnbr(va_arg(*ap, int), ret_value);
		*i += 2;
	}
	else if (str[*i + 1] == 's')
	{
		ft_putstr(va_arg(*ap, char *), ret_value);
		*i += 2;
	}
	else if (str[*i + 1] == 'x' || str[*i + 1] == 'X'
		|| str[*i + 1] == 'p' || str[*i + 1] == 'u')
		val_print_hexa(str, ap, i, ret_value);
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		ret_value;

	i = 0;
	ret_value = 0;
	va_start(ap, str);
	while (str[i])
	{
		while (str[i] && str[i] != '%')
		{
			ft_putchar(str[i], &ret_value);
			i++;
		}
		if (str[i] == '%')
			val_print(str, &ap, &i, &ret_value);
	}
	va_end(ap);
	return (ret_value);
}

/*
#include <limits.h>
#include <stdio.h>
int main()
{
	//int nombre = 5;
	//char *str = "toi";

	printf("\n%i\n", ft_printf("NULL %s NULL", NULL));
	printf("\n%i\n", printf("NULL %s NULL", NULL));;
	return (0);
}*/
