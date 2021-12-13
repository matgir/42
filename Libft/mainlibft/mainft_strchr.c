/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainft_strchr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 16:26:06 by mgirardo          #+#    #+#             */
/*   Updated: 2021/12/13 16:09:03 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strchr(const char *s, int c);

int	main(void)
{
	const char	s[] = "bonsoir bonsoir";
	int		c = 115;

	printf("%s\n", ft_strchr(s, c));
	printf("%s\n", strchr(s, c));
}
