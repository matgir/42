/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainft_strdup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:48:29 by mgirardo          #+#    #+#             */
/*   Updated: 2021/12/13 16:54:57 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strdup(const char *s);

int	main(void)
{
	const char	s[] = "moi doubler";

	printf("%s\n", strdup(s));
	printf("%s\n", ft_strdup(s));
}
