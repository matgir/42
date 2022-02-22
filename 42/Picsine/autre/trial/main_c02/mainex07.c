/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainex07.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 10:02:07 by mgirardo          #+#    #+#             */
/*   Updated: 2021/08/11 21:35:58 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

char	*ft_strupcase(char	*str);

int	main(void)
{
	char	str[] = "je\n veuX:wd3v3ni% & @#r une m4juscule";

	printf("%s\n", str);
	printf("%s", ft_strupcase(str));
	return (0);
}
