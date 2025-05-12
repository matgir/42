/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainex07.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 12:24:40 by mgirardo          #+#    #+#             */
/*   Updated: 2021/08/23 19:56:22 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_find_next_prime(int nb);

int main(int ac, char **av)
{
    (void) ac;
    printf("%d\n", ft_find_next_prime(atoi(av[1])));
    return (0);
}
