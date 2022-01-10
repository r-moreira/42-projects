/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 13:52:00 by romoreir          #+#    #+#             */
/*   Updated: 2022/01/10 16:42:22 by romoreir         ###   ########.fr       */
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

static void	clean_cmd_struct(t_shell *sh)
{
	int	i;
	int	j;

	i = -1;
	while (++i < sh->count.cmds)
	{
		ft_strlcpy(sh->cmds[i].name, "\0", 1);
		j = -1;
		while (++j < sh->cmds[i].args_count)
			ft_strlcpy(sh->cmds[i].args[j], "\0", 1);
		sh->cmds[i].args_count = 0;
		sh->cmds[i].flag = NONE;
		ft_strlcpy(sh->cmds[i].path, "\0", 1);
	}
}

static t_status	handle_builtin(t_shell *sh, int cmd_num)
{
	size_t		len;
	char		*cmd;

	cmd = sh->cmds[cmd_num].name;
	len = ft_strlen(cmd) + 1;
	if (ft_strncmp(cmd, "echo", len) == 0)
		return (ft_echo(sh, cmd_num));
	else if (ft_strncmp(cmd, "cd", len) == 0)
		return (ft_cd(sh, cmd_num));
	else if (ft_strncmp(cmd, "pwd", len) == 0)
		return (ft_pwd(sh, cmd_num));
	else if (ft_strncmp(cmd, "export", len) == 0)
		return (ft_export(sh, cmd_num));
	else if (ft_strncmp(cmd, "unset", len) == 0)
		return (ft_unset(sh, cmd_num));
	else if (ft_strncmp(cmd, "env", len) == 0)
		return (ft_env(sh));
	else if (ft_strncmp(cmd, "exit", len) == 0)
		ft_exit(sh);
	return (NOT_BUILT_IN);
}

//TO-DO trasnformar args em *args[MAX_ARGS_NUM]
static int	exec_bin(t_shell *sh, int cmd_num)
{
	int		status;
	int		errcode;
	pid_t	pid;
	char	*tmp_args[] = {sh->cmds[cmd_num].name, NULL};

	if (DEBUGGER)
		printf("Calling non built-in bin, with path: |%s|\n",
			sh->cmds[cmd_num].path);
	errcode = 0;
	pid = fork();
	if (!pid)
	{
		if (execve(sh->cmds[0].path, tmp_args, sh->envs) == -1)
		{
			perror(ERROR_EXEC);
			exit(errcode);
		}
		else
			exit(errcode);
	}
	else
		wait(&status);
	errcode = 0;
	return (errcode);
}

void	executor(t_shell *sh)
{
	int	cmd_num;

	cmd_num = 0;
	if (handle_builtin(sh, cmd_num) == NOT_BUILT_IN)
		if (get_cmd_path(sh, cmd_num) == SUCCESS)
			exec_bin(sh, cmd_num);
	clean_cmd_struct(sh);
}
