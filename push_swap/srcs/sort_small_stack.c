/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 12:10:16 by romoreir          #+#    #+#             */
/*   Updated: 2021/09/25 15:08:55 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	sort_two(t_stacks *stacks)
{
	int	first;
	int	second;

	first = stacks->a->index;
	second = stacks->a->next->index;
	if (first > second)
		ra(stacks);
}

static void	sort_three(t_stacks *stacks)
{
	int	first;
	int	second;
	int	third;

	first = stacks->a->index;
	second = stacks->a->next->index;
	third = stacks->a->next->next->index;

	if (first < second && second > third) // 1 3 2 - 2 3 1
	{
		sa(stacks);
		ra(stacks);
		sa(stacks);
	}
	else if (first > second && second < third) // 2 1 3 - 3 1 2
	{
		sa(stacks);
	}
	else if (first > second && second > third) // 3 2 1
	{
		ra(stacks);
		sa(stacks);
	}
}

static void	sort_four(t_stacks *stacks)
{
	while (stacks->a->index != 0)
		ra(stacks);
	pb(stacks);
	sort_three(stacks);
	pa(stacks);
}

static void	sort_five(t_stacks *stacks)
{
	(void)stacks;
}

void	sort_small_stack(t_stacks *stacks)
{
	if (stacks->len == 2)
		sort_two(stacks);
	else if (stacks->len == 3)
		sort_three(stacks);
	else if (stacks->len == 4)
		sort_four(stacks);
	else if (stacks->len == 5)
		sort_five(stacks);
}
