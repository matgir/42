/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 14:08:01 by mgirardo          #+#    #+#             */
/*   Updated: 2022/10/27 01:13:43 by audreyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_error(t_minishell *minishell, char *str)
{
	ft_closevaria(1, minishell->fdutil);
	ft_closevaria(2, minishell->pipe[0], minishell->pipe[1]);//
	minishell->fdutil = 0;
	minishell->laststatus = ft_errorstr(str);
	if (str && !ft_isnum(str))
		write(2, str, ft_strlen(str));
	if (minishell->garbagecmd != NULL)
		ft_posclear(minishell->garbagecmd, 1);
	minishell->tokenlist->start = 0;
	*minishell->tokenlist->size = 0;
}
