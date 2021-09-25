/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 20:40:57 by romoreir          #+#    #+#             */
/*   Updated: 2021/09/25 14:22:50 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_stacks *stacks)
{
	t_node	*top;
	t_node	*bottom;

	if (stacks->a)
	{
		top = stacks->a;
		bottom = stacks->a;
		while (bottom->next != NULL)
			bottom = bottom->next;
		stacks->a = top->next;
		top->next = NULL;
		bottom->next = top;
		ft_putstr_fd("ra\n", 1);
	}
}

void	pb(t_stacks *stacks)
{
	t_node	*top;

	if (stacks->a)
	{
		top = stacks->a;
		stacks->a = top->next;
		top->next = stacks->b;
		stacks->b = top;
		ft_putstr_fd("pb\n", 1);
	}
}

void	pa(t_stacks *stacks)
{
	t_node	*top;

	if (stacks->b)
	{
		top = stacks->b;
		stacks->b = top->next;
		top->next = stacks->a;
		stacks->a = top;
		ft_putstr_fd("pa\n", 1);
	}
}

void	sa(t_stacks *stacks)
{
	int	first;
	int	second;

	if (stacks->a)
	{
		first = stacks->a->index;
		second = stacks->a->next->index;
		stacks->a->index = second;
		stacks->a->next->index = first;
		ft_putstr_fd("sa\n", 1);
	}
}
