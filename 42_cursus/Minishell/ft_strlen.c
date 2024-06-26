/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aurele <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 18:03:37 by aurele            #+#    #+#             */
/*   Updated: 2022/10/14 14:11:31 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendu_minishell/include/minishell.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (s == 0)
		return (-1);
	while (s[i])
		i++;
	return (i);
}
