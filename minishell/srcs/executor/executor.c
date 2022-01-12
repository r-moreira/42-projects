/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 13:52:00 by romoreir          #+#    #+#             */
/*   Updated: 2022/01/12 11:55:32 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	executor_debug_helper(t_shell *sh)
{
	parsed_info_logger(sh);
	printf("\n========= Execution ==========");
}

static void	clear_execution(t_shell *sh)
{
	int	i;
	int	j;

	i = -1;
	while (++i < sh->count.cmds)
	{
		j = -1;
		while (++j < sh->cmds[i].args_count)
			free(sh->cmds[i].args[j]);
		sh->cmds[i].args_count = 0;
		sh->cmds[i].flag = NONE;
		ft_strlcpy(sh->cmds[i].name, "\0", 1);
		ft_strlcpy(sh->cmds[i].path, "\0", 1);
	}
}

static t_status	handle_builtin(t_shell *sh, int num)
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

static void	call_exec(t_shell *sh, int num)
{
	sh->last_flag = NONE;

	if (num > 0)
		sh->last_flag = sh->cmds[num - 1].flag;

	if (sh->cmds[num].flag == PIPE && sh->last_flag == NONE && sh->fd.open == ANY)
		exec_pipe_write_fd1(sh, num);
	else if (sh->cmds[num].flag == PIPE && sh->last_flag == PIPE && sh->fd.open == IN)
		exec_pipe_read_fd1_write_fd2(sh, num);
	else if (sh->cmds[num].flag == PIPE && sh->last_flag == PIPE && sh->fd.open == OUT)
		exec_pipe_read_fd2_write_fd1(sh, num);
	else if (sh->cmds[num].flag != PIPE && sh->last_flag == PIPE && sh->fd.open == IN)
		exec_pipe_read_fd1(sh, num);
	else if (sh->cmds[num].flag != PIPE && sh->last_flag == PIPE && sh->fd.open == OUT)
		exec_pipe_read_fd2(sh, num);
	else
		exec_noflag(sh, num);
}

//////////////////TO-DOs
// Lidar com as flags (Process Handlers, Pipe, Dup2 e afins..) Built-ins e Não Built-ins
// Lidar com signals
// Garantir o retorno do PID para: "$?"
/////////////////////////
void	executor(t_shell *sh)
{
	int	i;

	sh->fd.open = ANY;
	if (DEBUGGER_EXEC)
		executor_debug_helper(sh);
	i = -1;
	while (++i < sh->count.cmds)
		if (handle_builtin(sh, i) == NOT_BUILT_IN)
			if (get_cmd_path(sh, i) == SUCCESS)
				call_exec(sh, i);
	clear_execution(sh);
}
