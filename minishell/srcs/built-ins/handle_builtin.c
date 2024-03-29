/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 00:21:28 by romoreir          #+#    #+#             */
/*   Updated: 2022/02/19 20:47:33 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	exec_builtin(t_shell *sh, int num)
{
	call_builtin(sh, num);
	exit(EXIT_SUCCESS);
}

t_bool	has_non_fork_builtins(t_shell *sh, int num)
{
	int		len;

	len = ft_strlen(sh->cmds[num].name) + 1;
	if (ft_strncmp(sh->cmds[num].name, "cd", len) == 0)
		return (TRUE);
	else if (ft_strncmp(sh->cmds[num].name, "export", len) == 0)
	{
		if (!sh->cmds[num].args[1] || !ft_strlen(sh->cmds[num].args[1]))
			return (FALSE);
		return (TRUE);
	}
	else if (ft_strncmp(sh->cmds[num].name, "unset", len) == 0)
		return (TRUE);
	else if ((ft_strncmp(sh->cmds[num].name, "exit", len) == 0))
		return (TRUE);
	return (FALSE);
}

t_bool	is_builtin(t_shell *sh, int num)
{
	size_t		len;
	t_bool		is_builtin;

	is_builtin = FALSE;
	len = ft_strlen(sh->cmds[num].name) + 1;
	if (ft_strncmp(sh->cmds[num].name, "echo", len) == 0)
		is_builtin = TRUE;
	else if (ft_strncmp(sh->cmds[num].name, "cd", len) == 0)
		is_builtin = TRUE;
	else if (ft_strncmp(sh->cmds[num].name, "pwd", len) == 0)
		is_builtin = TRUE;
	else if (ft_strncmp(sh->cmds[num].name, "export", len) == 0)
		is_builtin = TRUE;
	else if (ft_strncmp(sh->cmds[num].name, "unset", len) == 0)
		is_builtin = TRUE;
	else if (ft_strncmp(sh->cmds[num].name, "env", len) == 0)
		is_builtin = TRUE;
	else if (ft_strncmp(sh->cmds[num].name, "exit", len) == 0)
		is_builtin = TRUE;
	if (is_builtin)
	{
		sh->cmds[num].exec.builtin = TRUE;
		return (TRUE);
	}
	return (FALSE);
}

t_status	call_builtin(t_shell *sh, int num)
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
