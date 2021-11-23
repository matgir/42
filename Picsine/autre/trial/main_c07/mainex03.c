/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainex03.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 12:50:24 by mgirardo          #+#    #+#             */
/*   Updated: 2021/08/26 11:28:08 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strjoin(int size, char **strs, char *sep);

int main()
{
	char	*tab[] = {"yo", "voila", "tu", "grandmot", "0123456789"};

	printf("%s\n", ft_strjoin(5, tab, " "));
	return(0);
}
