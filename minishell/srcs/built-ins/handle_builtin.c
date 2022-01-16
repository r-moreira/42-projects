/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_builtis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 00:21:28 by romoreir          #+#    #+#             */
/*   Updated: 2022/01/16 00:21:58 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_status	handle_builtin(t_shell *sh, int num)
{
	size_t		len;
	char		*cmd;

	cmd = sh->cmds[num].name;
	len = ft_strlen(cmd) + 1;
	if (ft_strncmp(cmd, "echo", len) == 0)
		return (ft_echo(sh, num));
	else if (ft_strncmp(cmd, "cd", len) == 0)
		return (ft_cd(sh, num));
	else if (ft_strncmp(cmd, "pwd", len) == 0)
		return (ft_pwd(sh, num));
	else if (ft_strncmp(cmd, "export", len) == 0)
		return (ft_export(sh, num));
	else if (ft_strncmp(cmd, "unset", len) == 0)
		return (ft_unset(sh, num));
	else if (ft_strncmp(cmd, "env", len) == 0)
		return (ft_env(sh));
	else if (ft_strncmp(cmd, "exit", len) == 0)
		ft_exit(sh);
	return (NOT_BUILT_IN);
}
