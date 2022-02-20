/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 23:06:23 by romoreir          #+#    #+#             */
/*   Updated: 2022/02/19 23:09:58 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

pid_t	handle_fork(void)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		exit_error(ERROR_FORK);
	return (pid);
}
