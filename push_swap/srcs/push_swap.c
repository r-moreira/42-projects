#include "../includes/push_swap.h"

//////////////TO-DO////////////////////
///Organizar funções de listas ligadas
///Começar a implentar as operações necessários de acordo com o guia do medium
//////////////////////////////////////
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

void print_binary(unsigned int number)
{
    if (number >> 1) {
        print_binary(number >> 1);
    }
    putc((number & 1) ? '1' : '0', stdout);
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
	print_things(argc, numbers, index, &stacks); //Temporary
	return (exit_free(numbers, index, &stacks));
}
