/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainft_tolower.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:14:09 by mgirardo          #+#    #+#             */
/*   Updated: 2021/12/08 15:11:42 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int	ft_tolower(int c);

int main()
{
    char c;

    c = 'm';
    printf("%c -> %c/%c", c, tolower(c),ft_tolower(c));

    c = 'D';
    printf("\n%c -> %c/%c", c, tolower(c),ft_tolower(c));

    c = '9';
    printf("\n%c -> %c/%c", c, tolower(c), ft_tolower(c));
    
    c = '=';
    printf("\n%c -> %c/%c", c, tolower(c), ft_tolower(c));
return ( 0);
}
