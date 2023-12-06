#include <stdio.h>
#include <unistd.h>
// #include <sys/types.h>
#include <linux/limits.h>
// #include <limits.h>
#include <string.h>
#include <sys/wait.h>

void	ft_print_error(char *str)
{
	int	i = 0;

	while (str[i])
		i++;
	write (2, str, i);
}

int	ft_execute(char **av, int i, int tmp_fd, char **env)
{
	av[i] = NULL;
	close(tmp_fd);
	execve(av[0], av, env);
	ft_print_error("ME error: cannot execute ");
	// ft_print_error("error: cannot execute ");
	ft_print_error(av[0]);
	ft_print_error("\n");
	return (1);
}

int	main(int ac, char **av, char **env)
{
	(void)ac;
	int	fd[2];
	int	i = 0;
	int	pid = 0;
	int	tmp_fd = dup(STDIN_FILENO);

	while (av[i] && av[i + 1])
	{
		av = &av[i + 1];
		// i = 0;
		while (av[i] && strcmp(av[i], ";") && strcmp(av[i], "|"))
			i++;
		/*********** CD ERRORS ***********/
		if (strcmp(av[0], "cd") == 0)
		{
			if (i != 2)
				ft_print_error("ME error: cd: bad arguments\n");
				// ft_print_error("error: cd: bad arguments\n");
			else if (chdir(av[1]) != 0)
			{
				ft_print_error("ME error: cd: cannot change directory to ");
				// ft_print_error("error: cd: cannot change directory to ");
				ft_print_error(av[1]);
				ft_print_error("\n");
			}
			{//
				char	cwd[PATH_MAX];//
				getcwd(cwd, PATH_MAX);//
				ft_print_error(cwd);//
				ft_print_error("\n");//
			}
		}
		/*********** ";" IMPLEMENTATION ***********/
		else if (av != &av[i] && (av[i] == NULL || strcmp(av[i], ";") == 0))
		{
			pid = fork();
			if (pid == 0)
			{
				dup2(tmp_fd, STDIN_FILENO);
				if (ft_execute(av, i, tmp_fd, env))
					return(1);
			}
			else
			{
				close(tmp_fd);
				waitpid(-1, NULL, WUNTRACED);
				tmp_fd = dup(STDIN_FILENO);
			}
		}
		/*********** "|" IMPLEMENTATION ***********/
		else if (av != &av[i] && strcmp(av[i], "|") == 0)
		{
			pipe(fd);
			pid = fork();
			if (pid == 0)
			{
				dup2(tmp_fd, STDIN_FILENO);
				dup2(fd[1], STDOUT_FILENO);
				close(fd[1]);
				close(tmp_fd);
				if (ft_execute(av, i, tmp_fd, env))
					return (1);
			}
			else
			{
				close(tmp_fd);
				close(fd[1]);
				waitpid(-1, NULL, WUNTRACED);
				tmp_fd = dup(fd[0]);
				close(fd[0]);
			}
		}
	}
	close(tmp_fd);
	return (0);
}