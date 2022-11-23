/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audreyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:02:33 by audreyer          #+#    #+#             */
/*   Updated: 2022/11/16 16:42:51 by audreyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//	when ctrl + d, EOF
//	minishell: warning: here-document at line <where we are at> delimited by
//	end-of-file (wanted `<heredoc delimiter>')

/* int	g_heredoc = 42;

void	ft_signalhd(int sig)
{
	// g_heredoc = 42;
	if (sig == SIGINT)
	{
		g_heredoc = 130;
		close(0);
	}
	else if (sig == SIGQUIT)
	{
		write(1, "\33[2K\r", 5);
		rl_on_new_line();
		rl_redisplay();
	}
} */

char	*ft_whileheredoc(t_minishell *minishell, char *str, t_token *t, int fd)
{
	char	*read;

/* 	if (g_heredoc == 130)
	{
		// printf("Had SIGINT in ft_heredoc\n");//
		minishell->laststatus = g_heredoc;
		// ft_error(minishell, ft_itoa(g_heredoc, minishell->garbage));
		signal(SIGINT, ft_signal_main);
		signal(SIGQUIT, ft_signal_main);
		return ("no no jose, no se bueno");
	} */
	read = ft_readline("> ", minishell->garbagecmd);
	if (!read)
	// {//
		// printf("EOF in ft_whileheredoc\n");//
		ft_exit(minishell, "exit\n");
	// }//
	minishell->heredocprompt++;
	read = ft_strjoin(read, "\n", minishell->garbagecmd);
	if (ft_strcmp(str, read) != 0)
	{
		if (t->type == HEREDOC)
			read = ft_expanddoublequote(minishell, read);
		write(fd, read, ft_strlen(read));
	}
	return (read);
}

void	ft_heredoc(t_minishell *minishell, t_token *token)
{
	int		fd;
	char	*str;
	char	*heredocnbr;
	char	*read;

	str = token->str;
	read = 0;
	token->str = ft_strdup("./tmp/heredoc", minishell->garbagecmd);
	str = ft_strjoin(str, "\n", minishell->garbagecmd);
	heredocnbr = ft_itoa(minishell->heredoc, minishell->garbagecmd);
	token->str = ft_strjoin(token->str, heredocnbr, minishell->garbagecmd);
	fd = open(token->str, O_CREAT | O_TRUNC | O_RDWR, 0777);
	if (fd == -1)
		write(2, "Could not open file descriptor\n", 8);
	// signal(SIGINT, ft_signalhd);
	// signal(SIGQUIT, ft_signalhd);
	// while (ft_strcmp(str, read) != 0 || ft_strcmp(read, "no no jose, no se bueno") != 0)//
	while (ft_strcmp(str, read) != 0)
		read = ft_whileheredoc(minishell, str, token, fd);
	minishell->heredoc++;
	token->type = IN;
	ft_closevaria(1, fd);
}

void	ft_heredocclean(t_minishell *minishell)
{
	t_list	*tokenlist;

	tokenlist = minishell->tokenlist->start;
	while (ft_type(tokenlist) != NL)
	{
		if (ft_type(tokenlist) == HEREDOC || ft_type(tokenlist) == HEREDOCEXT)
			ft_heredoc(minishell, tokenlist->content);
		tokenlist = tokenlist->next;
	}
}

	/*
		Pour les signaux qudn EOF message derreur recup str sans \n et
		minishell->heredocprompt
	*/