/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainex04.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 17:30:18 by mgirardo          #+#    #+#             */
/*   Updated: 2021/08/10 11:04:36 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_ultimate_div_mod(int	*a, int	*b);

int	main(void)
{
	int a;
	int	b;
	
	a = 54;
	b = -14;
	printf("a = %d\nb = %d\n", a, b);
	ft_ultimate_div_mod(&a, &b);
	printf("div de a et b = %d\nmod de a et b = %d", a, b);
	return (0);
}
