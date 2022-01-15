/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 23:17:30 by romoreir          #+#    #+#             */
/*   Updated: 2022/01/15 16:07:44 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_status	ft_cd(t_shell *sh, int num)
{
	char	*arg;
	char	*home;

	arg = sh->cmds[num].args[1];
	home = getenv("HOME");
	if (ft_strlen(arg) != 0)
		g_pid_number = chdir(arg);
	else
	{
		if (home != NULL)
			g_pid_number = chdir(home);
		else
			printf("ERROR_HOME");
	}
	if (g_pid_number == -1)
	{
		printf("minishell: cd: %s: %s", arg, ERROR_DIR);
		return (ERROR);
	}
	return (SUCCESS);
}
