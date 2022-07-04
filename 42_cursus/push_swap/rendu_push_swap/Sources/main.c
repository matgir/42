#include "libpushswap.h"

int	ft_ps_parsing(int ac, char** av)
{
	int i;
	int j;
	int error;

	if (ac < 3)
		return (1);
	i = -1;
	while (av[++i])
	{
		error = 0;
		ft_ps_atoi(av[i], &error);
		if (error != 1)
		{
			ft_putendl_fd("Error 1", 2);
			return(0);
		}
		j = i - 1;
		while (av[++j])
		{
			if (ft_ps_atoi(av[i], &error) == ft_ps_atoi(av[j], &error) && error == 1)
			{

				ft_putendl_fd("Error 2", 2);
				return(0);
			}
		}
	}
	return (1);
}

int	main(int ac, char** av)
{
	if (ft_ps_parsing(ac, av) == 0)
		return (0);
}