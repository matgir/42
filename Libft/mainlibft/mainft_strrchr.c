/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainft_strrchr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 16:57:46 by mgirardo          #+#    #+#             */
/*   Updated: 2021/12/13 11:38:02 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strrchr(const char *s, int c);

int	main(void)
{
	const char	s[] = "bonsoir bonsoir";
	int		c = 98;

	printf("%s\n", ft_strrchr(s, c));
	printf("%s\n", strrchr(s, c));
}