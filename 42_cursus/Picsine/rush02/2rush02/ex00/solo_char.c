/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solo_char.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepiney <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 14:41:29 by llepiney          #+#    #+#             */
/*   Updated: 2021/08/22 14:41:43 by llepiney         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "library.h"
#include <stdlib.h>

char	*solo_char(char c)
{
	char	*solo;

	solo = malloc(sizeof(char) * 2);
	solo[0] = c;
	solo[1] = '\0';
	return (solo);
}
