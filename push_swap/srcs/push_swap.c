/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 20:42:25 by romoreir          #+#    #+#             */
/*   Updated: 2021/09/29 18:55:55 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

////////////////// TO-DO ///////////////////////
// 1) Fazer checagem de argumentos duplicados
// 3) Continuar testando a partir de: Push_swap - Simple version.
///////////////////////////////////////////////

int	main(int argc, char **argv)
{
	int			*numbers;
	int			*index;
	t_stacks	stacks;

	numbers = handle_args(argc, argv);
	index = create_index(numbers, argc);
	setup_stacks(&stacks, argc, index);
	if (stacks.len <= 5)
		sort_small_stack(&stacks);
	else
		sort_big_stack(&stacks);
	return (exit_free(numbers, index, &stacks));
}
