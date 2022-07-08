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

typedef struct v_pair
{
	int				content_a;
	int				content_b;
	int				nb_moves_a;
	int				nb_moves_b;
	int				tt_nb_moves;
	int				nb_rb;
	int				nb_ra;
	int				nb_rr;
	int				nb_rra;
	int				nb_rrb;
	int				nb_rrr;
	struct v_pair	*next;
}				t_pair;

int			main(int ac, char **av);
int			ft_ps_parsing(int ac, char **av);
int			ft_ps_atoi(char *nptr, int *error);
int			ft_ps_intcheck(char **av);
int			ft_ps_duplicatecheck(char **av);
t_ps_list	*fill_stack_a(char **av);
t_ps_list	*ft_ps_lstnew(int content);
void		ft_ps_lstadd_back(t_ps_list **alst, t_ps_list *new);
void		ft_ps_lstclear(t_ps_list **lst);
t_ps_list	*ft_ps_lstlast(t_ps_list *stack);
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
void		to_the_top(t_ps_list **stack, int value, char which);
void		to_the_top_a(t_ps_list **stack, int value);
void		to_the_top_b(t_ps_list **stack, int value);
void		sort_four(t_ps_list **stack_a, t_ps_list **stack_b);
void		sort_five(t_ps_list **stack_a, t_ps_list **stack_b);
int			place(t_ps_list *stack, int value);
int			smallest(t_ps_list *stack);
int			smallest_bis(t_ps_list *stack, int value);
int			stack_size(t_ps_list *stack);
int			biggest(t_ps_list *stack);
int			biggest_bis(t_ps_list *stack, int value);
t_ps_list	*sort_stack(t_ps_list **stack);
int			median_value(t_ps_list *stack, int place);
int			find_median(t_ps_list **stack);
void		first_triage(t_ps_list **stack_a, t_ps_list **stack_b, int median);
t_pair		pairs(t_ps_list **stack_a, t_ps_list **stack_b);
void		to_move_a_pair(t_ps_list **stack_a, t_ps_list **stack_b);
void		sort(t_ps_list **stack_a, t_ps_list **stack_b);
t_pair		*ft_pair_lstnew(int c_a, int c_b, int m_a, int m_b);
void		ft_pair_lstadd_back(t_pair **alst, t_pair *new);
void		ft_pair_lstclear(t_pair **lst);
t_pair		costless_pair(t_pair *pairs);
void		moves(t_pair **info);
int			tiniest(int i1, int i2);
int			taller(int i1, int i2);
int			nb_move(t_ps_list *stack, int value);

#endif