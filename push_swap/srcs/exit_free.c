#include "../includes/push_swap.h"

void	free_a(t_stacks *stacks)
{
	t_node *temp;

   	while (stacks->top_a != NULL)
	{
		temp = stacks->top_a;
		stacks->top_a = temp->next;
		free(temp);
   	}
}

int	exit_free(int *numbers, unsigned int *index, t_stacks *stacks)
{
	free(index);
	free(numbers);
	free_a(stacks);

	return (EXIT_SUCCESS);
}
