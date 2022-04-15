/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_routine.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 22:35:50 by romoreir          #+#    #+#             */
/*   Updated: 2022/04/15 15:43:54 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

static void	*handle_one_philosopher(t_philo *philo)
{
	pthread_mutex_lock(&philo->control->forks[philo->right_fork]);
	status_routine(philo, get_current_time(), "has taken a fork");
	pthread_mutex_unlock(&philo->control->forks[philo->right_fork]);
	status_routine(philo, get_current_time(),"died");
	philo->control->is_dead = TRUE;
	return (NULL);
}

static void	feed_philosopher(t_philo *philo)
{
	long	instant;

	instant = get_current_time();
	pthread_mutex_lock(&philo->control->forks[philo->left_fork]);
	pthread_mutex_lock(&philo->control->forks[philo->right_fork]);
	status_routine(philo, instant, "has taken a fork");
	status_routine(philo, instant, "has taken a fork");
	instant = get_current_time();
	philo->ms_last_meal = instant;
	status_routine(philo, instant, "is eating");
	usleep(philo->control->ms_to_eat * 1000);
	pthread_mutex_unlock(&philo->control->forks[philo->left_fork]);
	pthread_mutex_unlock(&philo->control->forks[philo->right_fork]);
}

static t_bool	simulation_not_over(t_philo *philo)
{
	if (!philo->control->is_dead && !philo->control->is_philos_full_up)
		return (TRUE);
	return (FALSE);
}

void	*philosophers_routine(void *p)
{
	t_philo	*philo;

	philo = p;
	if (philo->control->philosopher_number == 1)
		return (handle_one_philosopher(philo));
	if (philo->id % 2 == 0)
		usleep(2000);
	while (simulation_not_over(philo))
	{
		feed_philosopher(philo);
		status_routine(philo, get_current_time(), "is sleeping");
		usleep(philo->control->ms_to_sleep * 1000);
		status_routine(philo, get_current_time(), "is thinking");
		philo->current_meals_count++;
	}
	return (NULL);
}
