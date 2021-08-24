/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainex04.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 15:49:40 by mgirardo          #+#    #+#             */
/*   Updated: 2021/08/19 18:54:16 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putnbr_base(int nbr, char *base);

int	main(int argc, char **argv)
{
	(void) argc;
	int nbr;

	nbr = -2147483648;
	ft_putnbr_base(nbr, argv[1]);
	return (0);
}
