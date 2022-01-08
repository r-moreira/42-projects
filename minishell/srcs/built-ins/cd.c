/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 23:17:30 by romoreir          #+#    #+#             */
/*   Updated: 2022/01/08 00:05:27 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_status	ft_cd(t_shell *sh, int cmd_num)
{
	char	*arg;
	char	*home;

	arg = sh->cmds[cmd_num].args[1];
	home = getenv("HOME");
	if (ft_strlen(arg) != 0)
		g_pid_number = chdir(arg);
	else
	{
		if (home != NULL)
			g_pid_number = chdir(home);
		else
			printf("minishell: cd: There is no HOME environment variable");
	}
	if (g_pid_number == -1)
	{
		printf("minishell: cd: %s: %s", arg, ERROR_DIR);
		return (ERROR);
	}
	return (SUCCESS);
}
