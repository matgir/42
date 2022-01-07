/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainex00.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 17:06:19 by mgirardo          #+#    #+#             */
/*   Updated: 2021/08/24 10:17:25 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	ft_iterative_factorial(int nb);

#include <stdio.h>
#include <stdlib.h>


int main(int ac, char **av)
{
    (void) ac;
    printf("%d\n", ft_iterative_factorial(atoi(av[1])));
    return (0);
}
