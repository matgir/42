/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 10:56:36 by mgirardo          #+#    #+#             */
/*   Updated: 2022/02/09 16:35:24 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i	;

	i = 0;
	while (n != 0)
	{
		((unsigned char *) dest)[i] = ((unsigned const char *) src)[i];
		i++;
		n--;
	}
	return (dest);
}

char	*final_line(char *line, char *buf)
{
	line = ft_strjoin (line, buf);
	line = ft_strtrim(line);
	ft_strlcpy(buf, buf + ft_strchr(buf, '\n') + 1, BUFFER_SIZE);
	return (line);
}
