/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_aux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 20:15:55 by romoreir          #+#    #+#             */
/*   Updated: 2022/01/18 20:16:13 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	wait_aux(int pid)
{
	waitpid(pid, &g_pid_number, WUNTRACED);
	if (WIFEXITED(g_pid_number))
		g_pid_number = WEXITSTATUS(g_pid_number);
	else
	g_pid_number += 128;
}
