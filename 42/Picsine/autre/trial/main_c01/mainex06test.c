/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1test.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 20:13:41 by mgirardo          #+#    #+#             */
/*   Updated: 2021/08/10 11:07:50 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h> 

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void    ft_putnbr(int i)
{
    if (i > 9)
    {
        ft_putnbr(i / 10);
        ft_putnbr(i % 10);
    }
    else
    {
        ft_putchar(i % 10 + 48);
    }
}

void	ft_putstr(char	*str)
{
	unsigned int	i;

	i = 0;
	while(str[i])
	{
//		ft_putchar(str[i]);
		i++;
	}
	ft_putnbr(i);
}

int	main(void)
{
	char str[] = "123456789";
	ft_putstr(str);
	printf("%lu",strlen(str));

	return (0);
}
