/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainex04.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 18:47:13 by mgirardo          #+#    #+#             */
/*   Updated: 2021/08/25 18:31:39 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_convert_base(char *nbr, char *base_from, char *base_to);

int	main(int ac, char **av)
{
	(void) ac;
	//(void) av;
	printf("%s\n", ft_convert_base(av[1], av[2], av[3]));
	//printf("%s\n", ft_convert_base("2557", "0123456789", "0123456789abcdefghijklmnopqrstuvwxyz"));
	return (0);
}
