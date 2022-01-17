/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:03:05 by mgirardo          #+#    #+#             */
/*   Updated: 2022/01/17 18:17:16 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftptf.h"

int	ft_printf(const char *str, ...)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (0);
	if (ft_find_%(str) == 1)
	{
		ft_putstr(str);
		return (ft_strlen(str));
	}

/*		reprendre ici et faire ft_what_variable, ou jai besoin de ap donc
 *		de va_start et va_arg		*/

	while (str[i])
	{
		if (str[i] == '%')
		{
			ft_what_variable(str[i + 1]);
			i++;
		}
		else
		{
			ft_putchar(str[i]);
			i++;
		}
	}

}
