/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 12:10:16 by romoreir          #+#    #+#             */
/*   Updated: 2021/09/25 13:13:15 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	sort_five(t_stacks *stacks)
{
	(void)stacks;
}

static void	sort_four(t_stacks *stacks)
{
	(void)stacks;
}

static void	sort_three(t_stacks *stacks)
{
	(void)stacks;
}

static void	sort_two(t_stacks *stacks)
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
