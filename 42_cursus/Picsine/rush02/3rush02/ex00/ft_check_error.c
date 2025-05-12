/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 20:54:04 by mgirardo          #+#    #+#             */
/*   Updated: 2021/08/22 21:25:32 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "library.h"

int	ft_check_error1(int argc)
{
	if (argc < 2 || argc > 3)
		return (1);
	return (0);
}

int	ft_check_error2(char *str)
{
	if (ft_chek_arg(str) != 0 || ft_clean_before_nd_nb_paquets(str) > 13)
		return (1);
	return (0);
}

char	*ft_define_txt(int argc, char **argv)
{
	char	*txt;

	if (argc == 3)
		txt = argv[1];
	else
		txt = "numbers.dict.txt";
	return (txt);
}

char	*ft_define_str(int argc, char **argv)
{
	char	*str;

	if (argc == 3)
		str = argv[2];
	else
		str = argv[1];
	return (str);
}
