/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 13:52:00 by romoreir          #+#    #+#             */
/*   Updated: 2022/01/05 23:08:49 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
#include <stddef.h>

//////////////////TO-DOs
//Verificar se é um comando built-in ou do SO
//Se for um built-in
//	criar funções para os comandos built-in e chama-los (sugestão, ptr functions - execve)
//Caso contrário
//	Procurar o comando em todos os diretórios da variável de ambiente PATH e execua-los (execve)
//	Se encontrar, executar. Caso contrário, printar que o comando não existe
// Lidar com as flags (Process Handlers, Pipe, Dup2 e afins..)
/////////////////////////


static void	handle_builtin(t_shell *sh)
{
	size_t	len;
	char	*cmd;

	cmd	= sh->cmds[0].name;
	len = ft_strlen(cmd) + 1;
	if (ft_strncmp(cmd, "echo", len) == 0)
		echo(sh);
	else if (ft_strncmp(cmd, "cd", len) == 0)
		printf("Calling cd\n");
	else if (ft_strncmp(cmd, "pwd", len) == 0)
		printf("Calling pwd\n");
	else if (ft_strncmp(cmd, "export", len) == 0)
		printf("Calling export\n");
	else if (ft_strncmp(cmd, "unset", len) == 0)
		printf("Calling unset\n");
	else if (ft_strncmp(cmd, "env", len) == 0)
		printf("Calling env\n");
	else if (ft_strncmp(cmd, "exit", len) == 0)
		printf("Calling exit\n");
	else
		printf("Calling non built in bin...\n");
}

void	executor(t_shell *sh)
{
	handle_builtin(sh);
}
