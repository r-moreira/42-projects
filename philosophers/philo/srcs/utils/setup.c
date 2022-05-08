/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 00:08:00 by romoreir          #+#    #+#             */
/*   Updated: 2022/04/15 16:09:43 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

static void	setup_philosophers(t_control *control)
{
	int	i;

	i = -1;
	while (++i < control->philosopher_number)
	{
		control->philo[i].id = i + 1;
		control->philo[i].left_fork = i;
		control->philo[i].right_fork = i + 1;
		if (i + 1 == control->philosopher_number)
			control->philo[i].right_fork = 0;
		control->philo[i].ms_last_meal = get_current_time();
		control->philo[i].current_meals_count = 0;
		control->philo[i].control = control;
		pthread_mutex_init(&control->forks[i], NULL);
	}
}

static void	setup_controller_utils(t_control *control)
{
	control->is_dead = FALSE;
	control->is_philos_full_up = FALSE;
	control->forks = NULL;
	control->required_meals_count = 0;
	control->ms_start_meal = get_current_time();
	control->forks = malloc(
			control->philosopher_number * sizeof(pthread_mutex_t));
	control->philo = malloc(sizeof(t_philo) * control->philosopher_number);
}

static void	setup_args(t_control *control, int argc, char **argv)
{
	control->required_meals = -1;
	control->philosopher_number = ft_atoi(argv[1]);
	control->ms_to_die = ft_atoi(argv[2]);
	control->ms_to_eat = ft_atoi(argv[3]);
	control->ms_to_sleep = ft_atoi(argv[4]);
	if (argc > 5)
		control->required_meals = ft_atoi(argv[5]);
}

void	setup(t_control *control, int argc, char **argv)
{
	setup_args(control, argc, argv);
	setup_controller_utils(control);
	setup_philosophers(control);
}
