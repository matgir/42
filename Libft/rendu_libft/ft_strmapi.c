/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 15:34:27 by mgirardo          #+#    #+#             */
/*   Updated: 2021/12/20 15:50:56 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*strmapi;

	if (s == NULL)
		return (NULL);
	strmapi = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (strmapi == NULL)
		return (NULL);
	i = -1;
	while (s[++i])
		strmapi[i] = f(i, s[i]);
	strmapi[i] = '\0';
	return (strmapi);
}
