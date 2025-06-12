/*#include <unistd.h>

int main(int ac, char **av)
{
    char    found[255];
    int     i;
    int     j;
    int     k;

    if (ac == 3)
    {
        i = 0;
        while (av[1][i])
        {
            j = i + 1;
            while (av[1][j])
            {
                if (found[av[1][j]] != 1 && found[av[1][i]] == found[av[1][j]])
                {
                    write(1, &found[av[1][j]], 1);
                    found[av[1][j]] = 1;
                }
                j++;
            }
            k = 0;
            while (av[2][k])
            {
                if (found[av[2][k]] != 1 && found[av[1][i]] == found[av[2][k]])
                {
                    write(1, &found[av[2][k]], 1);
                    found[av[2][k]] = 1;
                }
                k++;
            }
        }
    }
    write(1, "\n", 1);
    return (0);
}*/



#include <unistd.h>

int	main(int argc, char *argv[])
{
	char	map[255];
	int		i;

	i = -1;
	if (argc == 3)
	{
		while (argv[1][++i])
		{
			if (map[(int)argv[1][i]] != 1)
			{
				write(1, &argv[1][i], 1);
				map[(int)argv[1][i]] = 1;
			}
		}
		i = -1;
		while (argv[2][++i])
		{
			if (map[(int)argv[2][i]] != 1)
			{
				write(1, &argv[2][i], 1);
				map[(int)argv[2][i]] = 1;
			}
		}
	}
	write(1, "\n", 1);
}