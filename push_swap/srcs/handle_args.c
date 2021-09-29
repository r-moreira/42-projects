/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 20:40:19 by romoreir          #+#    #+#             */
/*   Updated: 2021/09/28 23:33:57 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	numbers_is_sorted(int argc, int *numbers)
{
	int	i;
	int	len;

	len = argc - 2;
	i = 0;
	while (i < len && numbers[i] < numbers[i + 1])
		i++;
	if (i == len)
		exit(EXIT_SUCCESS);
}

static int	*get_numbers(int argc, char **argv)
{
	int	i;
	int	*numbers;

	numbers = malloc((sizeof(int) * (argc - 1)) + 1);
	if (!numbers)
		exit_failure("Failed to allocate memory");
	i = -1;
	while (++i < argc - 1)
		numbers[i] = ft_atoi(argv[i + 1]);
	return (numbers);
}

static void	validate_integers(char *argv)
{
	int		i;
	long	num;
	t_bool	is_negative;

	num = 0;
	if (argv[0] == '-' && !ft_isdigit(argv[1]))
		exit_failure("The arguments must contain only valid integers");
	if (argv[0] == '-')
		is_negative = TRUE;
	else
		is_negative = FALSE;
	i = is_negative - 1;
	while (argv[++i])
	{
		if (!ft_isdigit(argv[i]))
			exit_failure("The arguments must contain only valid integers");
		num = num * 10 + argv[i] - '0';
	}
	if (is_negative)
		num = -num;
	if (num < INT_MIN || num > INT_MAX)
		exit_failure("The arguments must not overflow integers range");
}

int	*handle_args(int argc, char **argv)
{
	int	i;
	int	*numbers;

	if (argc == 1)
		exit(EXIT_SUCCESS);
	i = 0;
	while (++i < argc)
		validate_integers(argv[i]);
	numbers = get_numbers(argc, argv);
	numbers_is_sorted(argc, numbers);
	return (numbers);
}
