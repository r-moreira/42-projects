/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 23:23:35 by romoreir          #+#    #+#             */
/*   Updated: 2022/01/10 22:02:14 by romoreir         ###   ########.fr       */
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

static void	setup_paths(t_shell *sh)
{
	char	*path_env;
	char	**split;
	int		i;

	i = -1;
	path_env = getenv("PATH");
	if (path_env == NULL)
		return ;
	split = ft_split(path_env, ':');
	while (split[++i])
	{
		sh->paths[i] = (char *)malloc(sizeof(char) * ft_strlen(split[i]) + 1);
		ft_strlcpy(sh->paths[i], split[i], ft_strlen(split[i]) + 1);
	}
	sh->count.paths = i;
	sh->paths[i + 1] = NULL;
	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
}

void	init_shell(t_shell *sh, char **envp)
{
	setup_envs(sh, envp);
	setup_paths(sh);
}