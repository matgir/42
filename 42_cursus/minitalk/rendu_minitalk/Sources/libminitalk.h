/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libminitalk.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 16:48:53 by mgirardo          #+#    #+#             */
/*   Updated: 2022/07/18 16:48:56 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBMINITALK_H
# define LIBMINITALK_H

/*########## INCLUDE ##########*/

# include <signal.h>
# include "../libft/libft.h"
# include <sys/types.h>

/*########## STRUCT' ##########*/

typedef struct s_to_send
{
	char	*message;
	int		cursor;
	int		server_pid;
	int		shift;
}	t_to_send;

typedef struct sigaction	t_sigation;

typedef struct s_to_print
{
	int		bits[8];
	char	*to_print;
	int		client_pid;
}	t_to_print;

/*########## FUNCTIONS ##########*/

char	*ft_mntlk_strjoin(char *str, char c);
void	reset_bits(void);
void	join_char(char c);
char	bits_to_char(t_to_print infos);
void	get_bits(int sig, int cursor);
void	server_signal(int sig, siginfo_t *siginfo, void *ucontext);

void	client_signal(int sig);
void	send_char(void);
void	send_byte(char c);
void	parsing_minitalk(int ac, char **av);
int		ft_mntlk_intcheck(char *av);
int		digit_check(char *str);
int		ft_mntlk_atoi(char *nptr, int *error);

#endif
