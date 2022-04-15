/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 19:19:24 by romoreir          #+#    #+#             */
/*   Updated: 2022/04/15 15:34:58 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

# define ERR_INVALID_ARGS "Error: Invalid number os arguments"
# define ERR_PHIL_NUM "Error: Number of philosopher must be greather than zero"
# define ERR_ONLY_DIGITS_ARGS "Error: Arguments must be only digits"

typedef struct s_control	t_control;
typedef struct s_philo		t_philo;

typedef enum e_bool
{
	FALSE,
	TRUE,
}	t_bool;

struct s_philo
{
	int				id;
	int				left_fork;
	int				right_fork;
	long 			ms_last_meal;
	int				current_meals_count;
	pthread_t		thread;
	t_control		*control;
};

struct s_control
{
	long 			ms_start_meal;
	int				ms_to_die;
	int				ms_to_eat;
	int				ms_to_sleep;
	int				required_meals;
	int				required_meals_count;
	int				philosopher_number;
	t_bool			is_dead;
	t_bool			is_philos_full_up;
	t_philo			*philo;
	pthread_t		monitor;
	pthread_mutex_t	*forks;
	pthread_mutex_t	out;
};

void 		setup(t_control *control, int argc, char **argv);
t_bool		is_args_valid(int argc, char **argv);
void		*monitor_routine(void *param);
void		*philosophers_routine(void *param);
void		status_routine(t_philo *philo, long instant, char *status);
long int	get_current_time(void);
int			ft_isdigit(int c);
int			ft_atoi(const char *nptr);

#endif
