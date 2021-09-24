#include "../includes/push_swap.h"

void	init_stacks(t_stacks *stacks, int argc)
{
	stacks->a = NULL;
	stacks->b = NULL;
	stacks->len = argc - 1;
}

void	push_a(t_stacks *stacks, unsigned int index)
{
	t_node *new;

	new = (t_node *)malloc(sizeof(t_node));
	new->index = index;
	if (stacks->a == NULL)
		new->next = NULL;
	else
		new->next = stacks->a;
	stacks->a = new;
}

void	put_indexes_into_stack_a(t_stacks *stacks, unsigned int *index)
{
	int	 i;

	i = stacks->len;
	while (i > 0) {
		push_a(stacks, index[i - 1]);
		i--;
	}
}

void	setup_stacks(t_stacks *stacks, int argc, unsigned int *index)
{
	init_stacks(stacks, argc);
	put_indexes_into_stack_a(stacks, index);
}