/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   what_variable.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:36:42 by mgirardo          #+#    #+#             */
/*   Updated: 2022/01/20 15:16:50 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	what_variable(const char *str, int *i, va_list *ap)
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
		ft_putchar_fd(str[*i + 1], 1);
		*i = *i + 1;
		return (1);
	}
}