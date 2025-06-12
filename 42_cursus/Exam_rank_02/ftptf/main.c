#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

int	ft_printf(const char *str, ... );

int	main(void)
{
	char			str[] = "et bonjour";
	int				i = 31;

	printf("\n%i\n", ft_printf("bonsoir %s %d %x %s %s", str, i, i, str, NULL));
    printf("\n%i\n", printf("bonsoir %s %d %x %s %s", str, i, i, str, NULL));
	printf("\n%i\n", printf("%%%%%%%%%%%%&%%%%%%%%%%"));
	printf("\n%i\n", ft_printf("%%%%%%%%%%%%&%%%%%%%%%%"));
}