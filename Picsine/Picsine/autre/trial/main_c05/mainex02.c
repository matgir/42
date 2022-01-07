/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainex02.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 20:10:52 by mgirardo          #+#    #+#             */
/*   Updated: 2021/08/23 19:53:42 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_iterative_power(int nb, int power);

int main(int ac, char **av)
{
    (void) ac;
    printf("%d\n", ft_iterative_power(atoi(av[1]), atoi(av[2])));
    return (0);
}
