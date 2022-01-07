/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 16:38:28 by mgirardo          #+#    #+#             */
/*   Updated: 2021/08/22 22:06:38 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "library.h"

int	ft_lenstr(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	main(int argc, char **argv)
{
	char			*str;
	char			*strcpy;
	char			**tab;
	char			*txt;

	str = ft_define_str(argc, argv);
	txt = ft_define_txt(argc, argv);
	if (ft_check_error1(argc) == 1 || ft_check_error2(str) == 1)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (ft_lenstr(str) % 3 == 0)
	{
		(void) strcpy;
		tab = split(str);
	}
	else
	{
		strcpy = ft_strcpy(str);
		tab = split(strcpy);
	}
	ft_lcmparsing(tab, txt, str);
	ft_putchar('\n');
	return (0);
}
