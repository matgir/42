#include <stdio.h>
#include <string.h>

int	ft_strlen(char	*str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	printf("%d", i);
	return (i);
}

int	main()
{
	char str[] = "1234567891113151719212325272931";
	ft_strlen(str);
	printf("%lu",strlen(str));
	return (0);
}
