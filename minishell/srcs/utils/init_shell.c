/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir <coder@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 23:23:35 by romoreir          #+#    #+#             */
/*   Updated: 2022/03/16 02:09:34 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	setup_not_workspace_envs(t_shell *sh, char **envp)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (envp[++i])
	{
		if (ft_strnstr(envp[i], "_WORKSPACE_", strlen(envp[i])) == NULL)
		{
			sh->envs[j] = (char *)malloc(sizeof(char) * ft_strlen(envp[i]) + 1);
			ft_strlcpy(sh->envs[j], envp[i], ft_strlen(envp[i]) + 1);
			j++;
		}
	}
	sh->count.envs = j;
	sh->envs[j] = NULL;
}

static void	setup_envs(t_shell *sh, char **envp)
{
	int	i;

	i = -1;
	while (envp[++i])
	{
		sh->envs[i] = (char *)malloc(sizeof(char) * ft_strlen(envp[i]) + 1);
		ft_strlcpy(sh->envs[i], envp[i], ft_strlen(envp[i]) + 1);
	}
	sh->count.envs = i;
	sh->envs[i] = NULL;
}

void	init_shell(t_shell *sh, char **envp)
{
	g_pid_number = 0;
	sh->count.cmds = 0;
	sh->count.envs = 0;
	sh->count.paths = 0;
	if (IGNORE_WORKSPACE_ENVS)
		setup_not_workspace_envs(sh, envp);
	else
		setup_envs(sh, envp);
}
