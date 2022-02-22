/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainex01.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 17:29:43 by mgirardo          #+#    #+#             */
/*   Updated: 2021/08/23 19:52:14 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int ft_recursive_factorial(int nb);

#include <stdio.h>
#include <stdlib.h>


int main(int ac, char **av)
{
    (void) ac;
    printf("%d\n", ft_recursive_factorial(atoi(av[1])));
    return (0);
}
