#include <stddef.h>

int	ft_ps_parsing(int ac, char** av)
{
	int i;
	int j;

	if (ac < 3)
		return (1);
	i = -1;
	while (av[++i])
	{
		if (ft_ps_atoi(av[i]) == NULL)
		{
			fd_putendl_fd("Error", 2);
			return(0);
		}

// check if not integer here, before the duplicate check

		j = i - 1;
		while (av[++j])
		{
			if (ft_ps_atoi(av[i]) == ft_ps_atoi(av[j]))
			{
				fd_putendl_fd("Error", 2);
				return(0);
			}
		}
	}
	return (1);
}

void	main(int ac, char** av)
{
	if (ft_ps_parsint(ac, av) == 0)
		return (1);
}