/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_validator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 01:00:48 by romoreir          #+#    #+#             */
/*   Updated: 2022/04/15 16:08:40 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

t_bool	is_number_of_philos_valid(char **argv)
{
	int	number_of_philosophers;

	number_of_philosophers = ft_atoi(argv[1]);
	if (number_of_philosophers < 1)
	{
		printf("%s\n", ERR_PHIL_NUM);
		return (FALSE);
	}
	return (TRUE);
}

t_bool	is_number_of_arguments_valid(int argc)
{
	if (argc != 5 && argc != 6)
	{
		printf("%s\n", ERR_INVALID_ARGS);
		return (FALSE);
	}
	return (TRUE);
}

t_bool	is_args_only_digits(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j])
		{
			if (!ft_isdigit(argv[i][j]))
			{
				printf("%s\n", ERR_ONLY_DIGITS_ARGS);
				return (FALSE);
			}
		}
	}
	return (TRUE);
}

t_bool	is_args_valid(int argc, char **argv)
{
	if (!is_number_of_arguments_valid(argc))
		return (FALSE);
	if (!is_number_of_philos_valid(argv))
		return (FALSE);
	if (!is_args_only_digits(argc, argv))
		return (FALSE);
	return (TRUE);
}
