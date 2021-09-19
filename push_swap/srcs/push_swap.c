#include "../includes/push_swap.h"

//////////////TO-DO////////////////////
///Adicionar index na lista ligada da stack A de trás para frente
//////////////////////////////////////

void print_binary(unsigned int number) //Temporary
{
    if (number >> 1) {
        print_binary(number >> 1);
    }
    putc((number & 1) ? '1' : '0', stdout);
}

int main(int argc, char **argv) {

	int 			*numbers;
	unsigned int 	*index;

	numbers = handle_args(argc, argv);

	for (int i = 0; i < argc - 1; i++) //Temporary
		printf("%d\n", numbers[i]);

	index = create_index(numbers, argc);

	printf("-------\n"); //Temporary
	for (int i = 0; i < argc - 1; i++)
		printf("%d\n", index[i]);

	printf("-------\n"); //Temporary
	for (int i = 0; i < argc - 1; i++) {
		print_binary(index[i]);
		printf("\n");
	}

	free(index);
	free(numbers);
	return 0;
}
