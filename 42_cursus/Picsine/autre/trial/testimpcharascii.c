/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testimpcharascii.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 19:29:41 by mgirardo          #+#    #+#             */
/*   Updated: 2021/08/10 19:56:04 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(void)
{
	char	str[] = "0a&";
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		write(1, &"str[i]", 1);
		i++;
	}
}
