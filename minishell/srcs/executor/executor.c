/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 13:52:00 by romoreir          #+#    #+#             */
/*   Updated: 2022/01/15 21:20:57 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

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
		j = -1;
		while (++j < sh->cmds[i].redin.len)
			ft_strlcpy(sh->cmds[i].redin.arg[j], "\0", 1);
		j = -1;
		while (++j < sh->cmds[i].redout.len)
			ft_strlcpy(sh->cmds[i].redout.arg[j], "\0", 1);
		j = -1;
		while (++j < sh->cmds[i].redout_apd.len)
			ft_strlcpy(sh->cmds[i].redout_apd.arg[j], "\0", 1);
		sh->cmds[i].args_count = 0;
		ft_strlcpy(sh->cmds[i].name, "\0", 1);
		ft_strlcpy(sh->cmds[i].path, "\0", 1);
	}
	ft_strlcpy(sh->heredoc_file_buffer, "\0", 1);
	ft_strlcpy(sh->input_string, "\0", 1);
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

static void	handle_pipes(t_shell *sh, int num)
{
	t_bool	pipe_last_cmd;
	t_bool	pipe;

	pipe = sh->cmds[num].pipe;
	pipe_last_cmd = FALSE;
	if (num > 0)
		pipe_last_cmd = sh->cmds[num - 1].pipe;
	if (pipe && !pipe_last_cmd && sh->fd.open == ANY)
		exec_pipe_write_fd1(sh, num);
	else if (pipe && pipe_last_cmd && sh->fd.open == ONE)
		exec_pipe_read_fd1_write_fd2(sh, num);
	else if (pipe && pipe_last_cmd && sh->fd.open == TWO)
		exec_pipe_read_fd2_write_fd1(sh, num);
	else if (!pipe && pipe_last_cmd && sh->fd.open == ONE)
		exec_pipe_read_fd1(sh, num);
	else if (!pipe && pipe_last_cmd && sh->fd.open == TWO)
		exec_pipe_read_fd2(sh, num);
	else
		exec_no_pipe(sh, num);
}

static void	call_exec(t_shell *sh, int num)
{
	//handle_input_redir(sh, num);
	//handle_output_redir(sh, num);

	handle_pipes(sh, num);

}

//////////////////TO-DOs
// Lidar com as flags (Process Handlers, Pipe, Dup2 e afins..)
//		- Built-ins e Não Built-ins
// Adicionar log de execução nos built-ins
// Lidar com signals
// Garantir o retorno do PID para: "$?"
/////////////////////////
void	executor(t_shell *sh)
{
	int	i;

	sh->fd.open = ANY;
	if (DEBUGGER_EXEC)
		executor_debugger_helper(sh);
	i = -1;
	while (++i < sh->count.cmds)
		if (handle_builtin(sh, i) == NOT_BUILT_IN)
			if (get_cmd_path(sh, i) == SUCCESS)
				call_exec(sh, i);
	clear_execution(sh);
}
