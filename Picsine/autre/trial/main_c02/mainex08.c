/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainex08.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 10:47:21 by mgirardo          #+#    #+#             */
/*   Updated: 2021/08/11 21:37:17 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strlowcase(char	*str);

int main(void)
{
	char	str[] = "JE @ gt %$& TRE V\nOILA VOILA ";

	printf("%s\n", str);
	printf("%s", ft_strlowcase(str));
}
