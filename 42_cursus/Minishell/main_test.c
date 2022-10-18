/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audreyer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 19:45:28 by audreyer          #+#    #+#             */
/*   Updated: 2022/10/13 19:54:54 by audreyer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendu_minishell/include/minishell.h"
#include <linux/limits.h>

int	main(int argc, char **argv, char **env)
{
	char	buff[PATH_MAX];
	
	if (chdir(argv[1]) != 0)
		printf("chdir error\nErrno = %d\n", errno);
	getcwd(buff, PATH_MAX);
	printf("curent directory = %s\n", buff);
	return (0);
}
