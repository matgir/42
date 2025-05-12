/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainft_strrchr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 16:57:46 by mgirardo          #+#    #+#             */
/*   Updated: 2021/12/15 11:06:07 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char	*ft_strrchr(const char *s, int c);

int	main(void)
{
	char	*s = (char*)calloc(1, 1);
	int		c = 'V';

	printf("%s\n", ft_strrchr(s, c));
	printf("%s\n", strrchr(s, c));
}
