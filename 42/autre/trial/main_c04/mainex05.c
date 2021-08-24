/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainex05.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 19:46:56 by mgirardo          #+#    #+#             */
/*   Updated: 2021/08/19 18:55:47 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atoi_base(char *str, char *base);

int main(void)
{
	char    str[] = " \v \n  --++-+--++--++--mateo";
	char  base[] = "mateo";

	printf("%d\n", ft_atoi_base(str, base));
	return (0);
}
