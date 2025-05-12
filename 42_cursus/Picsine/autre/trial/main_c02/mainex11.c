/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainex11.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 19:06:33 by mgirardo          #+#    #+#             */
/*   Updated: 2021/08/11 21:44:13 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putstr_non_printable(char *str);

int	main(void)
{
	char	str[] = "voici un dindon\n pour un ordi en hexa 🦃";

	ft_putstr_non_printable(str);
	return (0);
}
