#include "../includes/push_swap.h"

void	init_stacks(t_stacks *stacks, int argc)
{
	stacks->a = NULL;
	stacks->b = NULL;
	stacks->top_a = NULL;
	stacks->top_b = NULL;
	stacks->len = argc - 1;
}

void display_a(t_stacks *stacks)
{
    t_node *temp;

	temp = stacks->top_a;
	if (stacks->top_a == NULL)
		printf("\nStack is Empty!!!\n");
	else
	{
		while (temp->next != NULL)
		{
			printf("%d--->",temp->index);
			temp = temp -> next;
		}
    	printf("%d--->NULL",temp->index);
	}
}
void	push_a(t_stacks *stacks, unsigned int index)
{
	t_node *new;

	new = (t_node *)malloc(sizeof(t_node));
	new->index = index;
	if (stacks->top_a == NULL)
		new->next = NULL;
	else
		new->next = stacks->top_a;
	stacks->top_a = new;
}

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
void	setup_stacks(t_stacks *stacks, int argc, unsigned int *index)
{
	int	 i;

	init_stacks(stacks, argc);
	i = stacks->len;
	while (i > 0) {
		push_a(stacks, index[i - 1]);
		i--;
	}
	display_a(stacks);
		i = stacks->len;
	free_a(stacks);
}
