/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 20:39:43 by romoreir          #+#    #+#             */
/*   Updated: 2021/09/24 20:39:45 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_a(t_stacks *stacks)
{
	t_node	*temp;

	while (stacks->a != NULL)
	{
		temp = stacks->a;
		stacks->a = temp->next;
		free(temp);
	}
}

void	free_b(t_stacks *stacks)
{
	t_node	*temp;

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
