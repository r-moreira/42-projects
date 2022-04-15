/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 22:35:50 by romoreir          #+#    #+#             */
/*   Updated: 2022/04/15 15:36:51 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

static t_bool is_philo_dead(t_control *control, int philo_id)
{
	int		ms_without_eating;
	int		ms_last_meal;
	long	instant;

	instant = get_current_time();
	ms_last_meal = control->philo[philo_id].ms_last_meal;
	ms_without_eating = instant - ms_last_meal;
	if (ms_without_eating > control->ms_to_die)
	{
		status_routine(control->philo, instant, "died");
		control->is_dead = TRUE;
		return (TRUE);
	}
	return (FALSE);
}

static t_bool is_all_philosophers_full_up(t_control *control)
{
	if (control->required_meals_count == control->philosopher_number)
	{
		control->is_philos_full_up = TRUE;
		return (TRUE);
	}
	return (FALSE);
}

static t_bool is_philosopher_full_up(t_control *control, int philo_id)
{
	if (control->philo[philo_id].current_meals_count == control->required_meals
		&& control->required_meals != -1)
		return (TRUE);
	return (FALSE);
}

void	*monitor_routine(void *c)
{
	int			i;
	t_control	*control;

	control = c;
	i = -1;
	while (++i < control->philosopher_number)
	{
		if (is_philo_dead(control, i) || is_all_philosophers_full_up(control))
			return (NULL);
		if (is_philosopher_full_up(control, i))
			control->required_meals_count++;
		if (i + 1 == control->philosopher_number)
			i = -1;
		usleep(2000);
	}
	return (NULL);
}
