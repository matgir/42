/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainex03.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 17:02:25 by mgirardo          #+#    #+#             */
/*   Updated: 2021/08/10 11:01:50 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_div_mod(int	a, int	b, int	*div, int	*mod);

int	main(void)
{
	int	a;
	int	b;
	int	div;
	int	mod;

	a = -56;
	b = 14;
	ft_div_mod(a, b, &div, &mod);
	printf("%d et %d\ndiv a et b = %d\nmod a et b = %d", a, b, div, mod);
	return (0);
}
