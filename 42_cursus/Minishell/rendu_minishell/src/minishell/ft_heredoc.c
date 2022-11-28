/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audreyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:02:33 by audreyer          #+#    #+#             */
/*   Updated: 2022/11/28 15:32:31 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//	when ctrl + d, EOF
//	minishell: warning: here-document at line <where we are at> delimited by
//	end-of-file (wanted `<heredoc delimiter>')

int	g_heredoc = 42;

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
}

char	*ft_whileheredoc(t_minishell *minishell, char *str, t_token *t, int fd)
{
	char	*read;
	char	*error;

	/* if (g_heredoc == 130)
	   {
	// printf("Had SIGINT in ft_heredoc\n");//
	minishell->laststatus = g_heredoc;
	// ft_error(minishell, ft_itoa(g_heredoc, minishell->garbage));
	// signal(SIGINT, ft_signal_main);
	// signal(SIGQUIT, ft_signal_main);
	return (str);
	} */
	read = ft_readline("> ", minishell->garbagecmd);
	if (!read && g_heredoc == 42)
	{//
		printf("EOF in ft_whileheredoc\n");//
		minishell->heredocprompt++;
		error = ft_strdup("minishell: warning: here-docume", minishell->garbagecmd);
		error = ft_strjoin(error, "nt at line ", minishell->garbagecmd);
		error = ft_strjoin(error, ft_itoa(minishell->heredocprompt, minishell->garbagecmd), minishell->garbagecmd);
		error = ft_strjoin(error, " delimited by end-of-fi", minishell->garbagecmd);
		error = ft_strjoin(error, "le (wanted `", minishell->garbagecmd);
		error = ft_strjoin(error, str, minishell->garbagecmd);
		error[ft_strlen(error) - 1] = '\0';
		error = ft_strjoin(error, "')\n", minishell->garbagecmd);
		printf("%s", error);
		// ft_error(minishell, error);
		return (str);
		// ft_error(minishell, "exit\n");
	}//
	else if (!read && g_heredoc == 130)
	{
		minishell->laststatus = g_heredoc;
		return (str);
	}
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

	printf("in ft_heredoc\n");
	str = token->str;
	read = 0;
	token->str = ft_strdup("./tmp/heredoc", minishell->garbagecmd);
	str = ft_strjoin(str, "\n", minishell->garbagecmd);
	heredocnbr = ft_itoa(minishell->heredoc, minishell->garbagecmd);
	token->str = ft_strjoin(token->str, heredocnbr, minishell->garbagecmd);
	fd = open(token->str, O_CREAT | O_TRUNC | O_RDWR, 0777);
	printf("fd = '%i'\n", fd);// 
	if (fd == -1)
		write(2, "Could not open file descriptor\n", 8);
	signal(SIGINT, ft_signalhd);
	signal(SIGQUIT, ft_signalhd);
	// while (ft_strcmp(str, read) != 0)
	while (ft_strcmp(str, read) != 0 /* && g_heredoc == 42 */ )//
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
	signal(SIGINT, ft_signal_main);
	signal(SIGQUIT, ft_signal_main);
}

void	ft_minishell(t_minishell *minishell)
{
	char			*str;

	str = 0;
	while (1)
	{
		printf("In ft_minishell\n");//
		str = ft_readline("Minishell> ", minishell->garbagecmd);
		if (!str && g_heredoc == 42)
		{//
			printf("EOF in ft_minishell\n");//
			ft_exit(minishell, "exit\n");
		}//
		else if (!str && g_heredoc == 130)
		{//
			str = ft_strdup('\0', minishell->garbagecmd);
			if (!str)
				ft_exit(minishell, "malloc error\n");
		}
		printf("before tring to read str[0]\n");//
		if (str[0] != '\0')
			add_history(str);
		printf("after tring to read str[0]\n");//
		if (ft_tokencreate(minishell, str) == 0
				|| *minishell->tokenlist->size != 0)
		{
			ft_tokenredirclean(minishell);
			if (*minishell->tokenlist->size != 0)
			{
				ft_heredocclean(minishell);
				ft_tokencmdclean(minishell);
				ft_child(minishell, minishell->tokenlist->start);
			}
			ft_error(minishell, ft_itoa(minishell->laststatus,
						minishell->garbage));
		}
		// }//
}
}

/*
   Pour les signaux qudn EOF message derreur recup str sans \n et
   minishell->heredocprompt
   */
