/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   what_variable.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:36:42 by mgirardo          #+#    #+#             */
/*   Updated: 2022/01/18 16:38:09 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftptf.h"

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
		ft_putchar(str[*i + 1]);
		return (1);
	}
}
