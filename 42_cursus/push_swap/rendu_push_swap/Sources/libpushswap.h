/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libpushswap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 11:25:53 by mgirardo          #+#    #+#             */
/*   Updated: 2022/07/05 11:26:09 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "../libft/libft.h"

int	main(int ac, char** av);
int	ft_ps_parsing(int ac, char** av);
int	ft_ps_atoi(char *nptr, int *error);
int	ft_ps_intcheck(char **av);
int	ft_ps_duplicatecheck(char **av);
