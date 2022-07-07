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

typedef struct v_list
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
void		ft_ps_lstclear(t_ps_list **lst);
int			swaping(t_ps_list **stack_a);
void		push_b(t_ps_list **stack_a, t_ps_list **stack_b);
void		push_a(t_ps_list **stack_a, t_ps_list **stack_b);
int			push(t_ps_list **from, t_ps_list **to);
void		double_swap(t_ps_list **stack_a, t_ps_list **stack_b);
void		swap_b(t_ps_list **stack_b);
void		swap_a(t_ps_list **stack_a);
int			swap(t_ps_list **stack);
void		print_stack(t_ps_list	*stack, char *name);
void		double_rotate(t_ps_list **stack_a, t_ps_list **stack_b);
void		rotate_b(t_ps_list **stack_b);
void		rotate_a(t_ps_list **stack_a);
int			rotate(t_ps_list **stack);
int			reverse_rotate(t_ps_list **stack);
void		reverse_a(t_ps_list **stack_a);
void		reverse_b(t_ps_list **stack_b);
void		double_reverse_rotate(t_ps_list **stack_a, t_ps_list **stack_b);
int			is_it_good(t_ps_list **stack);
void		start_sort(t_ps_list **stack_a, t_ps_list **stack_b);
void		sort_three(t_ps_list **stack);

#endif