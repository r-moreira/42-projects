/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 13:52:00 by romoreir          #+#    #+#             */
/*   Updated: 2022/01/09 17:17:26 by romoreir         ###   ########.fr       */
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

void	executor(t_shell *sh)
{
	if (handle_builtin(sh, 0) == NOT_BUILT_IN)
		printf("Calling non built-in bin...\n");
	clean_cmd_struct(sh);
}
