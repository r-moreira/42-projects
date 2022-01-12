/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 13:52:00 by romoreir          #+#    #+#             */
/*   Updated: 2022/01/11 22:01:01 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include <unistd.h>

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

	if (DEBUGGER_BUILTIN)
		parsed_info_logger(sh);
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

static void	exec_noflag(t_shell *sh, int num)
{
	int		status;
	pid_t	pid;

	pid = fork();
	if (pid == FORKED_CHILD)
	{
		if (execve(sh->cmds[num].path, sh->cmds[num].args, sh->envs) == -1)
		{
			perror(ERROR_EXEC);
			exit(errno);
		}
		else
			exit(EXIT_SUCCESS);
	}
	else
		g_pid_number = wait(&status);
}

static void	exec_pipe_write_in(t_shell *sh, int num)
{
	pid_t	pid;

	printf("\nCalling pipe write in\n");
	sh->fd.open = IN;

	if (pipe(sh->fd.in) == -1)  {
		return ;
	}

	pid = fork();
	if (pid == -1)
		return ;

	if (pid == FORKED_CHILD)
	{
		dup2(sh->fd.in[WRITE_END], STDOUT_FILENO);
		close(sh->fd.in[READ_END]);
		close(sh->fd.in[WRITE_END]);
		if (execve(sh->cmds[num].path, sh->cmds[num].args, sh->envs) == -1)
		{
			perror(ERROR_EXEC);
			exit(errno);
		}
		else
			exit(EXIT_SUCCESS);
	}
	else
		g_pid_number = waitpid(pid, NULL, 0);
}

static void	exec_pipe_read_in(t_shell *sh, int num)
{
	pid_t	pid;

	if (DEBUGGER_EXEC)
		parsed_info_logger(sh);
	printf("\nCalling pipe read in\n");
	sh->fd.open = ANY;

	pid = fork();
	if (pid == -1)
		return ;

	if (pid == FORKED_CHILD)
	{
		dup2(sh->fd.in[READ_END], STDIN_FILENO);
		close(sh->fd.in[READ_END]);
		close(sh->fd.in[WRITE_END]);
		if (execve(sh->cmds[num].path, sh->cmds[num].args, sh->envs) == -1)
		{
			perror(ERROR_EXEC);
			exit(errno);
		}
		else
			exit(EXIT_SUCCESS);
	}
	else
	{
		close(sh->fd.in[READ_END]);
		close(sh->fd.in[WRITE_END]);
		g_pid_number = waitpid(pid, NULL, 0);
	}
}

static void	exec_pipe_read_out(t_shell *sh, int num)
{
	pid_t	pid;

	if (DEBUGGER_EXEC)
		parsed_info_logger(sh);
	printf("\nCalling pipe read out\n");
	sh->fd.open = ANY;

	pid = fork();
	if (pid == -1)
		return ;

	if (pid == FORKED_CHILD)
	{
		dup2(sh->fd.out[READ_END], STDIN_FILENO);
		close(sh->fd.out[READ_END]);
		close(sh->fd.out[WRITE_END]);
		if (execve(sh->cmds[num].path, sh->cmds[num].args, sh->envs) == -1)
		{
			perror(ERROR_EXEC);
			exit(errno);
		}
		else
			exit(EXIT_SUCCESS);
	}
	else
	{
		close(sh->fd.out[READ_END]);
		close(sh->fd.out[WRITE_END]);
		g_pid_number = waitpid(pid, NULL, 0);
	}
}

static void	exec_pipe_read_in_write_out(t_shell *sh, int num)
{
	pid_t	pid;

	if (DEBUGGER_EXEC)
		parsed_info_logger(sh);
	printf("\nCalling pipe read in write out\n");
	sh->fd.open = OUT;

	if (pipe(sh->fd.out) == -1)  {
		return ;
	}

	pid = fork();
	if (pid == -1)
		return ;

	if (pid == FORKED_CHILD)
	{
		dup2(sh->fd.in[READ_END], STDIN_FILENO);
		close(sh->fd.in[READ_END]);
		close(sh->fd.in[WRITE_END]);
		dup2(sh->fd.out[WRITE_END], STDOUT_FILENO);
		close(sh->fd.out[READ_END]);
		close(sh->fd.out[WRITE_END]);
		if (execve(sh->cmds[num].path, sh->cmds[num].args, sh->envs) == -1)
		{
			perror(ERROR_EXEC);
			exit(errno);
		}
		else
			exit(EXIT_SUCCESS);
	}
	else
	{
		close(sh->fd.in[READ_END]);
		close(sh->fd.in[WRITE_END]);
		g_pid_number = waitpid(pid, NULL, 0);
	}
}

static void	exec_pipe_read_out_write_in(t_shell *sh, int num)
{
	pid_t	pid;

	if (DEBUGGER_EXEC)
		parsed_info_logger(sh);
	printf("\nCalling pipe read out write in\n");
	sh->fd.open = IN;

	if (pipe(sh->fd.in) == -1)  {
		return ;
	}

	pid = fork();
	if (pid == -1)
		return ;

	if (pid == FORKED_CHILD)
	{
		dup2(sh->fd.out[READ_END], STDIN_FILENO);
		close(sh->fd.out[READ_END]);
		close(sh->fd.out[WRITE_END]);
		dup2(sh->fd.in[WRITE_END], STDOUT_FILENO);
		close(sh->fd.in[READ_END]);
		close(sh->fd.in[WRITE_END]);
		if (execve(sh->cmds[num].path, sh->cmds[num].args, sh->envs) == -1)
		{
			perror(ERROR_EXEC);
			exit(errno);
		}
		else
			exit(EXIT_SUCCESS);
	}
	else
	{
		close(sh->fd.out[READ_END]);
		close(sh->fd.out[WRITE_END]);
		g_pid_number = waitpid(pid, NULL, 0);
	}
}

static void	eval_cmd(t_shell *sh, int num)
{
	sh->last_flag = NONE;


	if (num > 0)
		sh->last_flag = sh->cmds[num - 1].flag;

	if (sh->cmds[num].flag == PIPE && sh->last_flag == NONE && sh->fd.open == ANY)
		exec_pipe_write_in(sh, num);
	else if (sh->cmds[num].flag == PIPE && sh->last_flag == PIPE && sh->fd.open == IN)
		exec_pipe_read_in_write_out(sh, num);
	else if (sh->cmds[num].flag == PIPE && sh->last_flag == PIPE && sh->fd.open == OUT)
		exec_pipe_read_out_write_in(sh, num);
	else if (sh->cmds[num].flag != PIPE && sh->last_flag == PIPE && sh->fd.open == IN)
		exec_pipe_read_in(sh, num);
	else if (sh->cmds[num].flag != PIPE && sh->last_flag == PIPE && sh->fd.open == OUT)
		exec_pipe_read_out(sh, num);
	else
		exec_noflag(sh, num);
}

//////////////////TO-DOs
// Lidar com as flags (Process Handlers, Pipe, Dup2 e afins..)
// Lidar com signals
// Garantir o retorno do PID para: "$?"
/////////////////////////
void	executor(t_shell *sh)
{
	int	i;

	sh->fd.open = ANY;
	i = -1;
	while (++i < sh->count.cmds)
	{
		if (handle_builtin(sh, i) == NOT_BUILT_IN)
		{
			if (get_cmd_path(sh, i) == SUCCESS)
			{
				if (DEBUGGER_EXEC)
					parsed_info_logger(sh);
				eval_cmd(sh, i);
			}
		}
	}
	clear_execution(sh);
}
