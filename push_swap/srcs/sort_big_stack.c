/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 20:38:32 by romoreir          #+#    #+#             */
/*   Updated: 2021/09/24 20:42:15 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	radix_sort(t_stacks *stacks, unsigned int max_bits)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	num;

	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < stacks->len)
		{
			num = stacks->a->index;
			if (((num >> i) & 1) == 1)
				ra(stacks);
			else
				pb(stacks);
			j++;
		}
		while (stacks->b != NULL)
			pa(stacks);
		i++;
	}
}

void	sort_big_stack(t_stacks *stacks)
{
	unsigned int	max_num;
	unsigned int	max_bits;

	max_num = stacks->len - 1;
	max_bits = 0;
	while ((max_num >> max_bits) != 0)
		++max_bits;
	radix_sort(stacks, max_bits);
}
