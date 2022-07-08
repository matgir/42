/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgirardo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 16:57:36 by mgirardo          #+#    #+#             */
/*   Updated: 2022/07/08 16:57:38 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpushswap.h"

void	execute_order_66_bis(t_ps_list **stack_a, t_ps_list **stack_b, char *l)
{
	if (ft_strncmp(l, "pa\n", 3) == 0)
		push(stack_b, stack_a);
	if (ft_strncmp(l, "pb\n", 3) == 0)
		push(stack_a, stack_b);
	if (ft_strncmp(l, "ra\n", 3) == 0)
		rotate(stack_a);
	if (ft_strncmp(l, "rb\n", 3) == 0)
		rotate(stack_b);
	if (ft_strncmp(l, "rr\n", 3) == 0)
	{
		rotate(stack_a);
		rotate(stack_b);
	}
	if (ft_strncmp(l, "rra\n", 4) == 0)
		reverse_rotate(stack_a);
	if (ft_strncmp(l, "rrb\n", 4) == 0)
		reverse_rotate(stack_b);
	if (ft_strncmp(l, "rrr\n", 4) == 0)
	{
		reverse_rotate(stack_a);
		reverse_rotate(stack_b);
	}
}

void	check_line(char *line, t_ps_list **stack_a, t_ps_list **stack_b)
{
	char	*tab[11];
	int		i;
	int		check;

	fill_tab(tab);
	i = -1;
	check = -1;
	while (++i <= 7)
	{
		if (ft_strncmp(line, tab[i], 3) == 0)
			check = 0;
	}
	while (i <= 11)
	{
		if (ft_strncmp(line, tab[i++], 4) == 0)
			check = 0;
	}
	if (check == -1)
	{
		free(line);
		ft_ps_lstclear(stack_a);
		ft_ps_lstclear(stack_b);
		ft_putendl_fd("Error", 2);
		exit (-1);
	}
}

int	execute_order_66(t_ps_list **stack_a, t_ps_list **stack_b)
{
	char	*line;
	int		fd;

	fd = 0;
	while (stack_b != NULL)
	{
		line = get_next_line(0);
		if (line == NULL)
			return (1);
		check_line(line, stack_a, stack_b);
		if (ft_strncmp(line, "sa\n", 3) == 0)
			swap(stack_a);
		if (ft_strncmp(line, "sb\n", 3) == 0)
			swap(stack_b);
		if (ft_strncmp(line, "ss\n", 3) == 0)
		{
			swap(stack_a);
			swap(stack_b);
		}
		execute_order_66_bis(stack_a, stack_b, line);
		free(line);
	}
	return (0);
}

int	checker(t_ps_list **stack_a)
{
	t_ps_list	*stack_b;

	stack_b = NULL;
	while (1)
	{
		if (stack_b == NULL && is_it_good(stack_a) == 0)
			return (0);
		if (execute_order_66(stack_a, &stack_b) == 1)
		{
			if (is_it_good(stack_a) != 0)
				return (1);
			else
				return (0);
		}
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_ps_list	*stack_a;

	if (ft_ps_parsing(ac, av) == 0)
		return (0);
	stack_a = fill_stack_a(av);
	if (stack_a == NULL)
		return (0);
	if (checker(&stack_a) == 0)
	{
		ft_ps_lstclear(&stack_a);
		ft_putendl_fd("OK", 1);
	}
	else
	{
		ft_ps_lstclear(&stack_a);
		ft_putendl_fd("KO", 1);
	}
	return (0);
}
