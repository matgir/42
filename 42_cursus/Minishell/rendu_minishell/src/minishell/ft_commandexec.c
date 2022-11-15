/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_commandexec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audreyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 13:35:21 by audreyer          #+#    #+#             */
/*   Updated: 2022/10/31 11:24:35 by audreyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_changefdin(t_list *tokenlist, int fd)
{
	t_token		*token;
	t_command	*command;

	token = (t_token *)tokenlist->content;
	command = (t_command *)token->str;
	if (command->ofdin == 0)
		command->ofdin = fd;
}

void	ft_changefdout(t_list *tokenlist, int fd)
{
	t_token		*token;
	t_command	*command;

	token = (t_token *)tokenlist->content;
	command = (t_command *)token->str;
	if (command->ofdout == 1)
		command->ofdout = fd;
}

void	ft_openend(t_command *cmd)
{
	if (cmd->fdin != 0)
		cmd->ofdin = open(cmd->fdin, O_RDONLY, 0777);
	if (cmd->fdout != 0 && cmd->type == 'T')
		cmd->ofdout = open(cmd->fdout, O_WRONLY | O_CREAT | O_TRUNC , 0777);
	if (cmd->fdout != 0 && cmd->type == 'A')
		cmd->ofdout = open(cmd->fdout, O_WRONLY | O_CREAT | O_APPEND , 0777);
}

void	ft_arg(t_minishell *minishell, t_list *tokenlist)
{
	if (ft_type(tokenlist->back) == PIPE)
	{
		if (!ft_fdin(tokenlist) && ft_type(tokenlist) == CMD)
			ft_changefdin(tokenlist, minishell->pipe[2]);
	}
	if (ft_type(tokenlist->next) == PIPE)
	{
		pipe(minishell->pipe);
		if (!ft_fdout(tokenlist) && ft_type(tokenlist) == CMD)
			ft_changefdout(tokenlist, minishell->pipe[1]);
		minishell->pipe[2] = minishell->pipe[0];
	}
	if (ft_type(tokenlist) == CMD)
		ft_openend(ft_commandget(tokenlist));
}

char	**ft_reenv(t_minishell *minishell)
{
	char	**str;
	int		i;
	t_env	*line;
	t_list	*listact;

	i = 0;
	str = ft_malloc(sizeof(char *) * (*minishell->actenv->size + 1), minishell->garbagecmd);
	if (!str)
		ft_exit(minishell, "malloc error\n");
	str[*minishell->actenv->size] = 0;
	listact = minishell->actenv->start;
	while (i < *minishell->actenv->size)
	{
		line = (t_env *)listact->content;
		str[i] = ft_strjoin(line->name, ft_strdup("=", minishell->garbagecmd), minishell->garbagecmd);
		str[i] = ft_strjoin(str[i], line->value, minishell->garbagecmd);
		if (!str[i])
			ft_exit(minishell, "malloc error\n");
		listact = listact->next;
		i++;
	}
	return (str);
}

int	ft_spacehere(char *str)
{
	int	i;
	int	nbspaces;

	i = -1;
	nbspaces = 0;
	while (str[++i])
		if (str[i] == ' ')
		{
			printf("in spacehere\nnbspaces = '%i'\nin spacehre : str[i] = '%c'", nbspaces, str[i]);//
			nbspaces++;
		}
	return (nbspaces);
}

char	**ft_cmdcheckbfexecve(t_minishell *minishell, char **cmd)
{
	int		i;
	// char	**newcmd;
	int		nbcmdtoadd;

	printf("in cmdcheckbfexecve\n");
	(void)minishell;//
	i = -1;
	// newcmd = cmd;
	nbcmdtoadd = 0;
	while (cmd[++i])
		nbcmdtoadd += ft_spacehere(cmd[i]);
	if (nbcmdtoadd == 0)
		return (cmd);
	else
		printf("Need to split some cmd\n");
	return (cmd);//
}

void	ft_executecmd(t_minishell *minishell, t_command *command)
{
	printf("in ft_executecmd\n");
	if (ft_isbuiltin(command) == 1)
	{
		ft_builtin(minishell, command);
		ft_exit(minishell, 0);
	}
	if (command->ofdin != 0)
		dup2(command->ofdin, 0);
	if (command->ofdout != 1)
	{
		dup2(command->ofdout, 1);
		if (command->ofdin != minishell->pipe[0])
			ft_closevaria(1, minishell->pipe[0]);
	}
	ft_closevaria(2, command->ofdin, command->ofdout);
	if (command->error == 0)
	{//
		int v = -1;//
		while (command->cmd[++v])//
		{//
			printf("cmd = %s\n", command->cmd[v]);//
		}//
		command->cmd = ft_cmdcheckbfexecve(minishell, command->cmd);// to be moved in ft_child
		execve(command->file, command->cmd, ft_reenv(minishell));
	}//
	if (command->error == 0)
		command->error = ft_strjoin(strerror(errno), "\n", minishell->garbagecmd);
	ft_exit(minishell, command->error);
}

int	ft_cmdnbr(t_list *tokenlist)
{
	int	i;

	i = 0;
	while (ft_type(tokenlist) != NL)
	{
		if (ft_type(tokenlist) == CMD)
			i++;
		tokenlist = tokenlist->next;
	}
	return (i);
}

void	ft_child(t_minishell *minishell, t_list *tokenlist)
{
	int			i;
	int			b;
	int			wstatus;
	int			*childid;
	t_command	*command;

	printf("In ft_child\n");//
	if (ft_type(tokenlist) == NL)
		return ;
//	ft_posprint(minishell, minishell->tokenlist, &ft_printtoken, 2);
	command = ft_commandget(tokenlist);
			printf("command->error = '%s'\n", command->error);//
	printf("here1\n");//
	if (ft_type(tokenlist->next) == NL && ft_isbuiltin(command) == 1)
	{
	printf("here2\n");//
		ft_openend(ft_commandget(tokenlist));
		ft_builtin(minishell, command);
	}
	else
	{
	printf("here3\n");//
			printf("command->error = '%s'\n", command->error);//
			/*
				need to do the spaces check here and not in executecmd
			*/
		if (command->cmd && command->cmd[0] != 0)
			command->file = ft_getcmdfile(minishell, command);
		printf("command->error = '%s'\n", command->error);//
		i = 0;
		childid = ft_malloc(sizeof(int) *ft_cmdnbr(tokenlist), minishell->garbagecmd);
		while (ft_type(tokenlist->back) != NL || i == 0)
		{
			printf("command->error = '%s'\n", command->error);//
			if (command->error == 0)
				ft_arg(minishell, tokenlist);
	printf("here4\n");//
			childid[i] = fork();
			if (childid[i] == 0)
			{
	printf("here5\n");//
				if (command->error == 0)
					{//
						printf("here6\n");//
				ft_executecmd(minishell, command);
					}//
				else
					ft_exit(minishell, command->error);
			}
			i++;
			ft_closevaria(2, ft_ofdout(tokenlist), ft_ofdin(tokenlist));
			tokenlist = tokenlist->next->next;
			command = ft_commandget(tokenlist);
			if (command->cmd && command->cmd[0] != 0)
				command->file = ft_getcmdfile(minishell, command);
		}
		b = 0;
		while (b < i)
			waitpid(childid[b++], &wstatus, 0);
		if (WIFEXITED(wstatus) == 1)
			minishell->laststatus = WEXITSTATUS(wstatus);
	}
}
