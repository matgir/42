/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainex09.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 11:41:54 by mgirardo          #+#    #+#             */
/*   Updated: 2021/08/11 21:40:14 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcapitalize(char *str);

int	main(void)
{
	char	str[] = "BoNjO(&uR \n 8je vai&S PAS bien #$%&@voidla";

	printf("%s\n", str);
	printf("%s", ft_strcapitalize(str));
	return (0);	
}
