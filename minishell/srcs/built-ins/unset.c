/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 23:19:07 by romoreir          #+#    #+#             */
/*   Updated: 2022/01/14 09:53:40 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
/*
static t_bool	is_valid_unset(char *env)
{
	int		i;

	if (ft_strlen(env) < 1 || ft_isdigit(env[0]))
		return (FALSE);
	i = -1;
	while (env[++i])
		if (env[i] == '=')
			return (FALSE);
	return (TRUE);
}

static void	parse_new_env(t_shell *sh, char **tmp, char *arg)
{
	int		i;
	int		j;
	int		len;
	char	*env_key;

	len = sh->count.envs;
	i = -1;
	j = -1;
	while (++i < len)
	{
		env_key = get_env_key(tmp[i]);
		if (ft_strncmp(arg, env_key, ft_strlen(arg) + 1))
		{
			sh->envs[++j] = (char *)malloc(sizeof(char)
					* ft_strlen(tmp[i]) + 1);
			ft_strlcpy(sh->envs[j], tmp[i], ft_strlen(tmp[i]) + 1);
		}
		else
			sh->count.envs--;
		free(env_key);
	}
}

static void	remove_env(t_shell *sh, char *arg)
{
	int		i;
	char	*tmp[MAX_ENVS];
	int		len;

	len = sh->count.envs;
	i = -1;
	while (++i < len)
	{
		tmp[i] = (char *)malloc(sizeof(char) * ft_strlen(sh->envs[i]) + 1);
		ft_strlcpy(tmp[i], sh->envs[i], ft_strlen(sh->envs[i]) + 1);
	}
	tmp[i + 1] = NULL;
	i = -1;
	while (++i < len)
		free(sh->envs[i]);
	parse_new_env(sh, tmp, arg);
	i = -1;
	while (++i < len)
		free(tmp[i]);
}

t_status	ft_unset(t_shell *sh, int num)
{
	char	*env;
	int		i;

	if (ft_strlen(sh->cmds[num].args[1]) == 0)
		return (SUCCESS);
	i = 0;
	while (++i < sh->cmds[num].args_count)
	{
		env = sh->cmds[num].args[i];
		if (is_valid_unset(env))
			remove_env(sh, env);
		else
			printf("%s%s%s", ERROR_UNSET_START, env, ERROR_UNSET_END);
	}
	return (SUCCESS);
}
*/
