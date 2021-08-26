/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 19:40:43 by mgirardo          #+#    #+#             */
/*   Updated: 2021/08/26 13:15:52 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	chek_if_charset(char stri, char *charset)
{
	int	i;

	i = 0;
	if (charset[i] = '\0')
		return (-1);
	while (charset[i])
	{
		if (charset[i] == stri)
			return (1);
		i++;
	}
	return (0);
}

int	get_first_word(char *str, char *charset)
{
	int	i;

	i = 0;
	if (chek_if_charset(str[i], charset) == -1)
		return (0);
	while (str[i] && chek_if_charset(str[i], charset) == 1)
		i++;
	return (i)
}

int	ft_count_word(char *str, char *charset)
{
	int	nbword;
	int	i;
	int	j;
	
	i = get_first_word(str, charset) - 1;
	nbword = 0;
	if (chek_if_charset(str[i], charset) == -1
			&& chek_if_charset(str[i], str) != -1)
		return (1);
	while (str[++i])
	{
		if (chek_if_charset(str[i], charset))
		{
			while (str[i] && chek_if_charset(str[i], charset) == 1)
				i++;
			if (str[i] != '\0')
				nbword++;
			j = i;
			while (str[j] && chek_if_charset(str[j], charset) != 1 )
				j++;
			if (str[j] == '\0')
				return (++nbword)
		}
	}
	return (nbword);
}

void	ft_remplissage(char *str, char *charset, int nbword)
{
}

char	**ft_split(char *str, char *charset)
{
	int		nbword;
	char	**tab;

	nbword = ft_count_word(str, charset);
	tab = malloc(sizeof(*tab) * (nbword + 1));
	if (tab == 0)
		return (tab);
	i = get_first_word(str, charset);
	start = i;
	if (nbword == 0 && str[i] && chek_if_charset(str[i], charset) != 1)
		nbword++;
}
