/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainex03.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 21:54:27 by mgirardo          #+#    #+#             */
/*   Updated: 2021/08/24 11:58:14 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_recursive_power(int nb, int power);

int main(int ac, char **av)
{
    (void) ac;
    printf("%d\n", ft_recursive_power(atoi(av[1]), atoi(av[2])));
    return (0);
}
