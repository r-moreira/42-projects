/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoreir < romoreir@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 11:43:06 by romoreir          #+#    #+#             */
/*   Updated: 2022/01/19 09:17:26 by romoreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

////////////////////TO-DOs
//
//  0) Fazer testes
//
//  1) Redirections/Pipe Fix
//		- Adicionar close nas pipes do parent
//		- Pipe + Redir out
//		- Redir in + Redir out
//		- Heredoc + Pipe (Não está pegando a flag pipe no flags parser)
//
// 2) Lidar com signals - Verificar comportamento CTRL + \
//
// 3) Ajustar o signal CTRL + C para o heredoc
//
/////////////////////////

int	main(int argc, char **argv, char **envp)
{
	t_shell	sh;

	(void)argc;
	(void)argv;
	init_shell(&sh, envp);
	run_signals_interactive();
	welcome_message();
	while (TRUE)
	{
		if (g_pid_number != SIGNALED)
			print_prompt();
		if (take_input(&sh) == SUCCESS)
			if (analyzer(&sh) == SUCCESS)
				if (parser(&sh) == SUCCESS)
					executor(&sh);
	}
	return (EXIT_SUCCESS);
}
