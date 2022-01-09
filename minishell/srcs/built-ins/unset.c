/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 23:19:07 by romoreir          #+#    #+#             */
/*   Updated: 2022/01/09 17:21:14 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_bool	is_valid_unset(char *env)
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

void	remove_env(t_shell *sh, char *env)
{
	(void)sh;
	(void)env;
}

t_status	ft_unset(t_shell *sh, int cmd_num)
{
	char	*env;
	int		i;

	if (ft_strlen(sh->cmds[cmd_num].args[1]) == 0)
		return (SUCCESS);
	i = 0;
	while (++i < sh->cmds[cmd_num].args_count)
	{
		env = sh->cmds[cmd_num].args[i];
		if (is_valid_unset(env))
			remove_env(sh, env);
		else
			printf("%s%s%s", ERROR_UNSET_START, env, ERROR_UNSET_END);
	}
	return (SUCCESS);
}
