/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   posprint_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 12:22:50 by mgirardo          #+#    #+#             */
/*   Updated: 2022/11/30 12:22:52 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_unsplit(char **tab, char *charset, t_pos *free)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_strdup("", free);
	if (str == 0)
		return (0);
	while (tab[i])
	{
		str = ft_strjoin(str, tab[i], free);
		if (str == 0)
			return (0);
		i++;
		if (tab[i] && charset != 0)
		{
			str = ft_strjoin(str, charset, free);
			if (str == 0)
				return (0);
		}
	}
	return (str);
}

void	ft_printcmd(t_minishell *minishell, t_command *cmd, int fd)
{
	char	*str;

	(void)fd;
	if (cmd->fdin == 0)
		write(2, "fdin = 0\n", 9);
	else
	{
		write(2, "fdin = ", 8);
		write(2, cmd->fdin, ft_strlen(cmd->fdin));
		write(2, "\n", 1);
	}
	if (cmd->fdout == 0)
		write(2, "fdout = 0\n", 10);
	else
	{
		write(2, "fdout = ", 8);
		write(2, cmd->fdout, ft_strlen(cmd->fdout));
		write(2, "\n", 1);
	}
	if (cmd->ofdout == 0)
		write(2, "ofdout = 0\n", 11);
	else
	{
		write(2, "ofdout = ", 9);
		ft_putnbrfd(cmd->ofdout, 2);
		write(2, "\n", 1);
	}
	if (cmd->ofdin == 0)
		write(2, "ofdin = 0\n", 10);
	else
	{
		write(2, "ofdin = ", 8);
		ft_putnbrfd(cmd->ofdin, 2);
		write(2, "\n", 1);
	}
	if (cmd->error == 0)
		write(2, "error = 0\n", 10);
	else
	{
		write(2, "error = ", 8);
		write(2, cmd->error, ft_strlen(cmd->error));
		write(2, "\n", 1);
	}
	if (cmd->cmd == 0)
		write(2, "cmd = 0\n", 8);
	else
	{
		str = ft_unsplit(cmd->cmd, "\n", minishell->garbagecmd);
		write(2, "cmd = {\n", 8);
		write(2, str, ft_strlen(str));
		write(2, "\n}\n", 3);
	}
}

void	ft_printtoken(t_minishell *minishell, void *ptr, int fd)
{
	t_token	*token;

	token = (t_token *)ptr;
	ft_putnbrfd(token->type, fd);
	write(fd, "\n", 1);
	if (token->type == CMD)
		ft_printcmd(minishell, (t_command *)token->str, 0);
	else
		write(fd, token->str, ft_strlen(token->str));
	write(fd, "\n", 1);
}