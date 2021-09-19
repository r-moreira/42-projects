#include "../includes/push_swap.h"

////////////////TO-DO//////////////
//Simplificar números
//Criar structs para listas ligadas
//Criar um array de strings com os valores dos números simplificados em binário
//Adicionar string de binários na lista ligada
//Dividir o algoritmo de ordenação em short e long
//Desenvolver operações de lista ligada e swap
//Desenvolver algoritmo de ordenação long
//Desenvolver algoritmo de ordenação short
//////////////////////////////////

int main(int argc, char **argv) {

	int *numbers;
	int *index;

	numbers = handle_args(argc, argv);

	for (int i = 0; i < argc - 1; i++) //Temporary
		printf("%d\n", numbers[i]); //Temporary

	index = create_index(numbers, argc);

	printf("-------\n");
	for (int i = 0; i < argc - 1; i++) //Temporary
		printf("%d\n", index[i]); //Temporary

	free(index);
	free(numbers);
	return 0;
}
