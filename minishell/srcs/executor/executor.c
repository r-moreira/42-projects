/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 13:52:00 by romoreir          #+#    #+#             */
/*   Updated: 2022/02/20 21:51:20 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	define_exec_params(t_shell *sh, int num)
{
	//t_bool pipe_lastcmd;
	(void)sh;
	(void)num;
}

/////////////////////// TO-DO
// Definir parâmetros para cada execução
// Adicionar tratamentos de I/O para a função exec_cmd
// Começar com todas as possibilidades de redirects
// Adicionar pipes
// Adicionar pipes + redirects
//////////////////////////////
void	executor(t_shell *sh)
{
	int	i;

	g_pid_number = 0;
	if (DEBUGGER_EXEC)
		executor_debugger_helper(sh);
	i = -1;
	while (++i < sh->count.cmds)
	{
		sh->cmds[i].exec.builtin = FALSE;
		if (is_builtin(sh, i) == FALSE)
			get_cmd_path(sh, i);
		define_exec_params(sh, i);
		exec_cmd(sh, i);
		setup_fd_info(sh);
	}
}
