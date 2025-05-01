#include <unistd.h>
#include <stdio.h>

int main(int ac, char *av[])
{
	char	found[255];
	int		i;
	int		j;

	i = 0;
	if (ac == 3)
	{
		while (av[1][i])
		{
			j = 0;
			while (av[2][j])
			{
				if (found[(int)av[1][i]] != 1 && (av[1][i] == av[2][j]))
				{
					write(1, &av[1][i], 1);
					found[(int)av[1][i]] = 1;
				}
				j++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}