#include "../includes/push_swap.h"

//////////////TO-DO////////////////////
///Organizar funções de listas ligadas
///Começar a implentar as operações necessários de acordo com o guia do medium
//////////////////////////////////////

void print_binary(unsigned int number)
{
    if (number >> 1) {
        print_binary(number >> 1);
    }
    putc((number & 1) ? '1' : '0', stdout);
}

void display_a(t_stacks *stacks)
{
    t_node *temp;

	printf("A | ");
	temp = stacks->a;
	if (stacks->a == NULL)
		printf("Empty\n");
	else
	{
		while (temp->next != NULL)
		{
			printf("%d--->",temp->index);
			temp = temp -> next;
		}
    	printf("%d--->NULL",temp->index);
	}
	printf("\n");
}

void display_a_bin(t_stacks *stacks)
{
    t_node *temp;

	temp = stacks->a;
	if (stacks->a == NULL)
		printf("Empty\n");
	else
	{
		while (temp->next != NULL)
		{
			print_binary(temp->index);
			printf(" | %u\n", temp->index);
			temp = temp -> next;
		}
	}
	printf("\n");
}

void display_b(t_stacks *stacks)
{
    t_node *temp;

	printf("B | ");
	temp = stacks->b;
	if (stacks->b == NULL)
		printf("Empty\n");
	else
	{
		while (temp->next != NULL)
		{
			printf("%d--->",temp->index);
			temp = temp -> next;
		}
    	printf("%d--->NULL",temp->index);
	}
	printf("\n");
}

void print_things(int argc, int *numbers, unsigned int *index, t_stacks *stacks)
{
	printf("-------\n");
	for (int i = 0; i < argc - 1; i++)
		printf("%d\n", numbers[i]);
	printf("-------\n");
	for (int i = 0; i < argc - 1; i++)
		printf("%d\n", index[i]);
	printf("-------\n");
	for (int i = 0; i < argc - 1; i++) {
		print_binary(index[i]);
		printf("\n");
	}
	printf("-------\n");
	display_a(stacks);
}


int main(int argc, char **argv) {

	int 			*numbers;
	unsigned int 	*index;
	t_stacks		stacks;

	numbers = handle_args(argc, argv);
	index = create_index(numbers, argc);
	setup_stacks(&stacks, argc, index);
	sort_big_stack(&stacks);
	return (exit_free(numbers, index, &stacks));
}
