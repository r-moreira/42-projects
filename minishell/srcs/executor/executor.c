/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 13:52:00 by romoreir          #+#    #+#             */
/*   Updated: 2022/01/10 22:25:02 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

//////////////////TO-DOs
//Verificar se é um comando built-in ou do SO
//Se for um built-in
//	criar funções para os comandos built-in e chama-los (sugestão, ptr functions - execve)
//Caso contrário
//	Procurar o comando em todos os diretórios da variável de ambiente PATH e execua-los (execve)
//	Se encontrar, executar. Caso contrário, printar que o comando não existe
// Lidar com as flags (Process Handlers, Pipe, Dup2 e afins..)
/////////////////////////
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

static void	exec_bin(t_shell *sh, int num)
{
	int		status;
	pid_t	pid;

	if (DEBUGGER_EXEC)
		parsed_info_logger(sh);
	pid = fork();
	if (pid == 0)
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
		wait(&status);
}

void	executor(t_shell *sh)
{
	int	num;

	num = 0;
	if (handle_builtin(sh, num) == NOT_BUILT_IN)
		if (get_cmd_path(sh, num) == SUCCESS)
			exec_bin(sh, num);
	clear_execution(sh);
}
