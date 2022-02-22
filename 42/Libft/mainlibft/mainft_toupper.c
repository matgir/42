/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainft_toupper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:14:09 by mgirardo          #+#    #+#             */
/*   Updated: 2021/12/08 14:22:35 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int	ft_toupper(int c);

int main()
{
    char c;

    c = 'm';
    printf("%c -> %c/%c", c, toupper(c),ft_toupper(c));

    c = 'D';
    printf("\n%c -> %c/%c", c, toupper(c),ft_toupper(c));

    c = '9';
    printf("\n%c -> %c/%c", c, toupper(c), ft_toupper(c));
    
    c = '=';
    printf("\n%c -> %c/%c", c, toupper(c), ft_toupper(c));
return ( 0);
}
