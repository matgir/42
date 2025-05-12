/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainft_substr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 15:10:05 by mgirardo          #+#    #+#             */
/*   Updated: 2021/12/15 17:50:27 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>

char	*ft_substr(char const *s, unsigned int start, size_t len);

int	main(void)
{
	//printf("%s\n", ft_substr("tripuoille", 0, 42000));
	printf("%s\n", ft_substr("lorem ipsum dolor sit amet", 0, 10));
	printf("%s\n", ft_substr("lorem ipsum dolor sit amet", 7, 10));
	printf("%s\n", ft_substr("lorem ipsum dolor sit amet", 400, 20));
	return (0);
}
