/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 12:10:16 by romoreir          #+#    #+#             */
/*   Updated: 2021/09/25 16:26:35 by romoreir         ###   ########.fr       */
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

static void	sort_three(t_stacks *stacks, int first, int second, int third)
{
	if (first < second)
	{
		if (first < third) //1 3 2 -> 3 1 2 -> 1 2 3
		{
			sa(stacks);
			ra(stacks);
		}
		if (first > third) // 2 3 1 -> 3 2 1 -> 2 1 3 -> 1 2 3
		{
			sa(stacks);
			ra(stacks);
			sa(stacks);
		}
	}
	else if (first > second)
	{
		if (first < third) //2 1 3 -> 1 2 3
			sa(stacks);
		if (first > third)
		{
			if (second < third) //3 1 2 -> 1 2 3
				ra(stacks);
			if (second > third) // 3 2 1
			{
				ra(stacks);
				sa(stacks);
			}
		}
	}
}

static void	sort_four(t_stacks *stacks, int first, int second, int third)
{
	while (stacks->a->index != 0)
		ra(stacks);
	pb(stacks);
	sort_three(stacks, first, second, third);
	pa(stacks);
}

static void	sort_five(t_stacks *stacks, int first, int second, int third)
{
	int i;

	i = -1;
	while (++i < 5) {
		if (stacks->a->index == 0 || stacks->a->index == 1)
			pb(stacks);
		else
			ra(stacks);
	}
	sort_three(stacks, first, second, third);
	pa(stacks);
	pa(stacks);
	if (stacks->a->index > stacks->a->next->index)
		sa(stacks);
}

void	sort_small_stack(t_stacks *stacks)
{
	int	first;
	int	second;
	int	third;

	first = stacks->a->index;
	second = stacks->a->next->index;
	third = stacks->a->next->next->index;
	if (stacks->len == 2)
		sort_two(stacks);
	else if (stacks->len == 3)
		sort_three(stacks, first, second, third);
	else if (stacks->len == 4)
		sort_four(stacks, first, second, third);
	else if (stacks->len == 5)
		sort_five(stacks, first, second, third);
}
