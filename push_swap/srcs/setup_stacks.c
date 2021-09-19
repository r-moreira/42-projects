#include "../includes/push_swap.h"

void	init_stacks(t_stacks *stacks, int argc)
{
	stacks->a = NULL;
	stacks->b = NULL;
	stacks->len = argc - 1;
}

//////////////TO-DO////////////////////
///Adicionar index na lista ligada da stack A de trás para frente
//////////////////////////////////////
void	setup_stacks(t_stacks *stacks, int argc, unsigned int *index)
{
	init_stacks(stacks, argc);
	(void)index;
}
