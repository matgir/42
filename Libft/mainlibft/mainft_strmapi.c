/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainft_strmapi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 15:34:40 by mgirardo          #+#    #+#             */
/*   Updated: 2021/12/20 16:04:54 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

char addOne(unsigned int i, char c) {return (i + c);}

int	main(void)
{
	printf("%s\n", ft_strmapi("1234", addOne));
	return (0);
}
