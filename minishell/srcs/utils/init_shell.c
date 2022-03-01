/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 23:23:35 by romoreir          #+#    #+#             */
/*   Updated: 2022/02/28 22:58:09 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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
	setup_envs(sh, envp);
}
