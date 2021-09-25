/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 20:38:32 by romoreir          #+#    #+#             */
/*   Updated: 2021/09/25 13:13:55 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	radix_sort(t_stacks *stacks, int max_bits)
{
	int	i;
	int	j;
	int	num;

	i = -1;
	while (++i < max_bits)
	{
		j = -1;
		while (++j < stacks->len)
		{
			num = stacks->a->index;
			if (((num >> i) & 1) == 1)
				ra(stacks);
			else
				pb(stacks);
		}
		while (stacks->b != NULL)
			pa(stacks);
	}
}

void	sort_big_stack(t_stacks *stacks)
{
	int	max_num;
	int	max_bits;

	max_num = stacks->len - 1;
	max_bits = 0;
	while ((max_num >> max_bits) != 0)
		++max_bits;
	radix_sort(stacks, max_bits);
}
