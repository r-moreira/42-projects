/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 00:20:00 by romoreir          #+#    #+#             */
/*   Updated: 2022/04/15 15:56:41 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

void	status_routine(t_philo *philo, long instant, char *status)
{
	pthread_mutex_lock(&philo->control->out);
	if (!philo->control->is_dead)
		printf("%ld %d %s\n", instant - philo->control->ms_start_meal,
			philo->id, status);
	pthread_mutex_unlock(&philo->control->out);
}
