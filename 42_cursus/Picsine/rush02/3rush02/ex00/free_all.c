/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepiney <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 21:30:22 by llepiney          #+#    #+#             */
/*   Updated: 2021/08/22 21:34:14 by llepiney         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
void	free_str(char *strcpy, char *solo, char *power, char *tempstr)
{
	free(strcpy);
	free(solo);
	free(power);
	free(tempstr);
}
