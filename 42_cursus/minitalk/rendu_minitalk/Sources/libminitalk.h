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

typedef struct s_to_send
{
	char	*message;
	int		cursor;
	pit_t	server_pid;
	int		binary;
}	t_to_send;

#endif




#ifndef MINITALK_CLIENT_H
# define MINITALK_CLIENT_H

typedef struct s_send
{
	char	*str;
	int		current;
	int		pid;
	int		binary;
}	t_send;

#endif

typedef enum e_bool {
	TRUE = 1,
	FALSE = 0
}	t_bool;


#ifndef MINITALK_SERVER_H
# define MINITALK_SERVER_H

typedef struct sigaction	t_sigation;

typedef struct s_dynamic_buffer
{
	char	*buffer;
	int		i;
	int		size;
}	t_dynamic_buffer;

typedef struct s_read
{
	int					char_read[8];
	t_dynamic_buffer	buffer;
}	t_read;

t_dynamic_buffer	init_buffer(void);
t_dynamic_buffer	append(t_dynamic_buffer buffer, char c);
t_dynamic_buffer	print_content_and_reset(t_dynamic_buffer buffer, int pid);
void				reset_char_read(void);
void				append_char_received(char c, int pid);
void				make_read(int signum, int current, int pid);
void				init_on_signal(int pid);
void				signal_handler(int signum, siginfo_t *siginfo,
						void *ucontext);
char				get_char_from_byte(t_read read);

#endif