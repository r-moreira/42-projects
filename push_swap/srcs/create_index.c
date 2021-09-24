/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_index.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 20:39:03 by romoreir          #+#    #+#             */
/*   Updated: 2021/09/24 20:39:05 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	*copy_vector(int *numbers, int argc)
{
	int	*copy;
	int	i;

	copy = malloc((sizeof(int) * argc));
	if (!copy)
		exit(EXIT_FAILURE);
	i = -1;
	while (++i < argc - 1)
		copy[i] = numbers[i];
	return (copy);
}

static int	*quick_sort(int *numbers, int argc)
{
	int	*copy;
	int	aux;
	int	i;

	copy = copy_vector(numbers, argc);
	i = -1;
	while (++i < argc - 2)
	{
		if (copy[i] > copy[i + 1])
		{
			aux = copy[i];
			copy[i] = copy[i + 1];
			copy[i + 1] = aux;
			i = -1;
		}
	}
	return (copy);
}

static unsigned int	*get_index(int *numbers, int *sorted, int argc)
{
	unsigned int	*index;
	int				i;
	int				j;

	index = malloc((sizeof(unsigned int) * argc));
	i = -1;
	while (++i < argc - 1)
	{
		j = 0;
		while (numbers[i] != sorted[j])
			j++;
		index[i] = j;
	}
	return (index);
}

unsigned int	*create_index(int *numbers, int argc)
{
	int				*sorted;
	unsigned int	*index;

	sorted = quick_sort(numbers, argc);
	index = get_index(numbers, sorted, argc);
	free(sorted);
	return (index);
}
