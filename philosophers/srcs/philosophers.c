/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 19:46:12 by rarodrig          #+#    #+#             */
/*   Updated: 2022/04/15 16:47:34 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	main(int argc, char **argv)
{
	t_control	control;
	int			i;

	if (!is_args_valid(argc, argv))
		return (EXIT_FAILURE);
	setup(&control, argc, argv);
	pthread_mutex_init(&control.out, NULL);
	i = -1;
	while (++i < control.philosopher_number)
		pthread_create(&control.philo[i].thread, NULL,
			&philosophers_routine, &control.philo[i]);
	pthread_create(&control.monitor, NULL, &monitor_routine, &control);
	i = -1;
	while (++i < control.philosopher_number)
		pthread_join(control.philo[i].thread, NULL);
	pthread_join(control.monitor, NULL);
	free(control.philo);
	free(control.forks);
	return (EXIT_SUCCESS);
}
