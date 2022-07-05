/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libpushswap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 11:25:53 by mgirardo          #+#    #+#             */
/*   Updated: 2022/07/05 11:26:09 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPUSHSWAP_H
# define LIBPUSHSWAP_H

# include <stddef.h>
# include <string.h>
# include <stdio.h>
# include <stddef.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct	v_list
{
	int					content;
	struct v_list		*next;
}				t_ps_list;

int			main(int ac, char **av);
int			ft_ps_parsing(int ac, char **av);
int			ft_ps_atoi(char *nptr, int *error);
int			ft_ps_intcheck(char **av);
int			ft_ps_duplicatecheck(char **av);
t_ps_list	*fill_stack_a(char **av);
t_ps_list	*ft_ps_lstnew(int content);
void		ft_ps_lstadd_back(t_ps_list **alst, t_ps_list *new);

#endif