#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int	error(char *error)
{
	while (*error)
		write(2, error++, 1);
	return 1;
}

int	cd(char **argv, int i)
{
	if (i != 2)
		return error("error: cd: bad arguments\n");
	else if (chdir(argv[1]) == -1)
		return error("error: cd: cannot change directory to "), error(argv[1]), error("\n");
	return 0;
}

int	execute(char **argv, char **env, int i)
{
	int	fd[2];
	int	status;
	int	has_pipe = argv[i] && !strcmp(argv[i], "|");

	if (has_pipe && pipe(fd) == -1)
		return error("error: fatal\n");

	int	pid = fork();
	if (!pid)
	{
		argv[i] = 0;
		if (has_pipe && (dup2(fd[1], STDOUT_FILENO) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
			return error("error: fatal\n");
		execve(*argv, argv, env);
		return error("error: cannot execute "), error(*argv), error("\n");
	}
	waitpid(pid, &status, 0);
	if (has_pipe && (dup2(fd[0], STDIN_FILENO) == -1 || close(fd[0]) == -1 || close(fd[1]) == -1))
		return error("error: fatal\n");
	return WIFEXITED(status) && WEXITSTATUS(status);
}

int	main(int argc, char **argv, char **env)
{
	int	i = 0;
	int status = 0;

	if (argc > 1)
	{
		while (argv[i] && argv[++i])
		{
			argv += i;
			i = 0;
			while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
				i++;
			if (!strcmp(*argv, "cd"))
				status = cd(argv, i);
			else if (i)
				status = execute(argv, env, i);
		}
	}
	return status;
}
