/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 12:10:16 by romoreir          #+#    #+#             */
/*   Updated: 2021/09/29 18:55:28 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	sort_three_first_less_than_second(t_stacks *stacks,
int first, int second, int third)
{
	if (first < third)
	{
		if (second < third)
			return ;
		if (second > third)
		{
			sa(stacks);
			ra(stacks);
		}
	}
	if (first > third)
	{
		sa(stacks);
		ra(stacks);
		sa(stacks);
	}
}

static void	sort_three_first_greater_than_second(t_stacks *stacks,
int first, int second, int third)
{
	if (first < third)
		sa(stacks);
	if (first > third)
	{
		if (second < third)
			ra(stacks);
		if (second > third)
		{
			ra(stacks);
			sa(stacks);
		}
	}
}

static void	sort_four(t_stacks *stacks)
{
	int	first;
	int	second;
	int	third;

	while (stacks->a->index != 0)
		ra(stacks);
	pb(stacks);
	first = stacks->a->index;
	second = stacks->a->next->index;
	third = stacks->a->next->next->index;
	if (first > second)
		sort_three_first_greater_than_second(stacks, first, second, third);
	if (first < second)
		sort_three_first_less_than_second(stacks, first, second, third);
	pa(stacks);
}

static void	sort_five(t_stacks *stacks)
{
	int	first;
	int	second;
	int	third;
	int	i;

	i = -1;
	while (++i < 5)
	{
		if (stacks->a->index == 0 || stacks->a->index == 1)
			pb(stacks);
		else
			ra(stacks);
	}
	first = stacks->a->index;
	second = stacks->a->next->index;
	third = stacks->a->next->next->index;
	if (first > second)
		sort_three_first_greater_than_second(stacks, first, second, third);
	if (first < second)
		sort_three_first_less_than_second(stacks, first, second, third);
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
	if (stacks->len > 2)
		third = stacks->a->next->next->index;
	if (stacks->len == 2)
	{
		if (first > second)
			ra(stacks);
	}
	else if (stacks->len == 3)
	{
		if (first > second)
			sort_three_first_greater_than_second(stacks, first, second, third);
		if (first < second)
			sort_three_first_less_than_second(stacks, first, second, third);
	}
	else if (stacks->len == 4)
		sort_four(stacks);
	else if (stacks->len == 5)
		sort_five(stacks);
}
