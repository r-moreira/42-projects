/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 23:18:50 by romoreir          #+#    #+#             */
/*   Updated: 2022/01/17 09:43:22 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	export_env(t_shell *sh, char *env)
{
	char	*env_key;
	int		i;
	int		env_len;

	env_len = ft_strlen(env);
	env_key = get_env_key(env);
	i = -1;
	while (++i < sh->count.envs)
	{
		if (ft_strncmp(sh->envs[i], env, ft_strlen(env_key) + 1) == 0)
		{
			free(sh->envs[i]);
			sh->envs[i] = (char *)malloc(sizeof(char) * env_len + 1);
			ft_strlcpy(sh->envs[i], env, env_len + 1);
			free(env_key);
			return ;
		}
	}
	sh->envs[sh->count.envs] = (char *)malloc(sizeof(char) * env_len + 1);
	ft_strlcpy(sh->envs[sh->count.envs], env, env_len + 1);
	sh->count.envs++;
	sh->envs[sh->count.envs] = NULL;
	free(env_key);
}

static t_status	export_with_no_arg(t_shell *sh, int num)
{
	int	i;

	(void)num;
	i = -1;
	while (++i < sh->count.envs)
		printf("declare -x %s\n", sh->envs[i]);
	return (SUCCESS);
}

t_status	ft_export(t_shell *sh, int num)
{
	char	*env;
	char	*arg;
	int		i;
	int		len;

	arg = sh->cmds[num].args[1];
	if (arg)
		len = ft_strlen(arg);
	if (!arg || len == 0)
		return (export_with_no_arg(sh, num));
	i = 0;
	while (++i < sh->cmds[num].args_count)
	{
		env = sh->cmds[num].args[i];
		if (is_env_valid(env))
		{
			env = parse_env(env);
			export_env(sh, env);
			free(env);
		}
		else
			printf("%s%s%s", ERROR_EXPT_START, env, ERROR_EXPT_END);
	}
	return (SUCCESS);
}
