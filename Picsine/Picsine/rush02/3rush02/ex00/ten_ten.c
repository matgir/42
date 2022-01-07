/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ten_ten.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepiney <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 21:46:27 by llepiney          #+#    #+#             */
/*   Updated: 2021/08/21 21:50:11 by llepiney         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

char	*ten_ten(char num1, char num2)
{
	char	*tempstr;

	tempstr = malloc(sizeof(char) * 3);
	if (!tempstr)
		return (0);
	tempstr[0] = num1;
	tempstr[1] = num2;
	tempstr[2] = '\0';
	return (tempstr);
}
