#include "../includes/push_swap.h"

void	free_a(t_stacks *stacks)
{
	t_node *temp;

   	while (stacks->a != NULL)
	{
		temp = stacks->a;
		stacks->a = temp->next;
		free(temp);
   	}
}

void	free_b(t_stacks *stacks)
{
	t_node *temp;

   	while (stacks->b != NULL)
	{
		temp = stacks->b;
		stacks->b = temp->next;
		free(temp);
   	}
}

int	exit_free(int *numbers, unsigned int *index, t_stacks *stacks)
{
	free(index);
	free(numbers);
	free_a(stacks);
	free_b(stacks);
	return (EXIT_SUCCESS);
}
