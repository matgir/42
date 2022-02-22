/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainft_strjoin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 12:20:17 by mgirardo          #+#    #+#             */
/*   Updated: 2021/12/16 14:48:13 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2);

int	main(void)
{
	printf("%s\n", ft_strjoin("bonjour", "bonsoir"));
	printf("%s\n", ft_strjoin("12345", "6789"));
	printf("%s\n", ft_strjoin("", "bonsoir"));
	printf("%s\n", ft_strjoin("bonjour", ""));
	printf("%s\n", ft_strjoin("bonjour", " bonsoir"));
	printf("%s\n", ft_strjoin(" bonjour\n", "\nbonsoir	"));
	printf("%s\n", ft_strjoin("!@#$%^&*(_+)", "bons\0oir"));
	printf("%s\n", ft_strjoin("\f\t\v\n\r", "bon soir"));
	printf("%s\n", ft_strjoin("123456", "ghijkl"));
	printf("%s\n", ft_strjoin("", ""));
	return (0);
}
