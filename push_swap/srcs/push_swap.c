#include "../includes/push_swap.h"

int main(int argc, char **argv) {

	int *numbers;
	numbers = handle_args(argc, argv);

	for (int i = 0; i < argc - 1; i++)
		printf("%d\n", numbers[i]);

	free(numbers);
	return 0;
}
