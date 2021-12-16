/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainft_strtrim.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:18:21 by mgirardo          #+#    #+#             */
/*   Updated: 2021/12/16 17:44:51 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strtrim(char const *s1, char const *set);

int	main(void)
{
	printf("%s\n", ft_strtrim("   xxx   xxx", " x"));
	printf("%s\n", ft_strtrim("", "123"));
	printf("%s\n", ft_strtrim("", ""));
	return (0);
}
