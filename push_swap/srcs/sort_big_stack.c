#include "../includes/push_swap.h"

void	sort_big_stack(t_stacks *stacks)
{
	unsigned int	max_num;
	unsigned int	max_bits;
	unsigned int	i;
	unsigned int	j;

	max_num = stacks->len - 1;
	max_bits = 0;
	while ((max_num >> max_bits) != 0)
		++max_bits;

	int	num;

	i = 0;
	while (++i < max_bits)
	{
		j = 0;
		while (++j < stacks->len)
		{
			num = stacks->a->index;
			if (((num >> i) & i) == 1)
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
