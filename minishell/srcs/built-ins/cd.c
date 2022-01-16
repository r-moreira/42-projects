/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 23:17:30 by romoreir          #+#    #+#             */
/*   Updated: 2022/01/16 20:22:29 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_status	ft_cd(t_shell *sh, int num)
{
	char	*arg;
	char	*home;

	printf("FT_CD Called!!!\n");
	arg = "\0";
	if (sh->cmds[num].args[1] != NULL)
		arg = sh->cmds[num].args[1];
	if (ft_strlen(arg) != 0)
	{
		printf("ARGs Called!!!\n");
		g_pid_number = chdir(arg);
	}
	else
	{
		printf("no ARGs Called!!!\n");
		home = getenv("HOME");
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
