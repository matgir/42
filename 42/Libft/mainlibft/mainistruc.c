/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainistruc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 12:18:19 by mgirardo          #+#    #+#             */
/*   Updated: 2021/11/23 14:07:31 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int	ft_isalpha(int c);
int	ft_isdigit(int c);
int	ft_isalnum(int c);
int	ft_isascii(int c);
int	ft_isprint(int c);

int main(void)
{
int c = '	';

printf("%d\n", isalpha(c));
printf("%d\n", ft_isalpha(c));
printf("%d\n", isdigit(c));
printf("%d\n", ft_isdigit(c));
printf("%d\n", isalnum(c));
printf("%d\n", ft_isalnum(c));
printf("%d\n", isascii(c));
printf("%d\n", ft_isascii(c));
printf("%d\n", isprint(c));
printf("%d", ft_isprint(c));
}
