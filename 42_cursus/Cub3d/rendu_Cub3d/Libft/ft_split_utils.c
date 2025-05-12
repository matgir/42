/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itahani <itahani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 17:10:25 by itahani           #+#    #+#             */
/*   Updated: 2022/10/07 17:12:41 by itahani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ligne_sup(char **str_arr, int *i)
{
	int	n;

	n = ft_strlen(str_arr[*i - 1]) - 1;
	str_arr[*i] = malloc(sizeof(char) * (n + 2));
	str_arr[*i][n + 1] = '\0';
	while (n >= 0)
	{
		str_arr[*i][n] = '#';
		n--;
	}
	str_arr[*i + 1] = NULL;
}
